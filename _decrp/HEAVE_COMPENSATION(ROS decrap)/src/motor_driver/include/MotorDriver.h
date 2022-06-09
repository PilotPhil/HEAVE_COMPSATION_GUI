#ifndef MOTODRIVER_H
#define MOTORDRIVER_H

#include "MotorProtocolRS485.h"
#include <iostream>
#include <ros/ros.h>
#include <serial/serial.h>
#include <std_msgs/Float32.h>
#include <std_msgs/String.h>

class MotorDriver {
private:
  /**
   * @brief 串口对象
   *
   */
  serial::Serial serial;

  /**
   * @brief 通讯协议对象
   *
   */
  MotorProtocolRS485 proptocol;

  /**
   * @brief 发送命令
   *
   * @param cmd
   * @return true
   * @return false
   */
  bool sendCommand(bytes cmd);

  ros::NodeHandle nh;

  ros::Subscriber sub;

public:
  /**
   * @brief Construct a new Motor Driver object
   *
   */
  MotorDriver();

  /**
   * @brief Construct a new Motor Driver object ctor
   *
   */
  MotorDriver(std::string port, int baud);

  /**
   * @brief Destroy the Motor Driver object dtor
   *
   */
  ~MotorDriver();

  /**
   * @brief 点击停止
   *
   * @return true
   * @return false
   */
  bool motoStop();

  /**
   * @brief 点击运行（恢复之前的控制方式）
   *
   * @return true
   * @return false
   */
  bool motoRestore();

  /**
   * @brief 电机关闭
   *
   * @return true
   * @return false
   */
  bool motoOff();

  /**
   * @brief 闭环速度控制
   *
   * @param speed
   * @return true
   * @return false
   */
  bool speedControlClosedLoop(int speed);

  /**
   * @brief 多圈角度闭环控制
   *
   * @param degree
   * @return true
   * @return false
   */
  bool multiLapAngleCloseLoopControl1(int degree);

  /**
   * @brief 接收消息控制电机转
   *
   * @param cmd
   */
  void doActMotor(const std_msgs::Float32::ConstPtr &cmd);
};

#endif