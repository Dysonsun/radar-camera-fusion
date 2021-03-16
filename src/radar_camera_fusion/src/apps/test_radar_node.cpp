//
// Description: 
// Created by sundong on 2021/3/15.
//

#include <ros/ros.h>
#include "glog/logging.h"
#include <yaml-cpp/yaml.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>

#include "radar_camera_fusion/global_defination/global_defination.h"
#include "radar_camera_fusion/subscriber/radar_subscriber.hpp"
#include "radar_camera_fusion/subscriber/camera_subscriber.hpp"
#include "radar_camera_fusion/tf_listener/tf_listener.hpp"
#include "radar_camera_fusion/tools/visualizer.hpp"

#include "radar_camera_fusion/common/rigid_transform.h"

using namespace radar_camera_fusion;

int main(int argc, char *argv[]){
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = WORK_SPACE_PATH + "/Log";
    FLAGS_alsologtostderr = 1;

    ros::init(argc, argv, "radar_frame_node");
    ros::NodeHandle nh;

    std::shared_ptr<RadarSubscriber> radar_sub_ptr = std::make_shared<RadarSubscriber>(nh, "/radar_front", 100);
    std::shared_ptr<CameraSubscriber> camera_sub_ptr = std::make_shared<CameraSubscriber>(nh, "/cam_front/raw", 100);
    std::shared_ptr<TFListener> radar_to_camera_ptr = std::make_shared<TFListener>(nh, "cam_front", "radar_front");

    std::shared_ptr<Visualizer> visualizer_ptr = std::make_shared<Visualizer>();

    std::string config_file_path = WORK_SPACE_PATH + "/config/params.yaml";
    std::cout << "config path: " << config_file_path << std::endl;

    YAML::Node config_node = YAML::LoadFile(config_file_path);

    std::deque<RadarData> radar_data_buff;
    std::deque<CameraData> camera_data_buff;
    transform::Rigid3d radar_to_camera = transform::Rigid3d::Identity();
    Eigen::Matrix3d camera_instrisic = Eigen::Matrix3d::Identity();
    bool TFrecevied_flag = false;

    for(unsigned i = 0; i < 9; i++){
        camera_instrisic(i/3, i%3) = config_node["camera_intrinsic"][i].as<double>();
    }

    ros::Rate rate(100);
    while (ros::ok()){
        ros::spinOnce();

        radar_sub_ptr->ParseData(radar_data_buff);
        camera_sub_ptr->ParseData(camera_data_buff);

        if(!TFrecevied_flag){
            if(radar_to_camera_ptr->LookupData(radar_to_camera)){
                std::cout << "radar to camera maxtric: " << std::endl;
                std::cout << "T: " << radar_to_camera.translation()[0] << " "
                                   << radar_to_camera.translation()[1] << " "
                                   << radar_to_camera.translation()[2] << std::endl;
                std::cout << "R: " << radar_to_camera.rotation().x() << " "
                                   << radar_to_camera.rotation().y() << " "
                                   << radar_to_camera.rotation().z() << " "
                                   << radar_to_camera.rotation().w() << std::endl;
                TFrecevied_flag = true;
            }
        }else{

            while(!radar_data_buff.empty() && !camera_data_buff.empty()) {

                RadarData curr_radar_data = radar_data_buff.front();
                CameraData curr_camera_data = camera_data_buff.front();
                visualizer_ptr->DisplayPC(curr_radar_data);
                visualizer_ptr->DisplayRadarinImage(curr_radar_data, curr_camera_data, radar_to_camera,
                                                    camera_instrisic);
                radar_data_buff.pop_front();
                camera_data_buff.pop_front();
            }
        }


        rate.sleep();
    }
    return 0;
}