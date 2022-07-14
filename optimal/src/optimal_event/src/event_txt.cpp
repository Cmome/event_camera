#include <stdio.h>
#include "ros/ros.h"
#include "dvs_msgs/Event.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "dvs_msgs/EventArray.h"
#include "optimal_event/common.h"

using namespace std;
int main ()
{  
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
    std::string file_;
    file_.append("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/event.txt");
    std::ifstream openFile(file_.c_str());
    if (!openFile.is_open())
    {
        std::cout << "text file open error" << std::endl;
    }
    else
    {
        std::string line;
        std::string token;
        std::vector<std::string> vToken;
        char *sz;

        while (getline(openFile, line))
        {
            dvs_msgs::Event msg;
            std::stringstream ss(line);
            while (getline(ss, token,' '))
            {
               // cout << token <<endl;
                vToken.push_back(token);
                //cout << vToken.size() << endl;
            }
            if (vToken.size() == 4)
            {
                msg.ts = ros::Time(std::strtod(vToken[0].c_str(), &sz));
                msg.x = uint16_t(std::strtod(vToken[1].c_str(), &sz));
                msg.y = uint16_t(std::strtod(vToken[2].c_str(), &sz));
                msg.polarity = uint8_t(std::strtod(vToken[3].c_str(), &sz));
               // cout << msg.ts << endl;
                events_buffer.push_back(msg);
            }
            else{cout << "error" << endl;}
          //  cout << events_buffer[i].ts << endl;

            vToken.clear();

        }

        openFile.close();

    }

 //events_buffer_.assign(msg->events.begin(), msg->events.end());
   event_size_ = events_buffer.size();
    float t0 = events_buffer[0].ts.toSec();
    // cout << t0 << endl;
    // t= events_buffer[1].ts.toSec();
    // float t1= t - t0;
   // cout << t <<endl;
    for (int i=0; i<event_size_;++i)
      {  t= events_buffer[i].ts.toSec() - t0;
        // cout << t << endl;
         deltaT.push_back(t);
         sum_T+=t;  
         sum_TY+= t*events_buffer[i].y;
         sum_X+= events_buffer[i].x;
       }
   //    cout << sum_T << " " << sum_TY << " " << sum_X << endl;
      e_T= sum_T / event_size_;
      e_TY=sum_TY/event_size_;
      e_X=sum_X/event_size_;
    //  cout << e_T << " " << e_TY << " " << e_X <<endl;
      
    for (int i=0; i<event_size_;++i)
      {   int ix = events_buffer[i].x;
          int iy = events_buffer[i].y;
          a= e_T - deltaT[i];
          A.push_back(a);
          ax+= pow(a,2);  // 计算hx系数
        //  cout << a << ax <<endl;
          bx+= deltaT[i]*iy*a-a*e_TY; //计算theta系数
          cx+=ix*a-a*e_X;  //计算常数c
       }
   //    cout << ax << bx << cx <<endl;
       ax = 2*ax / event_size_;
       bx = 2*bx / event_size_;
       cx = 2*cx / event_size_;
      // cout << ax << bx << cx <<endl;
       
       float hx1= -(cx /ax) ;
       float hx2= -bx/ax;
       cout << "hx1=" << hx1 << "hx2=" << hx2  << endl;   

      
     for (int i=0; i<event_size_;++i)
      {  
         sum_TX+= deltaT[i]*events_buffer[i].x;
         sum_Y+= events_buffer[i].y;
       }
      e_TX=sum_TX/event_size_;
      e_Y=sum_Y/event_size_;
    for (int i=0; i<event_size_;++i)
      {   int ix = events_buffer[i].x;
          int iy = events_buffer[i].y;
         
          by+= deltaT[i]*ix*A[i]-A[i]*e_TX; //计算theta系数
          cy+=iy*A[i]-A[i]*e_Y;  //计算常数c
       }
        ay= ax;  // 计算hy系数
        by  = 2*by / event_size_;
        cy  = 2*cy / event_size_;

        float hy1 = -(cy / ay);
        float hy2 = -by/ay ;
        cout << "hy1=" << hy1 << "hy2=" << hy2 << endl;


        for (int i=0; i<event_size_;++i)
      {  
          int ix = events_buffer[i].x;
          int iy = events_buffer[i].y;
          b=deltaT[i]*iy - e_TY ;
          B.push_back(b);
          c=deltaT[i]*ix + e_TX;
          C.push_back(c);
        //  cout << "b=" << b << "c=" << c <<endl;
       }
    
    for (int i=0; i<event_size_;++i)
      {   
          int ix = events_buffer[i].x;
          int iy = events_buffer[i].y;
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
     
       cout << "hx=" << hx << "  " << "hy=" << hy << "  " << "r=" << r   << std::endl;
         A.clear();
         B.clear();
         C.clear();
         deltaT.clear();
         events_buffer.clear(); 
        

     return 0; 

}































 /**
    int count=events_buffer.size();
         for (int i=0; i<count;i++)
         {
        
           cout << events_buffer[i].ts << endl;

         }
 **/



 
