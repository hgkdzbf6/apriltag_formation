/*
 * ImageTransfer.cpp
 *
 *  Created on: 2018年1月1日
 *      Author: zbf
 */

#include "ecust_tool/ImageTransfer.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "image_transfer");
  ImageTransfer transfer;
  ros::spin();

  return 0;
}

