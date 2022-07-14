
#include "optimal_event/common.h"



void eventCallback(const dvs_msgs::EventArray::ConstPtr& msg){
  

 events_buffer_.assign(msg->events.begin(), msg->events.end());
   event_size_ = events_buffer_.size();
    ull t0 = events_buffer_[0].ts.toNSec();
/** 
 hx偏导系数
**/
    for (int i=0; i<event_size_;i++)
      {  t= (events_buffer_[i].ts.toNSec() - t0) / 1000000000.0;
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
  /**     
       float hx1= -(cx /ax) ;
       cout << "hx1=" << hx1  << endl; 
       ofstream outfile;    //定义输出流对象
        outfile.open("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/hx1.txt",ofstream::app);    //打开文件
        outfile  << "hx1=" << hx1  << endl;
        outfile.close();    //关闭文件
        **/
       
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
/**

        float hy1 = -(cy / ay);
        ofstream outfile1;    //定义输出流对象
        outfile1.open("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/hy1.txt",ofstream::app);    //打开文件
        outfile1  << "hy1=" << hy1  << endl;
        outfile1.close();    //关闭文件
        **/
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
          dr+=B[i]*ix + C[i]*iy - B[i]*e_X - C[i]*e_Y;
       }
       ar = 2*ar / event_size_;
       br = 2*br / event_size_;
       cr = 2*cr / event_size_;
       dr = 2*dr / event_size_;



     hx= (-bx/ax)*(ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax) - (cx/ax);
     hy= (-by/ay)*(ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax) - (cy/ay);
     r = (ar*cx*ay+br*cy*ax-dr*ax*ay)/(cr*ax*ay-ar*bx*ay-br*by*ax); 
     
      // std::cout << "hx=" << hx << "  " << "hy=" << hy << "  " << "r=" << r   << std::endl;
     ofstream outfile;    
      outfile.open("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/out.txt",ofstream::app);    
      //outfile.open("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/out1.txt",ofstream::app);    
      if (!outfile)
      {
      	cout << "打开文件失败" << endl;
           	exit(1);
            }
        outfile  << "hx=" << hx << "  " << "hy=" << hy << "  " << "r=" << r  << endl;
        outfile.close();     
       
   //  float r1=ar*cx*ay+br*cy*ax-dr*ax*ay;
   //  float r2=cr*ax*ay-ar*bx*ay-br*by*ax;
   //  double r3=r1/r2;
    // cout <<  "r1=" << r1 <<"   " << "r2=" << r2  << "  " << "r3=" << r3 <<endl ;
   
     
     events_buffer_.clear();
     A.clear();
     B.clear();
     C.clear();
     deltaT.clear(); 
}
 

int main(int argc, char **argv){

	ros::init(argc, argv, "event_node");
	ros::NodeHandle nh;
  //ros::Rate loop_rate(40);
  //  while (ros::ok()) {
    ros::Subscriber subEvent = nh.subscribe("cam0/events", 10000, eventCallback);
    //ros::Subscriber subEvent = nh.subscribe("dvs/events", 10000, eventCallback);
    //ros::Timer timer1=nh.createTimer(ros::Duration(0.02),eventCallback);
    //loop_rate.sleep();
    ros::spin();
  //  }
    
    return 0;
}



