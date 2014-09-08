//--Common include files
#include <ros/ros.h>

//--These files are present in catkin_ws/devel of the git repository. Have a look at them.
#include <math/math.hh>
#include <miscellaneous.h>

//--Message include files. Include correct message headers for messages to work

//--Node specific other includes
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

//using namespace std;
//using namespace cv;

//--Global Variable Declarations--//
//boost::property_tree::ptree Configuration;

static const std::string OPENCV_WINDOW = "Image window";

class ImageConverter
{
  image_transport::ImageTransport _it;
  image_transport::Subscriber _it_subscriber;

public:
  ImageConverter( ros::NodeHandle _nh ) :_it(_nh)
  {
    // Subscrive to input video feed
    _it_subscriber = _it.subscribe("/left/image_raw", 1, &ImageConverter::onFrameReceive, this);

    cv::namedWindow(OPENCV_WINDOW);
  }

  ~ImageConverter()
  {
    cv::destroyWindow(OPENCV_WINDOW);
  }

  void onFrameReceive(const sensor_msgs::ImageConstPtr& msg)
  {
    cv_bridge::CvImagePtr cv_ptr;
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }

    // Draw an example circle on the video stream
    if (cv_ptr->image.rows > 60 && cv_ptr->image.cols > 60)
      cv::circle(cv_ptr->image, cv::Point(50, 50), 10, CV_RGB(255,0,0));

    // Update GUI Window
    cv::imshow(OPENCV_WINDOW, cv_ptr->image);
    cv::waitKey(3);
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "opencv_node");
  ros::NodeHandle _nh("rover");
//  Misc::LoadXMLConfig("/navigation/src/config.xml", Configuration);
  ImageConverter _ic(_nh);

//  ros::ServiceServer service = _nh.advertiseService("/rover/navigation/getTorque", getTorqueCallback);


  while( ros::ok() )
  {
    ros::spinOnce();
  }

  return 0;
}

