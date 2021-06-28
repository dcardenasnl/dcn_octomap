#include <dcn_octomap/octomap_interface.hpp>

OctomapInterface::OctomapInterface(const ros::NodeHandle nh):
  nh_(nh),
  tf_buffer_(new tf2_ros::Buffer()),
  tf_listener_(new tf2_ros::TransformListener(*tf_buffer_)),
  pointcloud_sub_(nullptr),
  pointcloud_tf_filtered_sub_(nullptr)
{
  /* Subcription */
  pointcloud_sub_ = new message_filters::Subscriber<sensor_msgs::PointCloud2>(nh_, "cloud_in", 5);
  pointcloud_tf_filtered_sub_ = new tf2_ros::MessageFilter<sensor_msgs::PointCloud2>(*pointcloud_sub_, *tf_buffer_, world_frame_, 5, nh_);
  pointcloud_tf_filtered_sub_->registerCallback(boost::bind(&OctomapInterface::cloudCallback, this, _1));
}

OctomapInterface::~OctomapInterface()
{
}

void OctomapInterface::cloudCallback(const sensor_msgs::PointCloud2::ConstPtr& cloud)
{
}
