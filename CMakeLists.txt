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
  LIBRARIES ${PROJECT_NAME}
  CATKIN_DEPENDS ${PACKAGE_DEPENDENCIES}
#  DEPENDS OCTOMAP
)

########
# LIBS #
########

add_library(${PROJECT_NAME}
  src/octomap_interface.cpp
)
target_link_libraries(${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OCTOMAP_LIBRARIES}
)

#########
# NODES #
#########

add_executable(octomap_node src/octomap_node.cpp)
target_link_libraries(octomap_node
  ${PROJECT_NAME}
  ${catkin_LIBRARIES}
  ${OCTOMAP_LIBRARIES}
)
