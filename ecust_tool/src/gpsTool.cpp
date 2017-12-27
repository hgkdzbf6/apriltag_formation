/*
 * gpsTool.cpp
 *
 *  Created on: 2017-12-26
 *      Author: zbf
 */


#include "ecust_tool/gpsTool.hpp"


int main(int argc,char ** argv){
	ros::init(argc,argv,"gps_tool");
	GpsTool gpsTool;
	gpsTool.run();
	return 0;
}
