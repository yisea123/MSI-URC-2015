//-- Common include files --//
#include <ros/ros.h>
#include <ctime>

//-- These files are present in ros_ws/include of the git repository. Have a look at them. --//
#include <math/math.hh>
#include <miscellaneous.hpp>

//-- Message include files. Include correct message headers for messages to work --//
#include <msi_rover/ObstacleScan.h>
#include <geometry_msgs/Pose2D.h>
#include <std_msgs/String.h>
#include <sensor_msgs/image_encodings.h>
#include <sensor_msgs/LaserScan.h>

//-- Node specific other includes --//
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <unistd.h>

//////////////////////////////////////////////////////

//-- Global Variable Declarations --//
boost::property_tree::ptree Configuration;
image_transport::Subscriber opencv_depth;
ros::Publisher  obstacle_scan;
ros::Subscriber environ_periph;
ros::Subscriber odometry;

//////////////////////////////////////////////////////

//-- Structure Definitions and Declarations --//
struct AttitudeStruct
{
  float                 roll;
  float                 pitch;
  float                 yaw;
} camera_state;

struct StateStruct
{
  time_t                timestamp;
  math::Vector3         position;
  struct AttitudeStruct attitude;
  math::Vector3         velocity;
  math::Vector3         ang_velocity;
} rover_state;

//////////////////////////////////////////////////////
//void EnvironPeriphUpdateUpdateCallback(const msi_rover::Peripheral::ConstPtr& _scan) {
void EnvironPeriphUpdateCallback(const sensor_msgs::LaserScan::ConstPtr& _scan) {
  msi_rover::ObstacleScan scan;
  scan.angle_min       = _scan->angle_min;
  scan.angle_max       = _scan->angle_max;
  scan.angle_increment = _scan->angle_increment;
  scan.range_min       = _scan->range_min;
  scan.range_max       = _scan->range_max;
  scan.ranges.clear();
  for( int index = 0; index < _scan->ranges.size(); index++) {
    if ( _scan->ranges[index] < scan.range_min || _scan->ranges[index] > scan.range_max ) scan.ranges.push_back(-1);
    else scan.ranges.push_back(_scan->ranges[index]);
  }
  obstacle_scan.publish(scan);
}

//////////////////////////////////////////////////////
void DepthMapUpdateCallback(const sensor_msgs::ImageConstPtr& image);
void Loop();
void Load();
void Shutdown();

//////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ros::init(argc, argv, "map_generation");
  ros::NodeHandle _nh("rover");
  image_transport::ImageTransport _it(_nh);
  Misc::LoadXMLConfig("config/map_generation.xml", Configuration);

  obstacle_scan  = _nh.advertise<msi_rover::ObstacleScan>("/rover/obstacle_scan", 1);
  environ_periph = _nh.subscribe("/rover/environ_periph",   5, EnvironPeriphUpdateCallback);
  opencv_depth   = _it.subscribe("/rover/opencv_depth_map", 1, DepthMapUpdateCallback);
  Load();

  ROS_INFO("Map generation processing node successfuly loaded :)");

  while( ros::ok() ) {
    Loop();
    ros::spinOnce();
  }
  Shutdown();
  return 0;
}
