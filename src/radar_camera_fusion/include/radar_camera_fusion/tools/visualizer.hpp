//
// Description: 
// Created by sundong on 2021/3/15.
//

#ifndef LIDAR_LOCALIZATION_VISUALIZER_HPP
#define LIDAR_LOCALIZATION_VISUALIZER_HPP

#include <mutex>
#include <thread>

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/visualization/boost.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_cloud.h>

#include "radar_camera_fusion/sensor_data/radar_data.hpp"

namespace radar_camera_fusion{
    class Visualizer{

    public:
        Visualizer();
        void DisplayPC(RadarData& radar_data);

    private:
        void Radardata2PC(RadarData& radar_data_in,
                          pcl::PointCloud<pcl::PointXYZI>::Ptr pointclout_out);
        void DisPlayPC_init();

    private:
        boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer_;
        std::mutex viewer_mutex_;
    };
}


#endif //LIDAR_LOCALIZATION_VISUALIZER_HPP
