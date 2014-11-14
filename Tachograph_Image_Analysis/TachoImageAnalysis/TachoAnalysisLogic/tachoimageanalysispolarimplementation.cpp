#include "tachoimageanalysispolarimplementation.h"

TachoImageAnalysisPolarImplementation::TachoImageAnalysisPolarImplementation()
{
}
TachoActivitiy* TachoImageAnalysisPolarImplementation::validateActivity(int *array,int length)
{

int counter=0;
for(int i=0;i<length;i++)
{
    if(array[i]<50)
    {
        counter++;
    }
}


    return new TachoDrivingActivity();

}

std::vector<TachoActivitiy> TachoImageAnalysisPolarImplementation::checkCircle
(int **array,int width,int height,int r1,int r2,int a,int b,double resoultion)
{
    std::vector<TachoActivitiy> activity;
    int y1;
    int x1;
    int k=0;
    for(int i=-180*resoultion;i<resoultion*180;i++)
    {
        for(int k=0;k<=r2-r1;k++)
        {
            y1=round((r1+k)*cos( M_PI*i/(180*resoultion)));
            x1=round((r1+k)*sin( M_PI*i/(180*resoultion)));
            y1=y1+b;
            x1=x1+a;
            array[y1][x1]=0;
        }
    }
    return activity;
}

std::vector<TachoActivitiy> TachoImageAnalysisPolarImplementation::correctDelayCausedRatation
(std::vector<TachoActivitiy> activities,double fi)
{
std::vector<TachoActivitiy> activity;
return activity;

}





std::vector<TachoActivitiy> TachoImageAnalysisPolarImplementation::getAllActivities(TachoImage *tacho)
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
int x1;
int y1;

///////////////////
checkCircle(array,0,0,r2,r1, a,b,4);


return result;
}

