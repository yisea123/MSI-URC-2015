//--Common include files
#include <ros/ros.h>

//--These files are present in catkin_ws/devel of the git repository. Have a look at them.
#include <math/math.hh>
#include <miscellaneous.h>

//--Message include files. Include correct message headers for messages to work
#include <navigation/navigation_srv.h>

//--Global Variable Declarations--//
boost::property_tree::ptree Configuration;
/*
float yaw_correct_I = 0;
float yaw_err_prev = 0;

bool getTorqueCallback ( navigation::getTorque::Request  &_model_state, navigation::getTorque::Response &_torque )
{
  math::Vector3 _model_linear_vel ( _model_state.twist.linear.x, _model_state.twist.linear.y, _model_state.twist.linear.z );
  math::Vector3 _model_direction  ( cos(_model_state.orientation.yaw), sin(_model_state.orientation.yaw), 0);
  math::Vector3 _target_direction ( Configuration.get<float>("rover.finalPose.x") - _model_state.position.x,
                                        Configuration.get<float>("rover.finalPose.y") - _model_state.position.y, 0);
  float _dist_to_target = _target_direction.GetLength();
  _target_direction     = _target_direction.Normalize();

  if (_dist_to_target > Configuration.get<float>("rover.poseControl.tolerance")) {
    float yaw_err        = _target_direction.Cross(_model_direction).z;
    if ( (_target_direction.Dot(_model_direction) < 0) || (abs(yaw_err) > Configuration.get<float>("rover.poseControl.yaw.critical")) )
    {
      yaw_err = ( yaw_err > 0 ) ? 1000 : -1000 ;
      _torque.front_left  = +1 * yaw_err;
      _torque.front_right = -1 * yaw_err;
      _torque.rear_left   = +1 * yaw_err;
      _torque.rear_right  = -1 * yaw_err;
    }
    else
    {
      yaw_correct_I        = ( yaw_correct_I + yaw_err ) * Configuration.get<float>("rover.poseControl.yaw.ki");
      float yaw_correction = Configuration.get<float>("rover.poseControl.yaw.kp")*yaw_err
				+ yaw_correct_I
				+ Configuration.get<float>("rover.poseControl.yaw.kd") * yaw_err_prev;

      float torque = exp( Configuration.get<float>("rover.speed.exponent")
				* (Configuration.get<float>("rover.speed.value") - _model_linear_vel.GetLength()) );

      _torque.front_left  = torque*(1 + yaw_correction);
      _torque.front_right = torque*(1 - yaw_correction);
      _torque.rear_left   = torque*(1 + yaw_correction);
      _torque.rear_right  = torque*(1 - yaw_correction);
      _torque.short_motors= 0;
    }

    ROS_INFO("POSITION:\t[%f]\t[%f]\t[%f]", _model_state.position.x, _model_state.position.y, _model_linear_vel.GetLength());
    ROS_INFO("__TARGET:\t[%f]\t[%f]\t[%f]", _target_direction.x, _target_direction.y, _dist_to_target);
    ROS_INFO("TORQ__FL:\t[%f]\tFR\t[%f]\tBL\t[%f]\tBR\t[%f]", _torque.front_left, _torque.front_right, _torque.rear_left, _torque.rear_right);
    float _max_permit_torque  = Configuration.get<float>("rover.maxTorque");;
    float _max_applied_torque = std::max(abs(_torque.front_left), abs(_torque.front_right));
    _max_applied_torque       = std::max(abs(_max_applied_torque), abs(_torque.rear_left));
    _max_applied_torque       = std::max(abs(_max_applied_torque), abs(_torque.rear_right));

    float _scale = ( _max_applied_torque == 0 ) ? 0 : _max_permit_torque /  _max_applied_torque;
    _scale = ( _scale > 1 )? 1 : _scale;
    _torque.front_left  = _torque.front_left   * _scale;
    _torque.front_right =  _torque.front_right * _scale;
    _torque.rear_left   = _torque.rear_left    * _scale;
    _torque.rear_right  = _torque.rear_right   * _scale;
    ROS_INFO("TORQ__FL:\t[%f]\tFR\t[%f]\tBL\t[%f]\tBR\t[%f]\n", _torque.front_left, _torque.front_right, _torque.rear_left, _torque.rear_right);
  }
  else
  {
    _torque.front_left  = 0;
    _torque.front_right = 0;
    _torque.rear_left   = 0;
    _torque.rear_right  = 0;
    _torque.short_motors= 1;
  }
  return true;
}
*/
int main(int argc, char **argv)
{
  ros::init(argc, argv, "navigation_node");
  ros::NodeHandle _nh("rover");
  Misc::LoadXMLConfig("/navigation/src/config.xml", Configuration);

//  ros::ServiceServer service = _nh.advertiseService("/rover/navigation/getTorque", getTorqueCallback);

  ros::spin();
  return 0;
}

