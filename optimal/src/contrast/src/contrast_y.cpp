#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cmath>
#include <memory>
#include <cstring>
using namespace std;


int count[10][10]={0};
int main()
{   
    int e_[10][2];
    
    int i,j,a,b;
    int x=0;
    int sum=0;
    float f;
    float f_=0;
    float f_m=0;

     int e[10][3]={ { 2,1,0 },
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
/**
     for (i=0;i<10;i++)
     {  
       e_[i][0]=2;
       e_[i][1]=e[i][1]-x*e[i][2];
       //cout<<e[j][1]<<e[j][2]<<endl;
        //cout << e_[j][1] << e_[j][0] <<endl; 
       a=e_[i][0];
       b=e_[i][1];
      // cout <<a <<b <<endl;
       count[a][b]++;
       //cout << count[a][b]<<endl;
        
     } 
  for (i=1;i<11;i++){
       for (j=1;j<11;j++){
        // cout << i << j <<endl;
        cout << count[i][j]<<endl;

       }
     } 
**/
/**
   for (i=1;i<11;i++){
       for (j=1;j<11;j++){
        sum+=count[i][j];

       }
     } 
   cout << sum <<endl;
      for (i=1;i<11;i++){
       for (j=1;j<11;j++){
        f=pow((count[i][j]-sum/100),2);

        f_=f_+f;
       }
     } 
     cout << f_ <<endl;
     memset(count,0,sizeof(count));
     cout << count[2][1]<<endl;

**/
        while(1)
        {
           for (i=0;i<10;i++)
                {  
                     e_[i][0]=2;
                     e_[i][1]=e[i][1]-x*e[i][2];
                    //cout<<e[j][1]<<e[j][2]<<endl;
                    //cout << e_[j][1] << e_[j][0] <<endl; 
                     a=abs(e_[i][0]);
                     b=abs(e_[i][1]);
                     // cout <<a <<b <<endl;
                     count[a][b]++;
                     //cout << count[a][b]<<endl;
                 } 
           for (i=0;i<10;i++)
             {
               for (j=0;j<10;j++)
               {
                sum+=count[i][j];
                }
              } 
           //cout << sum <<endl;
          for (i=0;i<10;i++)
             {
               for (j=0;j<10;j++)
               {
                f=pow((count[i][j]-sum/100),2)/100;

                 f_=f_+f;
                }
              } 
          //cout << f_ <<endl;
          sum=0;
          memset(count,0,sizeof(count));
        // cout << count[2][1]<<endl;
        
           if (f_>=f_m) 
           {
             f_m=f_;
             x++;
            
            }   
            else
            { break;
            }

      }
         
        
       cout<< "x="<< x <<endl;
       return 0;


   }
    






