//
// Description: 
// Created by sundong on 2021/3/16.
//

#ifndef RADAR_CAMERA_FUSION_CAMERA_DATA_HPP
#define RADAR_CAMERA_FUSION_CAMERA_DATA_HPP

#include <sensor_msgs/Image.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

namespace radar_camera_fusion{
    class CameraData{
    public:
        CameraData();
//    public:
//        using IMAGE = sensor_msgs::Image ;
//        using IMAGE_PTR = IMAGE::Ptr;

    public:
        double time = 0.0;
        cv::Mat image;

    public:
        void ImageCompress(const sensor_msgs::ImageConstPtr& img_in, cv::Mat& img_out);

    };
}

#endif //RADAR_CAMERA_FUSION_CAMERA_DATA_HPP
