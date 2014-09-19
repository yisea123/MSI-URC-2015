#include <map_generation_sim.hpp>

//////////////////////////////////////////////////////
void Load() {
  cv::namedWindow("DepthMap");
}

//////////////////////////////////////////////////////
void Loop() {
}

//////////////////////////////////////////////////////
void Shutdown() {
  cv::destroyWindow("DepthMap");
}

//////////////////////////////////////////////////////
void DepthMapUpdateCallback(const sensor_msgs::ImageConstPtr& image) {
  cv_bridge::CvImagePtr cv_ptr;
  try {
    cv_ptr = cv_bridge::toCvCopy(image, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("CV_BRIDGE Exception: %s", e.what());
    return;
  }
  cv::imshow("DepthMap",  cv_ptr->image);
  cv::waitKey(3);
}

