//
// Description: 
// Created by sundong on 2021/3/16.
//

#include "radar_camera_fusion/subscriber/camera_subscriber.hpp"

#include <sensor_msgs/image_encodings.h>

namespace radar_camera_fusion{
    CameraSubscriber::CameraSubscriber(ros::NodeHandle &nh, std::string topic_name, size_t buff_size)
        : nh_(nh){
        subscriber_ = nh_.subscribe(topic_name, buff_size, &CameraSubscriber::msg_callback, this);
    }

    void CameraSubscriber::msg_callback(const sensor_msgs::ImageConstPtr &camera_msg_ptr) {

       buff_mutex_.lock();
       CameraData camera_data;
       camera_data.time = camera_msg_ptr->header.stamp.toSec();
       camera_data.ImageCompress(camera_msg_ptr, camera_data.image);
       new_camera_data_.push_back(camera_data);
       buff_mutex_.unlock();
    }

    void CameraSubscriber::ParseData(std::deque<CameraData> &deque_camera_data) {
        buff_mutex_.lock();
        if(!new_camera_data_.empty()){
            deque_camera_data.insert(deque_camera_data.end(), new_camera_data_.begin(), new_camera_data_.end());
            new_camera_data_.clear();
        }
        buff_mutex_.unlock();
    }
}