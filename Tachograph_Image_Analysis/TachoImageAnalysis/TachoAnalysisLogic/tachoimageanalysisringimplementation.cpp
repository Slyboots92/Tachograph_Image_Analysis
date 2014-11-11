#include "tachoimageanalysisringimplementation.h"

TachoImageAnalysisRingImplementation::TachoImageAnalysisRingImplementation()
{
}

std::vector<TachoActivitiy> TachoImageAnalysisRingImplementation::getAllActivities(TachoImage *tacho)
{

    ////////////////tests
std::vector<TachoActivitiy> result;
int ** array =tacho->getArray();
for(int i=0;i<tacho->getWidth();i++)
{
    array[tacho->getHeight()/2][i]=0;
}
for(int i=0;i<tacho->getHeight();i++)
{
    array[i][tacho->getWidth()/2]=0;
}


int a=tacho->getHeight()/2;
int b=tacho->getWidth()/2;
int r1=387;
int r2=363;
int y1;
int y2;

///////////////////

int l;
int counter=0;
int all=0;
for(int i=a-r2;i<=a+r2;i++)
{
       l=0;
       for(int k=0;k<=r1-r2;k++)
       {
           y1=round(sqrt(((r2+k)-i+a)*((r2+k)+i-a))+b);
          // y2=round(-sqrt(((r2+k)-i+a)*((r2+k)+i-a))+b);
           //y2=round(-sqrt((r2+k)*(r2+k) -(i-a)*(i-a)) +b);
           //qDebug()<<"(array[i][y1]"<<array[i][y1];
           if(array[i][y1]<100)
           {
                l++;
                array[i][y1]=0;
           }
           //array[i][y1]=0;
         //  array[i][y2]=0;
       }

       if(l>0.8*(r1-r2))
       {
            counter++;
       }
       all++;
    //y=round(sqrt(((r2+k)-i+a)*((r2+k)+i-a))+b);
}


for(int i=a-r2;i<=a+r2;i++)
{
       l=0;
       for(int k=0;k<=r1-r2;k++)
       {
           //y1=round(sqrt(((r2+k)-i+a)*((r2+k)+i-a))+b);
           y2=round(-sqrt(((r2+k)-i+a)*((r2+k)+i-a))+b);
           //y2=round(-sqrt((r2+k)*(r2+k) -(i-a)*(i-a)) +b);

           if(array[i][y2]<100)
           {
                l++;
                array[i][y2]=0;
           }
          // array[i][y2]=0;

       }

       if(l>0.8*(r1-r2))
       {
            counter++;

       }
       all++;
    //y=round(sqrt(((r2+k)-i+a)*((r2+k)+i-a))+b);
}



qDebug()<<"counter "<<counter<<"all "<<all;
return result;
}
