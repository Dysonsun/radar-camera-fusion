cmake_minimum_required(VERSION 2.8.3)
project(radar_camera_fusion)

SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
add_compile_options(-std=c++11)
add_definitions(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
        roscpp
        rospy
        std_msgs
        pcl_ros
        geometry_msgs
        tf
        eigen_conversions
        message_generation
        std_srvs
        sensor_driver_msgs
        )



set(ALL_TARGET_LIBRARIES "")

include(cmake/glog.cmake)
#include(cmake/YAML.cmake)
include(cmake/PCL.cmake)
#include(cmake/eigen.cmake)

include_directories(include ${catkin_INCLUDE_DIRS})
include(cmake/global_defination.cmake)
catkin_package()

file(GLOB_RECURSE ALL_SRCS "*.cpp")
file(GLOB_RECURSE NODE_SRCS "src/apps/*_node.cpp")
#file(GLOB_RECURSE THIRD_PARTY_SRCS "third_party/*.cpp")
list(REMOVE_ITEM ALL_SRCS ${NODE_SRCS})
#list(REMOVE_ITEM ALL_SRCS ${THIRD_PARTY_SRCS})

add_executable(test_radar_node src/apps/test_radar_node.cpp ${ALL_SRCS})
target_link_libraries(test_radar_node ${catkin_LIBRARIES} ${ALL_TARGET_LIBRARIES})