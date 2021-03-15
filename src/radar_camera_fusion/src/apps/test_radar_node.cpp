//
// Description: 
// Created by sundong on 2021/3/15.
//

#include <ros/ros.h>
#include "glog/logging.h"


#include "radar_camera_fusion/global_defination/global_defination.h.in"
#include "radar_camera_fusion/subscriber/radar_subscriber.hpp"
#include "radar_camera_fusion/tools/visualizer.hpp"

using namespace radar_camera_fusion;

int main(int argc, char *argv[]){
    google::InitGoogleLogging(argv[0]);
    FLAGS_log_dir = WORK_SPACE_PATH + "/Log";
    FLAGS_alsologtostderr = 1;

    ros::init(argc, argv, "radar_frame_node");
    ros::NodeHandle nh;

    std::shared_ptr<RadarSubscriber> radar_sub_ptr = std::make_shared<RadarSubscriber>(nh, "/radar_front", 100);
    std::shared_ptr<Visualizer> visualizer_ptr = std::make_shared<Visualizer>();

    std::deque<RadarData> radar_data_buff;

    ros::Rate rate(100);
    while (ros::ok()){
        ros::spinOnce();

        radar_sub_ptr->ParseData(radar_data_buff);
        while(!radar_data_buff.empty()){
            RadarData curr_radar_data = radar_data_buff.front();
            visualizer_ptr -> DisplayPC(curr_radar_data);
            radar_data_buff.pop_front();
        }

        rate.sleep();
    }
    return 0;
}