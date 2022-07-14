/**  contrast_max.h  
 * 
 * 
*/
#ifndef CONTRAST_MAX_H
#define CONTRAST_MAX_H
  
#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/Dense>
#include <eigen3/Eigen/Geometry>
#include <eigen3/unsupported/Eigen/MatrixFunctions>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <opencv2/opencv.hpp>
 #include "ros/ros.h"
#include "dvs_msgs/Event.h"
#include "optimal_event/common.h"


using std::vector;
using namespace std;
using namespace cv;
using namespace Eigen;


class contrast_max {
private:
   

  



public:


    vector<dvs_msgs::Event> events_buffer_;
         

   int event_size_;

   double hx,hy,hz,rot;
    void LoadEvents(const dvs_msgs::EventArray::ConstPtr &emsg);
    void EventsCallback(const dvs_msgs::EventArray::ConstPtr &emsg);
    void cost_function(double hx, double hy,double hz,double rot);
  
};



#endif









