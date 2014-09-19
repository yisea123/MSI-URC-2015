/*------------------------------------------------------------------------------------------------------------*/
/*---------------------------------------------  Reference Table  --------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*                                                                                                            *
 *  Value        | Variable             | Type               | Reference                                      *
 * ---------------------------------------------------------------------------------------------------------- *
STATE
 *  Last updated | state.timestamp      | time_t             | http://www.cplusplus.com/reference/ctime/
 *  Position     | state.position       | math::Vector3      | http://osrf-distributions.s3.amazonaws.com/gazebo/api/4.0.0/classgazebo_1_1math_1_1Vector3.html
 *  Yaw          | state.attitude.yaw   | float              |
 *  Pitch        | state.attitude.pitch | float              |
 *  Roll         | state.attitude.roll  | float              |
 *  Velocity     | state.velocity       | math::Vector3      | http://osrf-distributions.s3.amazonaws.com/gazebo/api/4.0.0/classgazebo_1_1math_1_1Vector3.html
 *  Ang velocity | state.ang_velocity   | math::Vector3      | http://osrf-distributions.s3.amazonaws.com/gazebo/api/4.0.0/classgazebo_1_1math_1_1Vector3.html
SCAN
 *  Last updated | scan.timestamp       | time_t             | http://www.cplusplus.com/reference/ctime/
 *  Min yaw      | scan.min_yaw         | float              |
 *  Max yaw      | scan.max_yaw         | float              |
 *  Delta yaw    | scan.delta_yaw       | float              |
 *  Min range    | scan.min_range       | float              |
 *  Max range    | scan.max_range       | float              |
 *  Ranges       | scan.ranges          | std::vector<float> | http://www.cplusplus.com/reference/vector/vector/
DESTINATION
 *  Last updated | dest.timestamp       | time_t             | http://www.cplusplus.com/reference/ctime/
 *  Position     | dest.position        | math::Vector2d     | http://osrf-distributions.s3.amazonaws.com/gazebo/api/4.0.0/classgazebo_1_1math_1_1Vector2d.html
 *  Yaw          | dest.yaw             | float              |
 *  Overridable  | dest.overrideable    | bool               |
 *
/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/
/*
 *  FUNCTIONS
 *
 *  float getRange( float yaw );                //Linear interpolated range in meters for a given yaw in radians
 *                                              // -1 if error / empty
 *  Configuration.get<bool>("rover.OpenCVNav"); //Read configuration from msi_rover/config/navigation_proc.xml
 */
/*------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------------------------------------*/

#include <navigation_proc.hpp>

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Load() { ; }

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Loop() { ; }

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void OpenCVCoordUpdateCallback(const geometry_msgs::Pose2D::ConstPtr& _dest) {
  if ( Configuration.get<bool>("control.OpenCVNav") ) {
    std::time(&dest.timestamp);
    dest.overrideable  = 1;
    dest.position.x    = _dest->x;
    dest.position.y    = _dest->y;
    dest.yaw           = _dest->theta;
  }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
void MasterCommandCallback(const std_msgs::String::ConstPtr& command)
{
  //------------------------------//
  //------------ TODO ------------//
  //------------------------------//
}
