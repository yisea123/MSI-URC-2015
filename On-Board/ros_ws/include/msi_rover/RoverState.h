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
 * Auto-generated by genmsg_cpp from file /home/singularity/git/MSI-URC-2015/On-Board/ros_ws/src/msi_rover/msg/RoverState.msg
 *
 */


#ifndef MSI_ROVER_MESSAGE_ROVERSTATE_H
#define MSI_ROVER_MESSAGE_ROVERSTATE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Point.h>
#include <msi_rover/attitude.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Point.h>

namespace msi_rover
{
template <class ContainerAllocator>
struct RoverState_
{
  typedef RoverState_<ContainerAllocator> Type;

  RoverState_()
    : position()
    , attitude()
    , lin_velocity()
    , ang_velocity()  {
    }
  RoverState_(const ContainerAllocator& _alloc)
    : position(_alloc)
    , attitude(_alloc)
    , lin_velocity(_alloc)
    , ang_velocity(_alloc)  {
    }



   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _position_type;
  _position_type position;

   typedef  ::msi_rover::attitude_<ContainerAllocator>  _attitude_type;
  _attitude_type attitude;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _lin_velocity_type;
  _lin_velocity_type lin_velocity;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _ang_velocity_type;
  _ang_velocity_type ang_velocity;




  typedef boost::shared_ptr< ::msi_rover::RoverState_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::msi_rover::RoverState_<ContainerAllocator> const> ConstPtr;

}; // struct RoverState_

typedef ::msi_rover::RoverState_<std::allocator<void> > RoverState;

typedef boost::shared_ptr< ::msi_rover::RoverState > RoverStatePtr;
typedef boost::shared_ptr< ::msi_rover::RoverState const> RoverStateConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::msi_rover::RoverState_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::msi_rover::RoverState_<ContainerAllocator> >::stream(s, "", v);
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
struct IsFixedSize< ::msi_rover::RoverState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::msi_rover::RoverState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msi_rover::RoverState_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::msi_rover::RoverState_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msi_rover::RoverState_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::msi_rover::RoverState_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::msi_rover::RoverState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "48cdb77a2d78b0e48773a1c7dce86f29";
  }

  static const char* value(const ::msi_rover::RoverState_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x48cdb77a2d78b0e4ULL;
  static const uint64_t static_value2 = 0x8773a1c7dce86f29ULL;
};

template<class ContainerAllocator>
struct DataType< ::msi_rover::RoverState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "msi_rover/RoverState";
  }

  static const char* value(const ::msi_rover::RoverState_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::msi_rover::RoverState_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/Point    position\n\
msi_rover/attitude     attitude\n\
geometry_msgs/Point    lin_velocity\n\
geometry_msgs/Point    ang_velocity\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
\n\
================================================================================\n\
MSG: msi_rover/attitude\n\
float32 roll\n\
float32 pitch\n\
float32 yaw\n\
";
  }

  static const char* value(const ::msi_rover::RoverState_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::msi_rover::RoverState_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.position);
      stream.next(m.attitude);
      stream.next(m.lin_velocity);
      stream.next(m.ang_velocity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER;
  }; // struct RoverState_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::msi_rover::RoverState_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::msi_rover::RoverState_<ContainerAllocator>& v)
  {
    s << indent << "position: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
    s << indent << "attitude: ";
    s << std::endl;
    Printer< ::msi_rover::attitude_<ContainerAllocator> >::stream(s, indent + "  ", v.attitude);
    s << indent << "lin_velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.lin_velocity);
    s << indent << "ang_velocity: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.ang_velocity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MSI_ROVER_MESSAGE_ROVERSTATE_H
