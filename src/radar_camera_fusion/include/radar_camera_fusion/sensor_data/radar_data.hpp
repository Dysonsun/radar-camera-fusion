//
// Description: 
// Created by sundong on 2021/3/15.
//

#ifndef LIDAR_LOCALIZATION_RADAR_DATA_HPP
#define LIDAR_LOCALIZATION_RADAR_DATA_HPP

//#include <pcl/point_cloud.h>
#include <geometry_msgs/Vector3.h>

namespace radar_camera_fusion{
class RadarData{
    public:
        struct RadarObject{
            int id = 0;
            geometry_msgs::Vector3 pose;
            double rcs = 0.0;
            double vx = 0.0;
            double vy = 0.0;


        };
    public:
        double time = 0.0;
        std::vector<RadarObject> radar_objects;


};
}
#endif //LIDAR_LOCALIZATION_RADAR_DATA_HPP
