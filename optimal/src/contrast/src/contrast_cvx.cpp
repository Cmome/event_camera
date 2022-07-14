#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <cstring>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace std;
using namespace cv;

//int e[10][3]={0};
int main ()
{   
    int e_[10][2];
    int i,j,a,b;
    int k=1;
    int x=0;
    int sum;
   // float f;
   // float f_=0;
    float f_m=0;
    cv::Scalar mean;
    cv::Scalar stddev;
     int e[10][3]={    { 2,1,0 },
                       { 2,7,1 },
                       { 2,13,2 },
                       { 2,19,3 },
                       { 2,25,4 },
                       { 2,31,5 },
                       { 2,37,6 },
                       { 2,43,7 },
                       { 2,49,8 },
                       { 2,55,9 },
    };  
   /** for (i=0;i<10;i++){
       e[i][0]=2;
       e[i][1]=k;
       k+=6;
       e[i][2]++;
    }  **/
    
    while(1)  {
      cv::Mat count_event=cv::Mat::zeros(346,260,CV_8UC1);
   // cv::imshow("event",count_event);
   // cv::waitKey();
   
     for (i=0;i<10;i++)
        {  
                     e_[i][0]=2;
                     e_[i][1]=e[i][1]-x*e[i][2];
                    //cout<<e[j][1]<<e[j][2]<<endl;
                    //cout << e_[j][1] << e_[j][0] <<endl; 
                     a=e_[i][0];
                     b=e_[i][1];
                      // cout <<a <<b <<endl;
                     if(a<0&&a>=346&&b<0&&b>=260){
                        continue;
                     }
                     else {
                     count_event.at<int>(a,b)++;
                   //  sum++;
                    // count_event.at<int>(a,b)=sum;
                     }
        } 
     /**for(i=0;i<50;i++)
        {   for (j=0;j<50;j++)
             {
            count_event.at<int>(i,j)=255;

             }

        }  **/

         cv::meanStdDev ( count_event, mean, stddev );
        // cv::Mat count_event=cv::Mat::zeros(346,260,CV_8UC1);
         //cv::imshow("event",count_event);
         std::cout<<"<----mean_pxl------>"<< mean[0] <<"<-------stddev_pxl------->"<< stddev[0] <<std::endl;
         //cv::waitKey();
         if(stddev[0]>=f_m){
            f_m=stddev[0];
            x++;
         }
          else{

              break;
          }
        
   }
   x=x-1;
      
     cout << x <<endl;  
    return 0;




} 
