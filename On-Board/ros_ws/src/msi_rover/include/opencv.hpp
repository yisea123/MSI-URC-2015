//--Common include files
#include <ros/ros.h>

//--These files are present in catkin_ws/devel of the git repository. Have a look at them.
#include <math/math.hh>
#include <miscellaneous.hpp>

//--Message include files. Include correct message headers for messages to work
#include <sensor_msgs/image_encodings.h>

//--Node specific other includes
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

#define _LEFT_ 1
#define _RIGHT_ 0

//--Global Variable Declarations--//
boost::property_tree::ptree Configuration;

void onFrameReceive(const sensor_msgs::ImageConstPtr& msg, bool left)
{
  cv_bridge::CvImagePtr cv_ptr;
  try
  {
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
  }
  catch (cv_bridge::Exception& e)
  {
    ROS_ERROR("CV_BRIDGE Exception: %s", e.what());
    return;
  }
  if ( left )
  {
    cv::imshow("LeftStereoImage",  cv_ptr->image);
  }
  else
  {
    cv::imshow("RightStereoImage", cv_ptr->image);
  }
  cv::waitKey(3);
}
void onLeftFrameReceive(const sensor_msgs::ImageConstPtr& msg) { onFrameReceive(msg, _LEFT_); }
void onRightFrameReceive(const sensor_msgs::ImageConstPtr& msg) { onFrameReceive(msg, _RIGHT_); }

int main(int argc, char **argv)
{
  ros::init(argc, argv, "opencv_node");
  ros::NodeHandle _nh("rover");
  image_transport::ImageTransport _it(_nh);
  image_transport::Subscriber _it_subscriber_lt;
  image_transport::Subscriber _it_subscriber_rt;
  Misc::LoadXMLConfig("config/stereo_config.xml", Configuration);

  usleep(1000000);

  _it_subscriber_lt = _it.subscribe("/left/image_raw",  1, onLeftFrameReceive);
  _it_subscriber_rt = _it.subscribe("/right/image_raw", 1, onRightFrameReceive);

  cv::namedWindow("LeftStereoImage");
  cv::namedWindow("RightStereoImage");
  while( ros::ok() )
  {
    ros::spinOnce();
  }
  cv::destroyWindow("RightStereoImage");
  cv::destroyWindow("LeftStereoImage");
  return 0;
}
