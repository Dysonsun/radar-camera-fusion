/*
 * @Description: tf监听模块
 * @Author: Ren Qian
 * @Date: 2020-02-06 16:10:31
 */
#include "radar_camera_fusion/tf_listener/tf_listener.hpp"

#include <Eigen/Geometry>

namespace radar_camera_fusion {
TFListener::TFListener(ros::NodeHandle& nh, std::string base_frame_id, std::string child_frame_id) 
    :nh_(nh), base_frame_id_(base_frame_id), child_frame_id_(child_frame_id) {
}

bool TFListener::LookupData(transform::Rigid3d& transform_rigid) {
    ros::Duration timeout(0.1);
    try {
        tf::StampedTransform transform;
        listener_.lookupTransform(base_frame_id_, child_frame_id_, ros::Time(), transform);

        transform::Rigid3d temp(Eigen::Vector3d(transform.getOrigin().x(), transform.getOrigin().y(), transform.getOrigin().z()),
                                Eigen::Quaterniond(transform.getRotation().w(), transform.getRotation().x()
                                        , transform.getRotation().y(), transform.getRotation().z()));
        transform_rigid = temp;
        return true;

    } catch (tf::TransformException &ex) {
        return false;
    }
}

}