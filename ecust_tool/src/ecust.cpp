
#include "ecust_tool/ecust.hpp"

int main(int argc,char ** argv){
    ros::init(argc,argv,"ecust_transform");
    ros::NodeHandle node;
    ros::Publisher publisher=node.advertise<geometry_msgs::PoseStamped>("camera_estimate_pose",10);
    ros::Publisher real_pub_=node.advertise<geometry_msgs::PoseStamped>("real_pose",10);
    tf::TransformListener listener;
    geometry_msgs::PoseStamped pose,pose_in,pose_pre,real_pose_in;
    geometry_msgs::PoseStamped real_pose;
    std::string ns=node.getNamespace().substr(1);
    // pose_in.header.frame_id="downward_cam_optical_frame";
    pose_in.header.frame_id=ns+"/downward_cam_optical_frame";
    real_pose_in.header.frame_id="/base_link";
    real_pose_in.pose.orientation.w=1;
    pose_in.pose.orientation.w=1;

    ros::Rate rate(10.0);
    bool is_ok=false;
    while(node.ok()){
        tf::StampedTransform transform;
        tf::StampedTransform transform2;
        try{
            listener.lookupTransform("base_link","/world",
                    ros::Time(0),transform2);
            listener.transformPose("/world",ros::Time(0),real_pose_in,"base_link",real_pose);

            listener.lookupTransform(ns+"/downward_cam_optical_frame","/world",
                    ros::Time(0),transform);
            listener.transformPose("/world",ros::Time(0),pose_in,ns+"/downward_cam_optical_frame",pose);
            // listener.lookupTransform("downward_cam_optical_frame","/world",
            //         ros::Time(0),transform);
            // listener.transformPose("/world",ros::Time(0),pose_in,"downward_cam_optical_frame",pose);
        }catch(tf::TransformException ex){
            ROS_ERROR("%s",ex.what());
            ros::Duration(1.0).sleep();
        }

        real_pub_.publish(real_pose);

        // 在这里加入pose判断的东西.
        // 如果偏差太大的话绝对不能要
        // 直接比较xyz三个坐标的值就好

        // if(abs(pose.pose.position.x)<8
        //     && abs(pose.pose.position.y)<8
        //     && abs(pose.pose.position.z)<10
        // ){        
        //     if(pose.pose.position.x==pose_pre.pose.position.x){
        //         is_ok=false;
        //     }else{
        //         is_ok=true;
        //     }
        // }else{
        //     is_ok=false;
        // }


        // if(is_ok){
        //     publisher.publish(pose);
        //     pose_pre=pose;
        // }
        rate.sleep();
    }
    
    ros::spin();
    return 0;
}
