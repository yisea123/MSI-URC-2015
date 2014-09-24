#include <opencv.hpp>

void Load() {
  cv::namedWindow("Stereo_Left");
  cv::namedWindow("Stereo_Right");
}

void Loop() {
  //If any of the image is older than max_lag_t or the difference b/w 2 images is greater max_diff_t
  double stamp = ros::Time::now().toSec() - 1;
  if ( stamp > _left_image_ptr->header.stamp.toSec()
    || stamp > _right_image_ptr->header.stamp.toSec() ) {
    ROS_ERROR("Too much lag in image reception");
    return;
  }
  if ( abs(_left_image_ptr->header.stamp.toSec() - _right_image_ptr->header.stamp.toSec()) > 0.1 ) {
    ROS_ERROR("Right and left images are not of the same time");
    return;
  }
  cv::Mat left_image(_left_image_ptr->image);            //Create local copy of image
  cv::Mat right_image(_right_image_ptr->image);          //As the images may change dynamically during execution

  cv::imshow("Stereo_Left",  left_image);
  cv::imshow("Stereo_Right", right_image);
  cv::waitKey(3);
}

void Shutdown(int signum) {
  ROS_WARN("SHUTTING DOWN");
  ros::shutdown();
  cv::destroyWindow("Stereo_Left");
  cv::destroyWindow("Stereo_Right");
}
