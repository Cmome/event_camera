#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
#include <vector>
#include <ctime>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "dvs_msgs/Event.h"
#include "dvs_msgs/EventArray.h"

using namespace std;
using namespace ros;

typedef long int lint;
typedef long long int sll;
typedef unsigned int uint;
typedef unsigned long int ulong;
typedef unsigned long long int ull;
   int j=0;
   double   hx,hy,r;
   //float hx,hy,r; 
   float e_T,e_TY,e_X,e_TX,e_Y;
   float sum_T=0, sum_TY=0, sum_X=0;
   float sum_TX=0, sum_Y=0;
   vector<float> A,B,C;
   vector<float> deltaT;
   float a,b,c;
   float t;
   float ax=0 ,bx=0 ,cx=0,ay=0,by=0,cy=0;
   float ar=0,br=0,cr=0,dr=0;
   vector<dvs_msgs::Event> events_buffer;
   vector<dvs_msgs::Event> events_buffers;
  // dvs_msgs::EventArray events_buffer;


  

// Camera resolution
#define RES_X 260
#define RES_Y 346
 dvs_msgs::Event e;
 int event_size_ = 0;
//void EventsCallback(const dvs_msgs::EventArray::ConstPtr &emsg);
void read();
void eventCallback(const dvs_msgs::EventArray::ConstPtr& msg);
std::vector<dvs_msgs::Event> events_buffer_;
void eventprocess(const vector<dvs_msgs::Event>& events_buffer);
void eventpublisher();

#endif
