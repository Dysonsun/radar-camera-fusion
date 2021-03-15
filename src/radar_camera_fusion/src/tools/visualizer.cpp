//
// Description: 
// Created by sundong on 2021/3/15.
//

#include <boost/thread/thread.hpp>
#include <opencv2/core/core.hpp>
#include "radar_camera_fusion/tools/visualizer.hpp"


namespace radar_camera_fusion{
    Visualizer::Visualizer()
    :viewer_(new pcl::visualization::PCLVisualizer("Radar Viewer")){
        DisPlayPC_init();
    }

    void Visualizer::DisPlayPC_init() {
        viewer_->addCoordinateSystem(3.0);
        viewer_->setBackgroundColor (0, 0, 0);
        viewer_->initCameraParameters ();
        viewer_->setCameraPosition (0.0, 0.0, 30.0, 0.0, 1.0, 0.0, 0);
        viewer_->setCameraClipDistances (0.0, 100.0);

    }

    void Visualizer::DisplayPC(RadarData& radar_data) {

        viewer_->removeAllPointClouds();
        pcl::PointCloud<pcl::PointXYZI>::Ptr cloud_ptr(new pcl::PointCloud<pcl::PointXYZI>);
        Radardata2PC(radar_data, cloud_ptr);

        pcl::visualization::PointCloudColorHandlerGenericField<pcl::PointXYZI> cloudHandler(cloud_ptr,"z");
        viewer_->addPointCloud<pcl::PointXYZI>(cloud_ptr, cloudHandler, "sample cloud");

        viewer_->setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 3, "sample cloud");
        viewer_->updatePointCloud(cloud_ptr, cloudHandler, "simple cloud");
        viewer_->spinOnce(0.001);
    }

    void Visualizer::Radardata2PC(RadarData &radar_data_in,
                                  pcl::PointCloud<pcl::PointXYZI>::Ptr point_clout_out) {
        viewer_mutex_.lock();
        for(int i = 0; i < radar_data_in.radar_objects.size(); i++){
            pcl::PointXYZI point;
            point.x = radar_data_in.radar_objects[i].pose.x;
            point.y = radar_data_in.radar_objects[i].pose.y;
            point.z = radar_data_in.radar_objects[i].pose.z;
            point.intensity = radar_data_in.radar_objects[i].rcs;
            point_clout_out->push_back(point);
//            std::cout << "cloud pos: " << point.x << " " << point.y << " " << point.z << std::endl;
        }
        viewer_mutex_.unlock();


    }
}