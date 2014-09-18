//-- Common include files --//
#include <ros/ros.h>
#include <ctime>

//-- These files are present in ros_ws/include of the git repository. Have a look at them. --//
#include <math/math.hh>
#include <miscellaneous.h>

//-- Message include files. Include correct message headers for messages to work --//
#include <msi_rover/NavigationDirectives.h>
#include <msi_rover/RoverState.h>
#include <msi_rover/ObstacleScan.h>
#include <geometry_msgs/Pose2D.h>
#include <std_msgs/String.h>

//////////////////////////////////////////////////////

//-- Global Variable Declarations --//
boost::property_tree::ptree Configuration;
ros::Publisher  rover;
ros::Subscriber odometry;
ros::Subscriber obstacle;
ros::Subscriber opencv;
ros::Subscriber master;

//////////////////////////////////////////////////////

//-- Structure Definitions and Declarations --//
struct AttitudeStruct
{
  float                 roll;
  float                 pitch;
  float                 yaw;
};

struct StateStruct
{
  time_t                timestamp;
  math::Vector3         position;
  struct AttitudeStruct attitude;
  math::Vector3         velocity;
  math::Vector3         ang_velocity;
} state;

struct DestStruct
{
  time_t                timestamp;
  math::Vector2d        position;
  float                 yaw;
  bool                  overrideable;
} dest;

struct ScanStruct
{
  time_t                timestamp;
  float                 min_yaw;
  float                 max_yaw;
  float                 min_range;
  float                 max_range;
  float                 delta_yaw;
  std::vector<float>    ranges;
} scan;

//////////////////////////////////////////////////////
float getRange( float yaw ) {
  if ( yaw > scan.max_yaw || yaw < scan.min_yaw ) return -1;
  int index = ( yaw - scan.min_yaw ) / scan.delta_yaw;
  return ( scan.ranges[index] + ( scan.ranges[index+1] - scan.ranges[index] ) * ( ( yaw - scan.min_yaw ) / scan.delta_yaw - (float)index ));
}

//////////////////////////////////////////////////////
void OdometryUpdateCallback(const msi_rover::RoverState::ConstPtr& _state) {
  std::time(&state.timestamp);
  state.position.x     = _state->position.x;
  state.position.y     = _state->position.y;
  state.position.z     = _state->position.z;
  state.attitude.yaw   = _state->attitude.yaw;
  state.attitude.pitch = _state->attitude.pitch;
  state.attitude.roll  = _state->attitude.roll;
  state.velocity.x     = _state->lin_velocity.x;
  state.velocity.y     = _state->lin_velocity.y;
  state.velocity.z     = _state->lin_velocity.z;
  state.ang_velocity.x = _state->ang_velocity.x;
  state.ang_velocity.y = _state->ang_velocity.y;
  state.ang_velocity.z = _state->ang_velocity.z;
}

//////////////////////////////////////////////////////
void ObstacleUpdateCallback(const msi_rover::ObstacleScan::ConstPtr& _scan) {
  std::time(&scan.timestamp);
  scan.min_yaw         = _scan->angle_min;
  scan.max_yaw         = _scan->angle_max;
  scan.delta_yaw       = _scan->angle_increment;
  scan.min_range       = _scan->range_min;
  scan.max_range       = _scan->range_max;
  scan.ranges          = _scan->ranges;
}

//////////////////////////////////////////////////////
void OpenCVCoordUpdateCallback(const geometry_msgs::Pose2D::ConstPtr& _dest);
void MasterCommandCallback(const std_msgs::String::ConstPtr& command);
void Loop();
void Load();

//////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_node");
  ros::NodeHandle _nh("rover");
  Misc::LoadXMLConfig("config/navigation_proc.xml", Configuration);

  rover    = _nh.advertise<msi_rover::NavigationDirectives>("/rover/navigation_proc", 1);
  odometry = _nh.subscribe("/rover/odometry",      1, OdometryUpdateCallback);
  obstacle = _nh.subscribe("/rover/obstacle_scan", 1, ObstacleUpdateCallback);
  opencv   = _nh.subscribe("/rover/opencv_coords", 5, OpenCVCoordUpdateCallback);
  master   = _nh.subscribe("/rover/base_station",  5, MasterCommandCallback);
  Load();

  ROS_INFO("Navigation processing node successfuly loaded :)");

  while( ros::ok() ) {
    Loop();
    ros::spinOnce();
  }
  return 0;
}
