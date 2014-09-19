#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>

#include <msi_rover/RoverState.h>
#include <stdlib.h>

namespace gazebo
{
  class OdometrySimulator : public ModelPlugin
  {
    public:  ros::Publisher rover_state;
    //---Global Variable Declarations----//
    private: physics::ModelPtr    model;

    private: event::ConnectionPtr _updateConnection;
    private: boost::thread        _spinnerThread;


    //--Callback for World Update Event--//
    private: void OnUpdate()
    {

      math::Pose       _model_pose           = this->model->GetWorldPose();
      math::Vector3    _model_linear_vel     = this->model->GetWorldLinearVel();
      math::Vector3    _model_angular_vel    = this->model->GetWorldAngularVel();

      msi_rover::RoverState state;
      state.position.x       = _model_pose.pos.x;
      state.position.y       = _model_pose.pos.y;
      state.position.z       = _model_pose.pos.z;
      state.attitude.roll    = _model_pose.rot.GetRoll();
      state.attitude.pitch   = _model_pose.rot.GetPitch();
      state.attitude.yaw     = _model_pose.rot.GetYaw();
      state.lin_velocity.x   = _model_linear_vel.x;
      state.lin_velocity.y   = _model_linear_vel.y;
      state.lin_velocity.z   = _model_linear_vel.z;
      state.ang_velocity.x   = _model_angular_vel.x;
      state.ang_velocity.y   = _model_angular_vel.y;
      state.ang_velocity.z   = _model_angular_vel.z;

      this->rover_state.publish(state);
    }

    //--------ROS Spinner Thread---------//
    private: void _ROS_Spinner()
    {
      //--Initialise a ROS NodeHandle with namespace 'rover'--//
      ros::NodeHandle _nh("rover");
      rover_state = _nh.advertise<msi_rover::RoverState>("/rover/odometry", 1);

      this->_updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&OdometrySimulator::OnUpdate, this));
      ROS_INFO("Odometry simulator plugin successfully loaded");

      //--Publish messages and keep looping--//
      while(ros::ok())
      {
        ros::spinOnce();
      }
    }

    //--Called on Plugin Load Event--//
    public: void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
      //--Make sure the ROS node for Gazebo has already been initialized--//
      if (!ros::isInitialized())
      {
        ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
          << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
        exit(EXIT_FAILURE);
      }

      //--Save Global Pointers--//
      this->model             = _model;

      //--Initialise ROS Spinner Thread--//
      this->_spinnerThread = boost::thread(boost::bind(&OdometrySimulator::_ROS_Spinner, this));
    }
};
GZ_REGISTER_MODEL_PLUGIN(OdometrySimulator);
}
