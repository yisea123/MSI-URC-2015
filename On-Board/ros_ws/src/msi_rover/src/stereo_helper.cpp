//--Common include files
#include <boost/bind.hpp>
#include <gazebo/gazebo.hh>
#include <gazebo/physics/physics.hh>
#include <gazebo/common/common.hh>
#include <gazebo/common/Plugin.hh>
#include <ros/ros.h>
#include <csignal>
#include <stdlib.h>
#include <geometry_msgs/Quaternion.h>

//--Message include files. Include correct message headers for messages to work

//--Node specific other includes
#include <unistd.h>
#include <termios.h>
#include <cstdio>
#include <sys/ioctl.h>
using namespace std;
void Shutdown(int signum) {
  ros::shutdown();
  gazebo::shutdown();
}

namespace gazebo
{
  class TeleOpClass : public ModelPlugin
  {
    public:
    TeleOpClass() : ModelPlugin()
    {
    }

    void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf)
    {
      // Make sure the ROS node for Gazebo has already been initialized
      if (!ros::isInitialized())
      {
        ROS_FATAL_STREAM("A ROS node for Gazebo has not been initialized, unable to load plugin. "
          << "Load the Gazebo system plugin 'libgazebo_ros_api_plugin.so' in the gazebo_ros package)");
        return;
      }
      // Save Global Pointers
      this->model = _model;
      this->_spinnerThread = boost::thread(boost::bind(&TeleOpClass::LoadThread, this));
    }
   void LoadThread()
    {
      signal(SIGINT, Shutdown);
      ros::NodeHandle _nh("rover");
      this->_updateConnection = event::Events::ConnectWorldUpdateBegin(boost::bind(&TeleOpClass::OnUpdate, this, _1));
      ros::Rate loop_rate(100);
      int byte;
      struct termios t;
      tcgetattr(STDIN_FILENO, &t);
      t.c_lflag &= ~(ECHO | ICANON);
      tcsetattr(STDIN_FILENO, TCSANOW, &t);

      while( ros::ok() )
      {
        ioctl(STDIN_FILENO, FIONREAD, &byte);
        if ( byte > 2 )
        {
          if ( getchar() == 27 )
          {
            if ( getchar() == 91 )
            {
              byte = getchar();
              switch ( byte )
              {
              case 65 :
//                ROS_INFO("KEY PRESSED [UP]");
                what = 1;
                break;
              case 66 :
//                ROS_INFO("KEY PRESSED [DN]");
                what = -1;
                break;
              case 67 :
//                ROS_INFO("KEY PRESSED [RT]");
                what = -2;
                break;
              case 68 :
//                ROS_INFO("KEY PRESSED [LT]");
                what = 2;
                break;
              default :
//                ROS_WARN("INVALID KEY PRESSED");
                what = 0;
              }
            }
          }
        }
        else if ( byte != 0 )
        {
          byte = getchar();
          switch ( byte )
          {
          case 119 :
//            ROS_INFO("KEY PRESSED [W]");
            what = 3;
            break;
          case 115 :
//            ROS_INFO("KEY PRESSED [S]");
            what = -3;
            break;
          case 113 :
//            ROS_INFO("KEY PRESSED [A]");
            what = -4;
            break;
          case 97 :
//            ROS_INFO("KEY PRESSED [Q]");
            what = 4;
            break;
          default :
            ROS_WARN("INVALID KEY PRESSED");
            what = 0;
          }
        }
        else what = 0;
        ros::spinOnce();
        loop_rate.sleep();
      }

      tcgetattr(STDIN_FILENO, &t);
      t.c_lflag |= ICANON;
      tcsetattr(STDIN_FILENO, TCSANOW, &t);
    }

    // Called by the world update start event
    void OnUpdate(const common::UpdateInfo & /*_info*/)
    {
      switch ( what )
      {
      case 1 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0.4,0,0));
        this->model->SetAngularVel(math::Vector3(0,0,0));
        break;
      case -1 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(-0.4,0,0));
        this->model->SetAngularVel(math::Vector3(0,0,0));
        break;
      case 3 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0,0,0.4));
        this->model->SetAngularVel(math::Vector3(0,0,0));
        break;
      case -3 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0,0,-0.4));
        this->model->SetAngularVel(math::Vector3(0,0,0));
        break;
      case -2 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0,0,0));
        this->model->SetAngularVel(math::Vector3(0,0,-0.6));
        break;
      case 2 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0,0,0));
        this->model->SetAngularVel(math::Vector3(0,0,0.6));
        break;
      case -4 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0,0,0));
        this->model->SetAngularVel(math::Vector3(0,-0.6,0));
        break;
      case 4 :
        this->model->SetStatic(0);
        this->model->SetLinearVel(math::Vector3(0,0,0));
        this->model->SetAngularVel(math::Vector3(0,0.6,0));
        break;
      default :
        this->model->SetStatic(1);
        this->model->SetLinearVel(math::Vector3(0,0,0));
        this->model->SetAngularVel(math::Vector3(0,0,0));
      }
    }

    // Global pointer declarations
    private: physics::ModelPtr model;
    private: event::ConnectionPtr _updateConnection;
    private: boost::thread _spinnerThread;
    private: char what;
};
GZ_REGISTER_MODEL_PLUGIN(TeleOpClass);
}
