/*
 * @Description: tf监听模块
 * @Author: Ren Qian
 * @Date: 2020-02-06 16:01:21
 */
#ifndef LIDAR_LOCALIZATION_TF_LISTENER_HPP_
#define LIDAR_LOCALIZATION_TF_LISTENER_HPP_

#include <string>

#include <Eigen/Dense>
#include <ros/ros.h>
#include <tf/transform_listener.h>

#include "radar_camera_fusion/common/rigid_transform.h"

namespace radar_camera_fusion {
class TFListener {
  public:
    TFListener(ros::NodeHandle& nh, std::string base_frame_id, std::string child_frame_id);
    TFListener() = default;

    bool LookupData(transform::Rigid3d& transform_rigid);
  
  private:
    bool TransformToMatrix(const tf::StampedTransform& transform, transform::Rigid3d& transform_rigid);

  private:
    ros::NodeHandle nh_;
//    tf2_ros::Buffer*  tf_buffer_;
    tf::TransformListener listener_;
    std::string base_frame_id_;
    std::string child_frame_id_;
};
}

#endif