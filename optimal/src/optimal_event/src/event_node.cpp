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
     /**
     float start_timestamp = msg->events[0].ts.toSec();
    // for (int i = 0; i < msg->events.size(); ++i) 
     int  i = msg->events.size();
     float time = msg->events[i].ts.toSec() - start_timestamp;
       // e(msg->events[i].y, msg->events[i].x, time, (msg->events[i].polarity ? 1 : 0));
      //  ev_buffer.push_back(e);
       
     cout << "dt=" << time << "   " << "START="<< start_timestamp << "   " << "i=" << i << endl; 
**/
   double hx,hy,r; 
   float e_T,e_TY,e_X,e_TX,e_Y;
   float sum_T=0, sum_TY=0, sum_X=0;
   float sum_TX=0, sum_Y=0;
   vector<float> A,B,C;
   vector<float> deltaT;
   float a,b,c;
   float t;
   float ax ,bx ,cx,ay,by,cy;
   float ar,br,cr,dr;
   events_buffer_.assign(msg->events.begin(), msg->events.end());
   event_size_ = events_buffer_.size();
    ull t0 = events_buffer_[0].ts.toNSec();
    /**
    for (int i=0; i<event_size_;i++)
      {  deltaT[i]= events_buffer_[i].ts.toSec() - t0;
         sum_T+=deltaT[i];  
       }
    e_T= sum_T / event_size_;
    for (int i=0; i<event_size_;i++)
      {  // deltaT= events_buffer_[i].ts.toSec() - t0;
          a[i]= e_T - deltaT[i];
          ax= 2*pow((a[i]),2)/event_size_;  // 计算hx系数
       }
    for (int i=0; i<event_size_;i++)
      {   //deltaT= events_buffer_[i].ts.toSec() - t0;
          sum_TY+= deltaT[i]*events_buffer_[i].y;  
       }
    e_TY=sum_TY/event_size_;
    for (int i=0; i<event_size_;i++)
      { 
         int iy = events_buffer_[i].y;
         bx= 2*(deltaT[i]*iy*a[i]-a[i]*e_TY)/event_size_; //计算theta系数
       }
    for (int i=0; i<event_size_;i++)
      {   
          sum_X+= events_buffer_[i].x;  
       }
     e_X=sum_X/event_size_;
    for (int i=0; i<event_size_;i++)
      {   int ix = events_buffer_[i].x;
          cx=2*(ix*a[i]-a[i]*e_X)/event_size_;  //计算常数c
       }  

    for (int i=0; i<event_size_;i++)
      {  deltaT[i]= (events_buffer_[i].ts.toSec() - t0) / 100000.0;
         sum_T+=deltaT[i];  
         sum_TY+= deltaT[i]*events_buffer_[i].y;
         sum_X+= events_buffer_[i].x;
       }
      e_T= sum_T / event_size_;
      e_TY=sum_TY/event_size_;
      e_X=sum_X/event_size_;
    for (int i=0; i<event_size_;i++)
      {   int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          a[i]= e_T - deltaT[i];
          ax= 2*pow((a[i]),2)/event_size_;  // 计算hx系数
          bx= 2*(deltaT[i]*iy*a[i]-a[i]*e_TY)/event_size_; //计算theta系数
          cx=2*(ix*a[i]-a[i]*e_X)/event_size_;  //计算常数c
       }

       


     for (int i=0; i<event_size_;i++)
      {  deltaT[i]= (events_buffer_[i].ts.toSec() - t0) / 1000000.0; 
         sum_TX+= deltaT[i]*events_buffer_[i].x;
         sum_Y+= events_buffer_[i].y;
       }
      e_TX=sum_TX/event_size_;
      e_Y=sum_Y/event_size_;
    for (int i=0; i<event_size_;i++)
      {   int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          a[i]= e_T - deltaT[i];
          ay= ax;  // 计算hy系数
          by= 2*(deltaT[i]*ix*a[i]-a[i]*e_TX)/event_size_; //计算theta系数
          cy=2*(iy*a[i]-a[i]*e_Y)/event_size_;  //计算常数c
       }


    for (int i=0; i<event_size_;i++)
      {   deltaT[i]= (events_buffer_[i].ts.toSec() - t0 ) / 1000000.0;
          int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          b[i]=deltaT[i]*iy - e_TY ;
          c[i]=deltaT[i]*ix + e_TX;
       }
    
    for (int i=0; i<event_size_;i++)
      {   deltaT[i]= (events_buffer_[i].ts.toSec() - t0) / 1000000.0;
          int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          ar=2*(b[i]*e_T - deltaT[i]*b[i])/event_size_;
          br=2*(c[i]*e_T - deltaT[i]*c[i])/event_size_;
          cr=2*(deltaT[i]*b[i]*iy - deltaT[i]*c[i]*ix - b[i]*e_TY + c[i]*e_TX )/event_size_;
          dr=2*(b[i]*ix + c[i]*iy - b[i]*e_X - c[i]*e_Y)/event_size_;
       }

     hx= (-bx/ax)*(ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax) - (cx/ax);
     hy= (-by/ay)*(ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax) - (cy/ay);
     r = (ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax);
     std::cout << hx << std::endl;

**/

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/** 
 hx偏导系数
**/
    for (int i=0; i<event_size_;i++)
      {  t= (events_buffer_[i].ts.toNSec() - t0) / 100000.0;
         deltaT.push_back(t);
         sum_T+=t;  
         sum_TY+= t*events_buffer_[i].y;
         sum_X+= events_buffer_[i].x;
       }
      e_T= sum_T / event_size_;
      e_TY=sum_TY/event_size_;
      e_X=sum_X/event_size_;
    for (int i=0; i<event_size_;i++)
      {   int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          a= e_T - deltaT[i];
          A.push_back(a);
          ax+= pow(a,2);  // 计算hx系数
          bx+= deltaT[i]*iy*a-a*e_TY; //计算theta系数
          cx+=ix*a-a*e_X;  //计算常数c
       }
       ax = 2*ax / event_size_;
       bx = 2*bx / event_size_;
       cx = 2*cx / event_size_;
       float hx1= cx /ax ;
       cout << hx1 << endl;
       
/** 
 hy偏导系数
**/

     for (int i=0; i<event_size_;i++)
      {  
         sum_TX+= deltaT[i]*events_buffer_[i].x;
         sum_Y+= events_buffer_[i].y;
       }
      e_TX=sum_TX/event_size_;
      e_Y=sum_Y/event_size_;
    for (int i=0; i<event_size_;i++)
      {   int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
         
          by+= deltaT[i]*ix*A[i]-A[i]*e_TX; //计算theta系数
          cy+=iy*A[i]-A[i]*e_Y;  //计算常数c
       }
        ay= ax;  // 计算hy系数
        by  = 2*by / event_size_;
        cy  = 2*cy / event_size_;
       // float hy1 = cy / ay;
        //cout << hy1 << endl;
/** 
 theta偏导系数
**/

    for (int i=0; i<event_size_;i++)
      {  
          int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          b=deltaT[i]*iy - e_TY ;
          B.push_back(b);
          c=deltaT[i]*ix + e_TX;
          C.push_back(c);
       }
    
    for (int i=0; i<event_size_;i++)
      {   
          int ix = events_buffer_[i].x;
          int iy = events_buffer_[i].y;
          ar+=B[i]*e_T - deltaT[i]*B[i];
          br+=C[i]*e_T - deltaT[i]*C[i];
          cr+=deltaT[i]*B[i]*iy - deltaT[i]*C[i]*ix - B[i]*e_TY + C[i]*e_TX ;
          dr==B[i]*ix + C[i]*iy - B[i]*e_X - C[i]*e_Y;
       }
       ar = 2*ar / event_size_;
       br = 2*br / event_size_;
       cr = 2*cr / event_size_;
       dr = 2*dr / event_size_;



     hx= (-bx/ax)*(ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax) - (cx/ax);
     hy= (-by/ay)*(ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax) - (cy/ay);
     r = (ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax); 
   //  float r1=ar*cx*ay+br*cy*ax-dr*ax*ay;
   //  float r2=cr*ax*ay-ar*bx*ay-br*by*ax;
   //  double r3=r1/r2;
    // cout <<  "r1=" << r1 <<"   " << "r2=" << r2  << "  " << "r3=" << r3 <<endl ;
   //  std::cout << "hx=" << hx << "  " << "hy=" << hy << "  " << "r=" << r   << std::endl;
     
     events_buffer_.clear();
     A.clear();
     B.clear();
     C.clear();
     deltaT.clear(); 
   
}

int main(int argc, char **argv){

	ros::init(argc, argv, "event_node");
	ros::NodeHandle nh;

    ros::Subscriber subEvent = nh.subscribe("dvs/events", 10, eventCallback);

    ros::spin();
    
    return 0;
}


