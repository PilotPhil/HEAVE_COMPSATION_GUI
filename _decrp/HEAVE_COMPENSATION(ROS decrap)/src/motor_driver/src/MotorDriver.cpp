#include "MotorDriver.h"

MotorDriver::MotorDriver()
{
  std::string port;
  nh.param("port",port,std::string("/dev/ttyUSB0"));
  int baud;
  nh.param("baud",baud,115200);

    try {
    //设置串口属-性，并打开串口
    serial.setPort(port);
    serial.setBaudrate(baud);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    serial.setTimeout(to);
    serial.open();
  } catch (serial::IOException &e) {
    ROS_ERROR_STREAM("Unable to open port ");
    return;
  }

  std::string sub_control_output_topic;
  nh.param("sub_topic", sub_control_output_topic, std::string("/sub_topic"));
  sub = nh.subscribe<std_msgs::Float32>(sub_control_output_topic, 10,
                                        &MotorDriver::doActMotor, this);

}

MotorDriver::MotorDriver(std::string port, int baud)
{
  try {
    //设置串口属-性，并打开串口
    serial.setPort(port);
    serial.setBaudrate(baud);
    serial::Timeout to = serial::Timeout::simpleTimeout(1000);
    serial.setTimeout(to);
    serial.open();
  } catch (serial::IOException &e) {
    ROS_ERROR_STREAM("Unable to open port ");
    return;
  }

  std::string sub_control_output_topic;
  nh.param("sub_topic", sub_control_output_topic, std::string("/sub_topic"));
  sub = nh.subscribe<std_msgs::Float32>(sub_control_output_topic, 10,
                                        &MotorDriver::doActMotor, this);
}

MotorDriver::~MotorDriver() {}

bool MotorDriver::sendCommand(bytes cmd) {
  if (serial.isOpen() == false)
    return false;

  serial.write(cmd);
  return true;
}

bool MotorDriver::motoStop() {
  auto cmd = proptocol.motoStop();
  return sendCommand(cmd);
}

bool MotorDriver::motoRestore() {
  auto cmd = proptocol.motoRestore();
  return sendCommand(cmd);
}

bool MotorDriver::motoOff() {
  auto cmd = proptocol.motoOff();
  return sendCommand(cmd);
}

bool MotorDriver::speedControlClosedLoop(int speed) {
  auto cmd = proptocol.speedControlClosedLoop(speed);
  return sendCommand(cmd);
}

bool MotorDriver::multiLapAngleCloseLoopControl1(int degree) {
  auto cmd = proptocol.multiLapAngleCloseLoopControl1(degree);
  return sendCommand(cmd);
}

void MotorDriver::doActMotor(const std_msgs::Float32::ConstPtr &cmd) {
  auto u = cmd->data;

  speedControlClosedLoop(u);
}