/*
 * gpsTool.hpp
 *
 *  Created on: 2017-12-26
 *      Author: zbf
 */




#ifndef GPS_TOOL_
#define GPS_TOOL_

#include <ros/ros.h>
#include <sensor_msgs/NavSatFix.h>
#include <geometry_msgs/Vector3Stamped.h>
#include <geometry_msgs/PoseStamped.h>

class GpsTool{
public:
	ros::Subscriber gps_subscriber;
	ros::Subscriber gps_velocity_subscriber;
	ros::Subscriber cam_pose_subscriber;

	ros::Publisher gps_publisher;
	ros::Publisher gps_velocity_publisher;
	ros::Publisher cam_pose_publisher;
	bool gps_pub_flag;
	int num;
	GpsTool():num(0),gps_pub_flag(false){
		ros::NodeHandle node;
		this->gps_subscriber=node.subscribe("fix",10,&GpsTool::gps_callback,this);
		this->gps_velocity_subscriber=
					node.subscribe("fix_velocity",10,&GpsTool::gps_velocity_callback,this);
		this->cam_pose_subscriber=
					node.subscribe("camera_estimate_pose",10,&GpsTool::cam_callback,this);

		this->gps_publisher=node.advertise<sensor_msgs::NavSatFix>("fix0",10);
		this->gps_velocity_publisher=
					node.advertise<geometry_msgs::Vector3Stamped>("fix_velocity0",10);
		this->cam_pose_publisher=node.advertise<geometry_msgs::PoseStamped>("/cam_estimate_pose",10);

	}
	void cam_callback(const geometry_msgs::PoseStampedConstPtr& msg){
		if(!gps_pub_flag){
			this->cam_pose_publisher.publish(*msg);
		}
	}

	void gps_callback(const sensor_msgs::NavSatFixConstPtr& msg){
		if(num<120){
			gps_pub_flag=true;
		}else{
			gps_pub_flag=false;
		}
		
		if(gps_pub_flag){
			this->gps_publisher.publish(*msg);
		}
		num++;
	}
	void gps_velocity_callback(const geometry_msgs::Vector3StampedConstPtr& msg){
		if(gps_pub_flag){
			this->gps_velocity_publisher.publish(*msg);
		}
	}
	void run(){
		ros::spin();
	}
};
#endif    /* GPS_TOOL_ */
