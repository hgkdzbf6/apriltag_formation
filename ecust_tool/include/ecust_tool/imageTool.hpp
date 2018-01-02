/*
 * gpsTool.hpp
 *
 *  Created on: 2017-12-26
 *      Author: zbf
 */

#ifndef IMAGE_TOOL_
#define IMAGE_TOOL_

#include <ros/ros.h>
#include "aprilslam/Apriltags.h"
#include "sensor_msgs/CameraInfo.h"

class ImageTool {
public:
	ros::Subscriber apriltags_subscriber_;
	ros::Subscriber cam_info_subscriber_;

	ros::Publisher apriltags_publisher_;
	ros::Publisher cam_info_publisher_;
	std::string sub_image_;
	std::string pub_image_;
	std::string sub_cam_info_;
	std::string pub_cam_info_;

	ImageTool(const std::string& sub_image, const std::string& pub_image,
			const std::string& sub_cam_info, const std::string& pub_cam_info):
				sub_image_(sub_image),pub_image_(pub_image),
				sub_cam_info_(sub_cam_info),pub_cam_info_(pub_cam_info){
		ros::NodeHandle node("/");
		this->apriltags_subscriber_ = node.subscribe(sub_image_, 10,
				&ImageTool::apriltags_callback, this);
		this->cam_info_subscriber_ = node.subscribe(sub_cam_info_, 10,
				&ImageTool::cam_info_callback, this);

		this->apriltags_publisher_ = node.advertise<aprilslam::Apriltags>(
				pub_image_, 10);
		this->cam_info_publisher_ = node.advertise<sensor_msgs::CameraInfo>(
				pub_cam_info_, 10);
	}

	void apriltags_callback(const aprilslam::ApriltagsConstPtr& msg) {
		this->apriltags_publisher_.publish(*msg);
	}

	void cam_info_callback(const sensor_msgs::CameraInfoConstPtr& msg) {
		this->cam_info_publisher_.publish(*msg);
	}

	void run() {
		ros::spin();
	}
};
#endif    /* GPS_TOOL_ */

