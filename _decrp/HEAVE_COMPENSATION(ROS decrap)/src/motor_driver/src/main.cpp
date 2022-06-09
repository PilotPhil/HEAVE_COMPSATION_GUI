#include "MotorDriver.h"
#include <ros/ros.h>
#include <std_msgs/Float32.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "motor_node");

  MotorDriver motorDriver();

  return 0;
}
