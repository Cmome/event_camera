#include "optimal_event/contrast_max.h"


void  contrast::EventsCallback(const dvs_msgs::EventArray::ConstPtr &emsg)
 {
  events_buffer_.assign(emsg->events.begin(), emsg->events.end());
  event_size_ = events_buffer_.size();
}

void cost_function(double hx, double hy,double hz,double rot)
{
    auto t0 = events_buffer_[0].ts;
    float prevDeltaT = 0.0f;

     for (int i = 0; i < event_size_; i++) {
    dvs_msgs::Event e = events_buffer_[i];
    float deltaT = (e.ts - t0).toSec();
    
      prevDeltaT = deltaT;
      rotation_vector = omega_avg_ * deltaT;
      rot_skew_mat = vectorToSkewMat(rotation_vector);
      rotation_matrix_ = rot_skew_mat.exp();  // vector space to Lee spin space
      rot_K = K * rotation_matrix_.transpose() * K_inverse;  // projection
    }

}














