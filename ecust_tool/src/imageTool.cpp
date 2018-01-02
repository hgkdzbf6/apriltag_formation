/*
 * gpsTool.cpp
 *
 *  Created on: 2017-12-26
 *      Author: zbf
 */


#include "ecust_tool/imageTool.hpp"


int main(int argc,char ** argv){
	ros::init(argc,argv,"image_tool");
	ros::NodeHandle node("~");
	std::string sub_str;
	std::string pub_str;
	std::string sub_cam_info_str;
	std::string pub_cam_info_str;
	if(!node.getParam("sub_str",sub_str)){
		sub_str="";
	}
	if(!node.getParam("pub_str",pub_str)){
		pub_str="";
	}
	if(!node.getParam("sub_cam_info_str",sub_cam_info_str)){
		sub_cam_info_str="";
	}
	if(!node.getParam("pub_cam_info_str",pub_cam_info_str)){
		pub_cam_info_str="";
	}
	ImageTool imageTool(sub_str,pub_str,sub_cam_info_str,pub_cam_info_str);

	imageTool.run();
	return 0;
}
