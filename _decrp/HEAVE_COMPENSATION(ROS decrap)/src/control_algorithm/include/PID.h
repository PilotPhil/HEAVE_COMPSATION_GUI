#ifndef PID_H
#define PID_H

#include <ros/ros.h>
#include <std_msgs/Float32.h>
#include "imu/vel.h"

class PID {
private:
  float kp;       //比例系数
  float ki;       //积分系数
  float kd;       //微分系数
  float target;   //目标值
  float actual;   //实际值
  float e;        //误差
  float e_pre;    //上一次误差
  float integral; //积分项

  ros::NodeHandle nh;
  ros::Subscriber sub;
  ros::Publisher pub;

public:
  /**
   * @brief Construct a new PID object
   *
   */
  PID();

  /**
   * @brief Destroy the PID object
   *
   */
  ~PID();

  /**
   * @brief PID控制函数
   *
   * @param targetValue 目标值
   * @param actualValue 传感器所测的真实值
   * @return float 控制输出量
   */
  float control(float targetValue, float actualValue);

  /**
   * @brief 接收传感器数值的回调函数
   * 
   */
  void doControl(const imu::vel::ConstPtr& vel);
};

#endif