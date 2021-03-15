// Generated by gencpp from file nuscenes2bag/RadarObjects.msg
// DO NOT EDIT!


#ifndef NUSCENES2BAG_MESSAGE_RADAROBJECTS_H
#define NUSCENES2BAG_MESSAGE_RADAROBJECTS_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <nuscenes2bag/RadarObject.h>

namespace nuscenes2bag
{
template <class ContainerAllocator>
struct RadarObjects_
{
  typedef RadarObjects_<ContainerAllocator> Type;

  RadarObjects_()
    : header()
    , objects()  {
    }
  RadarObjects_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , objects(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::nuscenes2bag::RadarObject_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::nuscenes2bag::RadarObject_<ContainerAllocator> >::other >  _objects_type;
  _objects_type objects;





  typedef boost::shared_ptr< ::nuscenes2bag::RadarObjects_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::nuscenes2bag::RadarObjects_<ContainerAllocator> const> ConstPtr;

}; // struct RadarObjects_

typedef ::nuscenes2bag::RadarObjects_<std::allocator<void> > RadarObjects;

typedef boost::shared_ptr< ::nuscenes2bag::RadarObjects > RadarObjectsPtr;
typedef boost::shared_ptr< ::nuscenes2bag::RadarObjects const> RadarObjectsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::nuscenes2bag::RadarObjects_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace nuscenes2bag

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'nav_msgs': ['/opt/ros/kinetic/share/nav_msgs/cmake/../msg'], 'nuscenes2bag': ['/home/sundong/bit_ivrc/Radar-Camera-Fusion/Dataset/nuscenes2bag/src/nuscenes2bag_cpp/msg'], 'sensor_msgs': ['/opt/ros/kinetic/share/sensor_msgs/cmake/../msg'], 'actionlib_msgs': ['/opt/ros/kinetic/share/actionlib_msgs/cmake/../msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/kinetic/share/geometry_msgs/cmake/../msg'], 'tf': ['/opt/ros/kinetic/share/tf/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::nuscenes2bag::RadarObjects_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::nuscenes2bag::RadarObjects_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::nuscenes2bag::RadarObjects_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c69401412379392af20b5a4c32b76eca";
  }

  static const char* value(const ::nuscenes2bag::RadarObjects_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc69401412379392aULL;
  static const uint64_t static_value2 = 0xf20b5a4c32b76ecaULL;
};

template<class ContainerAllocator>
struct DataType< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
{
  static const char* value()
  {
    return "nuscenes2bag/RadarObjects";
  }

  static const char* value(const ::nuscenes2bag::RadarObjects_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
{
  static const char* value()
  {
    return "std_msgs/Header header\n\
RadarObject[] objects\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: nuscenes2bag/RadarObject\n\
geometry_msgs/Vector3 pose\n\
uint8 dyn_prop\n\
uint16 id\n\
float32 rcs\n\
float32 vx\n\
float32 vy\n\
float32 vx_comp\n\
float32 vy_comp\n\
uint8 is_quality_valid\n\
uint8 ambig_state\n\
uint8 x_rms\n\
uint8 y_rms\n\
uint8 invalid_state\n\
uint8 pdh0\n\
uint8 vx_rms\n\
uint8 vy_rms\n\
================================================================================\n\
MSG: geometry_msgs/Vector3\n\
# This represents a vector in free space. \n\
# It is only meant to represent a direction. Therefore, it does not\n\
# make sense to apply a translation to it (e.g., when applying a \n\
# generic rigid transformation to a Vector3, tf2 will only apply the\n\
# rotation). If you want your data to be translatable too, use the\n\
# geometry_msgs/Point message instead.\n\
\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::nuscenes2bag::RadarObjects_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.objects);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarObjects_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::nuscenes2bag::RadarObjects_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::nuscenes2bag::RadarObjects_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "objects[]" << std::endl;
    for (size_t i = 0; i < v.objects.size(); ++i)
    {
      s << indent << "  objects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::nuscenes2bag::RadarObject_<ContainerAllocator> >::stream(s, indent + "    ", v.objects[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // NUSCENES2BAG_MESSAGE_RADAROBJECTS_H
