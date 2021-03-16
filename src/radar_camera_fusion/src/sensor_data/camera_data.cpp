//
// Description: 
// Created by sundong on 2021/3/16.
//

#include "radar_camera_fusion/sensor_data/camera_data.hpp"

namespace radar_camera_fusion{
    CameraData::CameraData(){
    }

    void CameraData::ImageCompress(const sensor_msgs::ImageConstPtr &img_in, cv::Mat &img_out) {

        cv_bridge::CvImagePtr img_compressed_ptr = cv_bridge::toCvCopy(img_in, sensor_msgs::image_encodings::BGR8);
        img_out = img_compressed_ptr->image;
    }
}