#include <ros/ros.h>

#include <dcn_octomap/octomap_interface.hpp>

int main(int argc, char** argv)
{
  ros::init(argc, argv, "dcn_octomap");
  ros::NodeHandle n("~");
  ROS_INFO("Start ocotmap node");

  while(ros::ok())
  {
    ros::spinOnce();
  }

	return 0;
}
