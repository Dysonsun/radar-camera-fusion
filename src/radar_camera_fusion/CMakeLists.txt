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
        cv_bridge
        )



set(ALL_TARGET_LIBRARIES "")

find_package(Protobuf REQUIRED "3.14.0")
include_directories(${Protobuf_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})


find_package(OpenCV REQUIRED)

include(cmake/glog.cmake)
include(cmake/YAML.cmake)
include(cmake/PCL.cmake)
include(cmake/eigen.cmake)
list(APPEND ALL_TARGET_LIBRARIES ${PROTOBUF_LIBRARIES})
list(APPEND ALL_TARGET_LIBRARIES ${OpenCV_LIBRARIES})

include_directories(include ${catkin_INCLUDE_DIRS})
include(cmake/global_defination.cmake)
catkin_package()

file(GLOB_RECURSE ALL_PROTOS "include/radar_camera_fusion/common/proto/*.pb.cc")
file(GLOB_RECURSE ALL_SRCS "*.cpp")
file(GLOB_RECURSE NODE_SRCS "src/apps/*_node.cpp")
#file(GLOB_RECURSE THIRD_PARTY_SRCS "third_party/*.cpp")
list(REMOVE_ITEM ALL_SRCS ${NODE_SRCS})
#list(REMOVE_ITEM ALL_SRCS ${THIRD_PARTY_SRCS})

#protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS "include/radar_camera_fusion/common/proto/transform.proto")

add_executable(test_radar_node src/apps/test_radar_node.cpp ${ALL_SRCS} ${ALL_PROTOS})
target_link_libraries(test_radar_node ${catkin_LIBRARIES} ${ALL_TARGET_LIBRARIES})