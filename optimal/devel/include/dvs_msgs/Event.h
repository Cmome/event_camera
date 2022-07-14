// Generated by gencpp from file dvs_msgs/Event.msg
// DO NOT EDIT!


#ifndef DVS_MSGS_MESSAGE_EVENT_H
#define DVS_MSGS_MESSAGE_EVENT_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace dvs_msgs
{
template <class ContainerAllocator>
struct Event_
{
  typedef Event_<ContainerAllocator> Type;

  Event_()
    : x(0)
    , y(0)
    , ts()
    , polarity(false)  {
    }
  Event_(const ContainerAllocator& _alloc)
    : x(0)
    , y(0)
    , ts()
    , polarity(false)  {
  (void)_alloc;
    }



   typedef uint16_t _x_type;
  _x_type x;

   typedef uint16_t _y_type;
  _y_type y;

   typedef ros::Time _ts_type;
  _ts_type ts;

   typedef uint8_t _polarity_type;
  _polarity_type polarity;





  typedef boost::shared_ptr< ::dvs_msgs::Event_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::dvs_msgs::Event_<ContainerAllocator> const> ConstPtr;

}; // struct Event_

typedef ::dvs_msgs::Event_<std::allocator<void> > Event;

typedef boost::shared_ptr< ::dvs_msgs::Event > EventPtr;
typedef boost::shared_ptr< ::dvs_msgs::Event const> EventConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::dvs_msgs::Event_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::dvs_msgs::Event_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace dvs_msgs

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'dvs_msgs': ['/media/sp/lx/ubuntu/optimal/src/dvs_msgs/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::dvs_msgs::Event_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::dvs_msgs::Event_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dvs_msgs::Event_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::dvs_msgs::Event_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dvs_msgs::Event_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::dvs_msgs::Event_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::dvs_msgs::Event_<ContainerAllocator> >
{
  static const char* value()
  {
    return "40d339b261445b8ce9a6fef01267cd5d";
  }

  static const char* value(const ::dvs_msgs::Event_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x40d339b261445b8cULL;
  static const uint64_t static_value2 = 0xe9a6fef01267cd5dULL;
};

template<class ContainerAllocator>
struct DataType< ::dvs_msgs::Event_<ContainerAllocator> >
{
  static const char* value()
  {
    return "dvs_msgs/Event";
  }

  static const char* value(const ::dvs_msgs::Event_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::dvs_msgs::Event_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# A DVS event\n\
uint16 x\n\
uint16 y\n\
time ts\n\
bool polarity\n\
";
  }

  static const char* value(const ::dvs_msgs::Event_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::dvs_msgs::Event_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.ts);
      stream.next(m.polarity);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Event_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::dvs_msgs::Event_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::dvs_msgs::Event_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.y);
    s << indent << "ts: ";
    Printer<ros::Time>::stream(s, indent + "  ", v.ts);
    s << indent << "polarity: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.polarity);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DVS_MSGS_MESSAGE_EVENT_H
