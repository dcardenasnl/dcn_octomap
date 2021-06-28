cmake_minimum_required(VERSION 3.0.2)
project(dcn_octomap)

add_compile_options(-std=c++11)

set(PACKAGE_DEPENDENCIES
  roscpp
  octomap_ros
  octomap_msgs
  sensor_msgs
  std_msgs
)

find_package(octomap REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  ${PACKAGE_DEPENDENCIES}
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${OCTOMAP_INCLUDE_DIRS}
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES navigation_msgs
  CATKIN_DEPENDS ${PACKAGE_DEPENDENCIES}
#  DEPENDS OCTOMAP
)
