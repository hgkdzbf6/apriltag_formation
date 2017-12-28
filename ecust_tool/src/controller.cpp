/*
 * controller.cpp
 *
 *  Created on: 2017-12-27
 *      Author: zbf
 */

#include "ecust_tool/controller.hpp"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "ecust_controller");
  Controller controller;
  ros::spin();

  return 0;
}

