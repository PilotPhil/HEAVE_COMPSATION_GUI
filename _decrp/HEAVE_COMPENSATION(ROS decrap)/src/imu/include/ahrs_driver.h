#ifndef BASE_DRIVER_H_
#define BASE_DRIVER_H_

#include <ros/ros.h>
#include <serial/serial.h> //ROS的串口包 http://wjwwood.io/serial/doc/1.1.0/index.html
#include <math.h>
#include <fstream>
#include <fdilink_data_struct.h>
#include <boost/thread.hpp>
#include <string>
#include <ros/package.h>
#include <crc_table.h>
#include "imu/vel.h"

using namespace std;
namespace FDILink
{
#define FRAME_HEAD 0xfc
#define FRAME_END 0xfd
#define TYPE_BODY_VEL 0x60
#define BODY_VEL_LEN 0x0c //12

class ahrsBringup
{
public:
  ahrsBringup();
  ~ahrsBringup();
  void processLoop();
  bool checkCS8(int len);
  bool checkCS16(int len);
  ros::NodeHandle nh_;

private:

  //sum info
  int sn_lost_ = 0;
  int crc_error_ = 0;
  uint8_t read_sn_ = 0;
  bool frist_sn_;
  int device_type_ = 1;

  //serial
  serial::Serial serial_; //声明串口对象
  std::string serial_port_;
  std::string vel_topic_;
  int serial_baud_;
  int serial_timeout_;

  //data
  FDILink::body_vel_frame_read BODY_VEL_frame_;////////////////

  //Publisher
  ros::Publisher vel_topic;

}; //ahrsBringup
} // namespace FDILink
#endif
