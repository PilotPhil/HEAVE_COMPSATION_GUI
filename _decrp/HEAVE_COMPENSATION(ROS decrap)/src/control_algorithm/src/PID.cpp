#include "PID.h"

PID::PID() {
  e = target - actual;
  e_pre = e;

  nh.param<float>("kp", kp, 10);
  nh.param<float>("ki", kp, 0.01);
  nh.param<float>("kd", kp, 0.01);

  std::string sub_imu_topic;
  nh.param("sub_topic", sub_imu_topic, std::string("/imu_vel"));

  std::string pub_control_output_topic;
  nh.param("pub_topic", pub_control_output_topic,
           std::string("/control_output"));

  sub = nh.subscribe<imu::vel>(sub_imu_topic, 10, &PID::doControl, this);
  pub = nh.advertise<std_msgs::Float32>(pub_control_output_topic, 10);
}

PID::~PID() {}

float PID::control(float targetValue, float actualValue) {
  float u;
  target = targetValue; //目标值
  actual = actualValue; //真实值（传感器所测）
  e = target - actual;  // error误差
  integral += e;        //误差累积（积分）
  u = kp * e + ki * integral + kd * (e - e_pre); // pid核心
  e_pre = e;                                     //
  return u;
}

void PID::doControl(const imu::vel::ConstPtr &vel) {
  auto v = vel->vel_z;
  auto u = control(0, v); //控制

  std_msgs::Float32 msg;
  msg.data = u;

  pub.publish(msg); //发送控制量
}