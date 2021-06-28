#include <ros/ros.h>

#include <message_filters/subscriber.h>
#include <tf2_ros/transform_listener.h>
#include <tf2_ros/message_filter.h>

#include <sensor_msgs/PointCloud2.h>

class OctomapInterface
{

public:
  OctomapInterface(const ros::NodeHandle nh);
  ~OctomapInterface();

private:
  void cloudCallback(const sensor_msgs::PointCloud2::ConstPtr& cloud);

private:
  ros::NodeHandle nh_;
  std::shared_ptr<tf2_ros::Buffer> tf_buffer_;
  std::shared_ptr<tf2_ros::TransformListener> tf_listener_;

  /* Frames */
  std::string world_frame_; // the map frame

  /* Input subs */
  message_filters::Subscriber<sensor_msgs::PointCloud2>* pointcloud_sub_;
  tf2_ros::MessageFilter<sensor_msgs::PointCloud2>* pointcloud_tf_filtered_sub_;
};
