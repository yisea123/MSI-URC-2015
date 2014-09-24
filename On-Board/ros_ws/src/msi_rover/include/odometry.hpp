//-- Common include files --//
#include <ros/ros.h>
#include <ctime>

//-- These files are present in ros_ws/include of the git repository. Have a look at them. --//
#include <math/math.hh>
#include <miscellaneous.hpp>

//-- Message include files. Include correct message headers for messages to work --//
#include <msi_rover/RoverState.h>

#include <ublas.hpp>
using namespace boost::numeric::ublas;

#define PI 3.14159265359
#define GG 9.8
//////////////////////////////////////////////////////

//-- Global Variable Declarations --//
boost::property_tree::ptree Configuration;
ros::Publisher  rover;
ros::Subscriber odometry;
ros::Subscriber obstacle;
ros::Subscriber opencv;
ros::Subscriber master;

matrix<float> P  (6,6);
matrix<float> Q  (6,6);
matrix<float> R  (3,3);
vector<float> ahrs    (6);
vector<float> vel     (3);
vector<float> acc     (3);
vector<float> gps_vel (3);
float del_t = 0.02;
float p, q, r, Mx, My, Mz;
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

//////////////////////////////////////////////////////
/*
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
*/
//////////////////////////////////////////////////////
void Loop();
void Load();

//////////////////////////////////////////////////////
int main(int argc, char **argv)
{
  ros::init(argc, argv, "odometry");
  ros::NodeHandle _nh("rover");
//  Misc::LoadXMLConfig("config/navigation_proc.xml", Configuration);

//  rover    = _nh.advertise<msi_rover::NavigationDirectives>("/rover/navigation_proc", 1);
//  odometry = _nh.subscribe("/rover/odometry",      1, OdometryUpdateCallback);
//  obstacle = _nh.subscribe("/rover/obstacle_scan", 1, ObstacleUpdateCallback);
//  opencv   = _nh.subscribe("/rover/opencv_coords", 5, OpenCVCoordUpdateCallback);
//  master   = _nh.subscribe("/rover/base_station",  5, MasterCommandCallback);

//  ros::Rate loop_rate(Configuration.get<int>("publishers.navigation_directives.publish_rate"));
  ros::Rate loop_rate(1000);
  Load();

  ROS_INFO("Navigation processing node successfuly loaded :)");

  while( ros::ok() ) {
    Loop();
    ros::spinOnce();
    loop_rate.sleep();
  }
  yaw.close();
  pitch.close();
  roll.close();
  return 0;
}
