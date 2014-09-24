/* Software License Agreement (BSD License)
 *
 * Copyright (c) 2011, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above
 *    copyright notice, this list of conditions and the following
 *    disclaimer in the documentation and/or other materials provided
 *    with the distribution.
 *  * Neither the name of Willow Garage, Inc. nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Auto-generated by genmsg_cpp from file /home/singularity/git/MSI-URC-2015/On-Board/ros_ws/src/msi_rover/msg/NavigationDirectives.msg
 *
 */


#ifndef MSI_ROVER_MESSAGE_NAVIGATIONDIRECTIVES_H
#define MSI_ROVER_MESSAGE_NAVIGATIONDIRECTIVES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace msi_rover
{
template <class ContainerAllocator>
struct NavigationDirectives_
{
  typedef NavigationDirectives_<ContainerAllocator> Type;

  NavigationDirectives_()
    : fl_steer_ang(0.0)
    , fr_steer_ang(0.0)
    , rl_steer_ang(0.0)
    , rr_steer_ang(0.0)
    , fl_wheel_rpm(0.0)
    , fr_wheel_rpm(0.0)
    , ml_wheel_rpm(0.0)
    , mr_wheel_rpm(0.0)
    , rl_wheel_rpm(0.0)
    , rr_wheel_rpm(0.0)
    , short_fl_wheel(false)
    , short_fr_wheel(false)
    , short_ml_wheel(false)
    , short_mr_wheel(false)
    , short_rl_wheel(false)
    , short_rr_wheel(false)
    , hand_brake(false)  {
    }
  NavigationDirectives_(const ContainerAllocator& _alloc)
    : fl_steer_ang(0.0)
    , fr_steer_ang(0.0)
    , rl_steer_ang(0.0)
    , rr_steer_ang(0.0)
    , fl_wheel_rpm(0.0)
    , fr_wheel_rpm(0.0)
    , ml_wheel_rpm(0.0)
    , mr_wheel_rpm(0.0)
    , rl_wheel_rpm(0.0)
    , rr_wheel_rpm(0.0)
    , short_fl_wheel(false)
    , short_fr_wheel(false)
    , short_ml_wheel(false)
    , short_mr_wheel(false)
    , short_rl_wheel(false)
    , short_rr_wheel(false)
    , hand_brake(false)  {
    }



   typedef float _fl_steer_ang_type;
  _fl_steer_ang_type fl_steer_ang;

   typedef float _fr_steer_ang_type;
  _fr_steer_ang_type fr_steer_ang;

   typedef float _rl_steer_ang_type;
  _rl_steer_ang_type rl_steer_ang;

   typedef float _rr_steer_ang_type;
  _rr_steer_ang_type rr_steer_ang;

   typedef float _fl_wheel_rpm_type;
  _fl_wheel_rpm_type fl_wheel_rpm;

   typedef float _fr_wheel_rpm_type;
  _fr_wheel_rpm_type fr_wheel_rpm;

   typedef float _ml_wheel_rpm_type;
  _ml_wheel_rpm_type ml_wheel_rpm;

   typedef float _mr_wheel_rpm_type;
  _mr_wheel_rpm_type mr_wheel_rpm;

   typedef float _rl_wheel_rpm_type;
  _rl_wheel_rpm_type rl_wheel_rpm;

   typedef float _rr_wheel_rpm_type;
  _rr_wheel_rpm_type rr_wheel_rpm;

   typedef uint8_t _short_fl_wheel_type;
  _short_fl_wheel_type short_fl_wheel;

   typedef uint8_t _short_fr_wheel_type;
  _short_fr_wheel_type short_fr_wheel;

   typedef uint8_t _short_ml_wheel_type;
  _short_ml_wheel_type short_ml_wheel;

   typedef uint8_t _short_mr_wheel_type;
  _short_mr_wheel_type short_mr_wheel;

   typedef uint8_t _short_rl_wheel_type;
  _short_rl_wheel_type short_rl_wheel;

   typedef uint8_t _short_rr_wheel_type;
  _short_rr_wheel_type short_rr_wheel;

   typedef uint8_t _hand_brake_type;
  _hand_brake_type hand_brake;




  typedef boost::shared_ptr< ::msi_rover::NavigationDirectives_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msi_rover::NavigationDirectives_<ContainerAllocator> const> ConstPtr;

}; // struct NavigationDirectives_

typedef ::msi_rover::NavigationDirectives_<std::allocator<void> > NavigationDirectives;

typedef boost::shared_ptr< ::msi_rover::NavigationDirectives > NavigationDirectivesPtr;
typedef boost::shared_ptr< ::msi_rover::NavigationDirectives const> NavigationDirectivesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msi_rover::NavigationDirectives_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msi_rover::NavigationDirectives_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace msi_rover

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'gazebo_msgs': ['/opt/ros/indigo/share/gazebo_msgs/cmake/../msg'], 'trajectory_msgs': ['/opt/ros/indigo/share/trajectory_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/indigo/share/std_msgs/cmake/../msg'], 'msi_rover': ['/home/singularity/git/MSI-URC-2015/On-Board/ros_ws/src/msi_rover/msg'], 'geometry_msgs': ['/opt/ros/indigo/share/geometry_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/indigo/share/sensor_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msi_rover::NavigationDirectives_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msi_rover::NavigationDirectives_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msi_rover::NavigationDirectives_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ac6f5cb26ce48f21ca50223e91c33fc6";
  }

  static const char* value(const ::msi_rover::NavigationDirectives_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xac6f5cb26ce48f21ULL;
  static const uint64_t static_value2 = 0xca50223e91c33fc6ULL;
};

template<class ContainerAllocator>
struct DataType< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msi_rover/NavigationDirectives";
  }

  static const char* value(const ::msi_rover::NavigationDirectives_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float32 fl_steer_ang\n\
float32 fr_steer_ang\n\
float32 rl_steer_ang\n\
float32 rr_steer_ang\n\
\n\
float32 fl_wheel_rpm\n\
float32 fr_wheel_rpm\n\
float32 ml_wheel_rpm\n\
float32 mr_wheel_rpm\n\
float32 rl_wheel_rpm\n\
float32 rr_wheel_rpm\n\
\n\
bool    short_fl_wheel\n\
bool    short_fr_wheel\n\
bool    short_ml_wheel\n\
bool    short_mr_wheel\n\
bool    short_rl_wheel\n\
bool    short_rr_wheel\n\
\n\
bool    hand_brake\n\
\n\
";
  }

  static const char* value(const ::msi_rover::NavigationDirectives_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.fl_steer_ang);
      stream.next(m.fr_steer_ang);
      stream.next(m.rl_steer_ang);
      stream.next(m.rr_steer_ang);
      stream.next(m.fl_wheel_rpm);
      stream.next(m.fr_wheel_rpm);
      stream.next(m.ml_wheel_rpm);
      stream.next(m.mr_wheel_rpm);
      stream.next(m.rl_wheel_rpm);
      stream.next(m.rr_wheel_rpm);
      stream.next(m.short_fl_wheel);
      stream.next(m.short_fr_wheel);
      stream.next(m.short_ml_wheel);
      stream.next(m.short_mr_wheel);
      stream.next(m.short_rl_wheel);
      stream.next(m.short_rr_wheel);
      stream.next(m.hand_brake);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct NavigationDirectives_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msi_rover::NavigationDirectives_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msi_rover::NavigationDirectives_<ContainerAllocator>& v)
  {
    s << indent << "fl_steer_ang: ";
    Printer<float>::stream(s, indent + "  ", v.fl_steer_ang);
    s << indent << "fr_steer_ang: ";
    Printer<float>::stream(s, indent + "  ", v.fr_steer_ang);
    s << indent << "rl_steer_ang: ";
    Printer<float>::stream(s, indent + "  ", v.rl_steer_ang);
    s << indent << "rr_steer_ang: ";
    Printer<float>::stream(s, indent + "  ", v.rr_steer_ang);
    s << indent << "fl_wheel_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.fl_wheel_rpm);
    s << indent << "fr_wheel_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.fr_wheel_rpm);
    s << indent << "ml_wheel_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.ml_wheel_rpm);
    s << indent << "mr_wheel_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.mr_wheel_rpm);
    s << indent << "rl_wheel_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.rl_wheel_rpm);
    s << indent << "rr_wheel_rpm: ";
    Printer<float>::stream(s, indent + "  ", v.rr_wheel_rpm);
    s << indent << "short_fl_wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.short_fl_wheel);
    s << indent << "short_fr_wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.short_fr_wheel);
    s << indent << "short_ml_wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.short_ml_wheel);
    s << indent << "short_mr_wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.short_mr_wheel);
    s << indent << "short_rl_wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.short_rl_wheel);
    s << indent << "short_rr_wheel: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.short_rr_wheel);
    s << indent << "hand_brake: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.hand_brake);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSI_ROVER_MESSAGE_NAVIGATIONDIRECTIVES_H
