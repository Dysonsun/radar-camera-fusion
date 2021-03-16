//
// Description: suscribe radar message, and ansysis data
// Created by sundong on 2021/3/15.
//

#include "radar_camera_fusion/subscriber/radar_subscriber.hpp"
#include "sensor_driver_msgs/RadarObject.h"

namespace radar_camera_fusion{
    RadarSubscriber::RadarSubscriber(ros::NodeHandle& nh, std::string topic_name, size_t buff_size)
    :nh_(nh){
        subscriber_ = nh_.subscribe(topic_name, buff_size, &RadarSubscriber::msg_callback, this);
    }

    void RadarSubscriber::msg_callback(const sensor_driver_msgs::RadarObjects::ConstPtr &radar_msg_ptr) {
        buff_mutex_.lock();
        RadarData radar_objects;


        radar_objects.time = radar_msg_ptr->header.stamp.toSec();
        int index = 0;
        for(int i = 0; i < radar_msg_ptr->objects.size(); i++){
            if(radar_msg_ptr->objects[i].dyn_prop != 0 || radar_msg_ptr->objects[i].invalid_state == false){
//                std::cout << radar_msg_ptr->objects[i].rcs << std::endl;
                continue;
            }
            RadarData::RadarObject radar_object;
            radar_object.id = index;
            radar_object.pose = radar_msg_ptr->objects[i].pose;
            radar_object.rcs = radar_msg_ptr->objects[i].rcs;
            radar_object.vx = radar_msg_ptr->objects[i].vx;
            radar_object.vy = radar_msg_ptr->objects[i].vy;

            radar_objects.radar_objects.push_back(radar_object);
            index ++;
        }

        new_radar_data_.push_back(radar_objects);
        buff_mutex_.unlock();
    }

    void RadarSubscriber::ParseData(std::deque<RadarData> &deque_radar_data) {
        buff_mutex_.lock();
        if(new_radar_data_.size() > 0){
            deque_radar_data.insert(deque_radar_data.end(), new_radar_data_.begin(), new_radar_data_.end());
            new_radar_data_.clear();
        }
        buff_mutex_.unlock();
    }
}