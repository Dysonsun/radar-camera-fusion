//
// Description: 
// Created by sundong on 2021/3/16.
//

#ifndef RADAR_CAMERA_FUSION_CAMERA_SUBSCRIBER_HPP
#define RADAR_CAMERA_FUSION_CAMERA_SUBSCRIBER_HPP

#include <mutex>
#include <deque>
#include <thread>

#include <ros/ros.h>
#include <sensor_msgs/Image.h>

#include "radar_camera_fusion/sensor_data/camera_data.hpp"

namespace radar_camera_fusion{
    class CameraSubscriber{
    public:
        CameraSubscriber(ros::NodeHandle& nh, std::string topic_name, size_t buff_size);
        CameraSubscriber() = default;
        void ParseData(std::deque<CameraData>& deque_camera_data);

    private:
        void msg_callback(const sensor_msgs::ImageConstPtr& camera_msg_ptr);

    private:
        ros::NodeHandle nh_;
        ros::Subscriber subscriber_;
        std::deque<CameraData> new_camera_data_;
        std::mutex buff_mutex_;
    };
}

#endif //RADAR_CAMERA_FUSION_CAMERA_SUBSCRIBER_HPP
