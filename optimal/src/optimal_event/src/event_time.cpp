#include <iostream>

#include <ros/ros.h>


#include <dvs_msgs/EventArray.h>

#include <opencv2/opencv.hpp>
#include "optimal_event/common.h"

using namespace std;
using namespace cv;

#define WIDTH 346
#define HEIGHT 260


void eventCallback(const dvs_msgs::EventArray::ConstPtr& msg){
    double   hx,hy,r;
   //float hx,hy,r; 
   float e_T,e_TY,e_X,e_TX,e_Y;
   float sum_T=0, sum_TY=0, sum_X=0;
   float sum_TX=0, sum_Y=0;
   vector<float> A,B,C;
   vector<float> deltaT;
   float a,b,c;
   double t;
   float ax ,bx ,cx,ay,by,cy;
   float ar,br,cr,dr;

 events_buffer_.assign(msg->events.begin(), msg->events.end());
   event_size_ = events_buffer_.size();
    //ull t0 = events_buffer_[0].ts.toNSec();
   // double t00= t0/ 1000000000.0;

     ofstream outfile;    
     // outfile.open("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/out.txt",ofstream::app);    
      outfile.open("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/time.txt",ofstream::app);    
      if (!outfile)
      {
      	cout << "打开文件失败" << endl;
           	exit(1);
            }

    for (int i=0; i<event_size_;i++)
      {  t= events_buffer_[i].ts.toNSec()*1.0 / 1000000000.0;
         int ix=events_buffer_[i].x;
         int iy=events_buffer_[i].y;
         int p=events_buffer_[i].polarity;     
         outfile  << t << "  " << ix << " " << iy << " " << p   <<endl;

       }
        outfile  << "timing" << endl;

        outfile.close();

              
      events_buffer_.clear();
  
}
 

int main(int argc, char **argv){

	ros::init(argc, argv, "event_node");
	ros::NodeHandle nh;
  //ros::Rate loop_rate(40);
   // while (ros::ok()) {
    //ros::Subscriber subEvent = nh.subscribe("cam0/events", 10000, eventCallback);
    ros::Subscriber subEvent = nh.subscribe("cam0/events", 10000, eventCallback);
    //ros::Timer timer1=nh.createTimer(ros::Duration(0dvs_msgs::EventArrayPtr.02),eventCallback);
    //loop_rate.sleep();
    ros::spin();
   // }
    
    return 0;
}



