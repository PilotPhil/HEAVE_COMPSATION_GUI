#include <ros/ros.h>

#include "PID.h"

int main(int argc, char *argv[]) {
  // pid对象

  ros::init(argc, argv, "control_algrothim_node");
  PID pid_controller();

  ros::spin();
  return 0;
}
