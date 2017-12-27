
#include "ecust_tool/ecust.hpp"

int main(int argc,char ** argv){
    ros::init(argc,argv,"ecust_transform");
    ros::NodeHandle node;
    ros::Publisher publisher=node.advertise<geometry_msgs::PoseStamped>("camera_estimate_pose",10);
    tf::TransformListener listener;
    geometry_msgs::PoseStamped pose,pose_in,pose_pre;
    pose_in.header.frame_id="/downward_cam_optical_frame";
    pose_in.pose.orientation.w=1;
    ros::Rate rate(10.0);
    bool is_ok=false;
    while(node.ok()){
    	tf::StampedTransform transform;
    	try{
    		listener.lookupTransform("/downward_cam_optical_frame","/world",
    				ros::Time(0),transform);
            listener.transformPose("/world",ros::Time(0),pose_in,"/downward_cam_optical_frame",pose);
    	}catch(tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
    	}
        // 在这里加入pose判断的东西.
        // 如果偏差太大的话绝对不能要
        // 直接比较xyz三个坐标的值就好
        if(abs(pose.pose.position.x)<8
            && abs(pose.pose.position.y)<8
            && abs(pose.pose.position.z)<10
        ){        
            if(pose.pose.position.x==pose_pre.pose.position.x){
                is_ok=false;
            }else{
                is_ok=true;
            }
        }else{
            is_ok=false;
        }


        if(is_ok){
            publisher.publish(pose);
            pose_pre=pose;
        }
        rate.sleep();
    }
    
    ros::spin();
    return 0;
}
