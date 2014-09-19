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

//////////////////////////////////////////////////////

//-- Global Variable Declarations --//
boost::property_tree::ptree Configuration;
ros::Publisher  obstacle_scan;
ros::Subscriber environ_periph;
ros::Subscriber opencv_depth;
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
void EnvironPeriphUpdateUpdateCallback(const msi_rover::Peripheral::ConstPtr& _) {
}

//////////////////////////////////////////////////////
void DepthMapUpdateCallback(const msi_rover::DepthMap::ConstPtr& _map);
void Loop();
void Load();

//////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ros::init(argc, argv, "map_generation");
  ros::NodeHandle _nh("rover");
  Misc::LoadXMLConfig("config/map_generation.xml", Configuration);

  obstacle_scan  = _nh.advertise<msi_rover::ObstacleScan>("/rover/obstacle_scan", 1);
  environ_periph = _nh.subscribe("/rover/environ_periph",   5, EnvironPeriphUpdateCallback);
  opencv_depth   = _nh.subscribe("/rover/opencv_depth_map", 1, DepthMapUpdateCallback);
  Load();

  ROS_INFO("Map generation processing node successfuly loaded :)");

  while( ros::ok() ) {
    Loop();
    ros::spinOnce();
  }
  return 0;
}
