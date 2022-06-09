#include "ahrs_driver.h"
#include <Eigen/Eigen>
namespace FDILink
{
  ahrsBringup::ahrsBringup() : frist_sn_(false), serial_timeout_(20)
  {
    ros::NodeHandle pravite_nh("~");
    
    pravite_nh.param("device_type", device_type_, 1); // default: single imu
    pravite_nh.param("pub_topic", vel_topic_, std::string("/vel"));
    pravite_nh.param("port", serial_port_, std::string("/dev/ttyTHS1")); /// dev/ttyTHS1
    pravite_nh.param("baud", serial_baud_, 115200);

    vel_topic=nh_.advertise<imu::vel>(vel_topic_,10);

    // setp up serial
    try
    {
      serial_.setPort(serial_port_);
      serial_.setBaudrate(serial_baud_);
      serial_.setFlowcontrol(serial::flowcontrol_none);
      serial_.setParity(serial::parity_none); // default is parity_none
      serial_.setStopbits(serial::stopbits_one);
      serial_.setBytesize(serial::eightbits);
      serial::Timeout time_out = serial::Timeout::simpleTimeout(serial_timeout_);
      serial_.setTimeout(time_out);
      serial_.open();
    }
    catch (serial::IOException &e)
    {
      ROS_ERROR_STREAM("Unable to open port ");
      exit(0);
    }
    if (serial_.isOpen())
    {
      ROS_INFO_STREAM("Serial Port initialized");
    }
    else
    {
      ROS_ERROR_STREAM("Unable to initial Serial port ");
      exit(0);
    }
    processLoop();
  }

  ahrsBringup::~ahrsBringup()
  {
    if (serial_.isOpen())
      serial_.close();
  }

  void ahrsBringup::processLoop()
  {
    ROS_INFO("ahrsBringup::processLoop: start");

    while (ros::ok())
    {
      // 0.检查串口是否已经打开
      if (!serial_.isOpen())
      {
        ROS_WARN("serial unopen");
      }

      // 1.起始标志校验 是否等于0xFC
      uint8_t check_head[1] = {0xff};
      size_t head_s = serial_.read(check_head, 1);
      if (check_head[0] != FRAME_HEAD)
      {
        ROS_WARN("FRAME_HEAD check error");
        continue;
      }

      // 2.检查指令类别
      uint8_t head_type[1] = {0xff};
      size_t type_s = serial_.read(head_type, 1);
      if (head_type[0] != TYPE_BODY_VEL)
      {
        ROS_WARN("head_type error: %02X", head_type[0]);
        continue;
      }

      // 3.检查数据长度
      uint8_t check_len[1] = {0xff};
      size_t len_s = serial_.read(check_len, 1);
      if (head_type[0] == TYPE_BODY_VEL && check_len[0] != BODY_VEL_LEN)
      {
        ROS_WARN("head_len error (BODY_VEL)");
        ROS_WARN("BODY_VEL_LEN RIGHT!");
        continue;
      }

      // 4.检查流水号，CRC8,CRC16
      uint8_t check_sn[1] = {0xff};
      size_t sn_s = serial_.read(check_sn, 1);

      uint8_t head_crc8[1] = {0xff};
      size_t crc8_s = serial_.read(head_crc8, 1);

      uint8_t head_crc16_H[1] = {0xff};
      uint8_t head_crc16_L[1] = {0xff};
      size_t crc16_H_s = serial_.read(head_crc16_H, 1);
      size_t crc16_L_s = serial_.read(head_crc16_L, 1);

      // CRC8校验
      if (head_type[0] == TYPE_BODY_VEL)
      {
        BODY_VEL_frame_.frame.header.header_start = check_head[0];
        BODY_VEL_frame_.frame.header.data_type = head_type[0];
        BODY_VEL_frame_.frame.header.data_size = check_len[0];
        BODY_VEL_frame_.frame.header.serial_num = check_sn[0];
        BODY_VEL_frame_.frame.header.header_crc8 = head_crc8[0];
        BODY_VEL_frame_.frame.header.header_crc16_h = head_crc16_H[0];
        BODY_VEL_frame_.frame.header.header_crc16_l = head_crc16_L[0];

        uint8_t CRC8 = CRC8_Table(BODY_VEL_frame_.read_buf.frame_header, 4);
        if (CRC8 != BODY_VEL_frame_.frame.header.header_crc8)
        {
          ROS_WARN("BODY_VEL header_crc8 error");
          continue;
        }
      }

      // CRC16校验+结束标志校验+速度解析
      if (head_type[0] == TYPE_BODY_VEL) ////////////////////////////////////////////////////////////////
      {
        uint16_t head_crc16_l = BODY_VEL_frame_.frame.header.header_crc16_l;
        uint16_t head_crc16_h = BODY_VEL_frame_.frame.header.header_crc16_h;
        uint16_t head_crc16 = head_crc16_l + (head_crc16_h << 8);
        size_t data_s = serial_.read(BODY_VEL_frame_.read_buf.read_msg, (BODY_VEL_LEN+1)); // 48+1

        // ROS_WARN("get body vel msg");
        // ROS_WARN(std::to_string(data_s).c_str());
        

        uint16_t CRC16 = CRC16_Table(BODY_VEL_frame_.frame.data.data_buff, BODY_VEL_LEN);

        if (head_crc16 != CRC16)
        {
          ROS_WARN("check crc16 faild(imu).");
          continue;
        }

        // 结束标志校验 是否等于0xFD
        else if (BODY_VEL_frame_.frame.frame_end != FRAME_END)
        {
          ROS_WARN(std::to_string(BODY_VEL_frame_.frame.frame_end).c_str());
          ROS_WARN("check frame end.");
          continue;
        }
      }

      // 解析得到速度
      if (head_type[0] == TYPE_BODY_VEL)
      {
        auto v_x = BODY_VEL_frame_.frame.data.data_pack.vel_x;
        auto v_y = BODY_VEL_frame_.frame.data.data_pack.vel_y;
        auto v_z = BODY_VEL_frame_.frame.data.data_pack.vel_z;
        
        // ROS_WARN(("v_x:"+std::to_string(v_x)).c_str());
        // ROS_WARN(("v_y:"+std::to_string(v_y)).c_str());
        // ROS_WARN(("v_z:"+std::to_string(v_z)).c_str());

        imu::vel vel;
        vel.vel_x=v_x;
        vel.vel_y=v_y;
        vel.vel_z=v_z;

        this->vel_topic.publish(vel);
      }
    }
  }

} // namespace FDILink

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ahrs_bringup");
  FDILink::ahrsBringup bp;

  return 0;
}
