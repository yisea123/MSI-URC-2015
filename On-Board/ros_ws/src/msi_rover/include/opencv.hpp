//--Common include files
#include <ros/ros.h>
#include <csignal>

//--These files are present in catkin_ws/devel of the git repository. Have a look at them.
#include <math/math.hh>
#include <algorithm>
#include <miscellaneous.hpp>

//--Message include files. Include correct message headers for messages to work
#include <sensor_msgs/image_encodings.h>

//--Node specific other includes
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//--Global Variable Declarations--//
boost::property_tree::ptree Configuration;
cv_bridge::CvImagePtr _left_image_ptr;
cv_bridge::CvImagePtr _right_image_ptr;
unsigned char status    = 0;

void onLeftFrameReceive(const sensor_msgs::ImageConstPtr& msg) {
  try {
    _left_image_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    _left_image_ptr->header.stamp = ros::Time::now();
    status = status | 1;
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("CV_BRIDGE Exception: %s", e.what());
    return;
  }
}

void onRightFrameReceive(const sensor_msgs::ImageConstPtr& msg) {
  try {
    _right_image_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    _right_image_ptr->header.stamp = ros::Time::now();
    status = status | 2;
  }
  catch (cv_bridge::Exception& e) {
    ROS_ERROR("CV_BRIDGE Exception: %s", e.what());
    return;
  }
}
void Loop();
void Load();
void Shutdown(int signum);
int main(int argc, char **argv) {
  ros::init(argc, argv, "opencv");
  ros::NodeHandle _nh("rover");
  image_transport::ImageTransport _it(_nh);
  image_transport::Subscriber _it_subscriber_lt;
  image_transport::Subscriber _it_subscriber_rt;
  signal(SIGINT, Shutdown);
//  Misc::LoadXMLConfig("config/opencv.xml", Configuration);

  _it_subscriber_lt = _it.subscribe("/rover/bumblebee/left/image_raw",  1, onLeftFrameReceive);
  _it_subscriber_rt = _it.subscribe("/rover/bumblebee/right/image_raw", 1, onRightFrameReceive);

  ros::Rate loop_rate(5);
  while ((status & 3) != 3) {
    ros::spinOnce();
  }
  Load();
  ROS_INFO("OpenCV node successfully loaded :)");

  while( ros::ok() )
  {
    Loop();
    ros::spinOnce();
    loop_rate.sleep();
  }
  Shutdown(0);

  return 0;
}
