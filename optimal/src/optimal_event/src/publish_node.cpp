#include <stdio.h>
#include "ros/ros.h"
#include "dvs_msgs/Event.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "dvs_msgs/EventArray.h"


int main(int argc, char *argv[])
{    ros::init(argc, argv, "talker");
     ros::NodeHandle n;
     ros::Publisher pub = n.advertise<dvs_msgs::EventArray>("dvs/events", 1000);
     ros::Rate loopRate(10);
    
  while (ros::ok())
   {
    
    std::string filename;
    std::string file_;
    file_.append(filename);
    file_.append("/media/sp/lx/ubuntu/optimal/src/optimal_event/config/events1.txt");

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
            dvs_msgs::EventArrayPtr event_array_msg(new dvs_msgs::EventArray());
            event_array_msg->height =346;
            event_array_msg->width = 260;
            dvs_msgs::Event e;
            std::stringstream ss(line);
            while (ss>>token)
                vToken.push_back(token);

              if (vToken.size() == 4)
              {
                e.ts = ros::Time(std::strtod(vToken[0].c_str(), &sz));
                e.x = uint16_t(std::strtod(vToken[1].c_str(), &sz));
                e.y = uint16_t(std::strtod(vToken[2].c_str(), &sz));
                e.polarity = uint8_t(std::strtod(vToken[3].c_str(), &sz));
                event_array_msg->events.push_back(e);
              }
              else {
                std::cout << "t error=" << vToken.size() << "t=" << token << "s=" << line << std::endl;
              }

            pub.publish(event_array_msg);
            ros::spinOnce();
            loopRate.sleep();
            event_array_msg->events.clear();
            vToken.clear();
           
        }
       
        openFile.close();
    }
       
   }
    
    
    return 0;
}