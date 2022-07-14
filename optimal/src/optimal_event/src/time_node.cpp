#include "optimal_event/common.h"

void EventsCallback(const dvs_msgs::EventArray::ConstPtr& msg)
{
  uint x,y;
  uint ts;
  bool polarity;

    x=msg->x;
    y=msg->y;
    ts=msg->ts.toSec();
    polarity=msg->polarity;
    ROS_INFO("I heard: [%s]", x);

}


int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "subscribe");
 
 
  ros::NodeHandle n;
 
 
  ros::Subscriber sub = n.subscribe("/dvs/events", 1, EventsCallback);
 

  ros::spin();

  return 0;
}
