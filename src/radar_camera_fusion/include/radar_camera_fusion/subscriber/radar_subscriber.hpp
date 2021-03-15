//
// Description: 
// Created by sundong on 2021/3/15.
//

#ifndef LIDAR_LOCALIZATION_RADAR_SUBSCRIBER_HPP
#define LIDAR_LOCALIZATION_RADAR_SUBSCRIBER_HPP

#include <deque>
#include <mutex>
#include <thread>

#include <ros/ros.h>

#include "sensor_driver_msgs/RadarObjects.h"
#include "radar_camera_fusion/sensor_data/radar_data.hpp"

namespace radar_camera_fusion{
    class RadarSubscriber{
    public:
        RadarSubscriber(ros::NodeHandle& nh, std::string topic_name, size_t buff_size);
        RadarSubscriber() = default;
        void ParseData(std::deque<RadarData>& deque_radar_data);

    private:
        void msg_callback(const sensor_driver_msgs::RadarObjects::ConstPtr& radar_msg_ptr);

    private:
        ros::NodeHandle nh_;
        ros::Subscriber subscriber_;
        std::deque<RadarData> new_radar_data_;

        std::mutex buff_mutex_;
    };
}


#endif //LIDAR_LOCALIZATION_RADAR_SUBSCRIBER_HPP
