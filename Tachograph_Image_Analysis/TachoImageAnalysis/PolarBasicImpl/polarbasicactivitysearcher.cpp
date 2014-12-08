#include "polarbasicactivitysearcher.h"

PolarBasicActivitySearcher::PolarBasicActivitySearcher()
{
}


std::vector<TachoActivitiy*> PolarBasicActivitySearcher::getAllActivities(TachoImage *tacho)
{
    int a=tacho->getHeight()/2;
    int b=tacho->getWidth()/2;
    int r1=363;
    int r2=387;
    int resolution=4;
    // temporary
    TachoActivityFactory * factory= new PolarBasicTachoActivityFactory();
    int counter=0;
    int **array=tacho->getArray();
    int recentActivity=-2;
    int x;
    int y;
    std::vector<TachoActivitiy*> result;
    int* buff= new int[r2-r1];
    for(int i=180*resolution;i>-resolution*180;i--)
    {
         for(int k=0;k<=r2-r1;k++)
         {
             x=round((r1+k)*cos( M_PI*i/(180*resolution)));
             y=round((r1+k)*sin( M_PI*i/(180*resolution)));
             y=y+b;
             x=x+a;
             buff[k]=array[y][x];
             //debug
             array[y][x]=0;
         }
            if(recentActivity!=validateActivity(buff,r2-r1,0.25,0.75,0.9,100))
            {
                finishOldActivity();
            }

     }



    return result;
}
TachoActivitiy * PolarBasicActivitySearcher::createNewActivtiy(int choose, int currentMin,TachoActivityFactory *factory)
{

    TachoActivitiy * activity=factory->produceTachoActivtiy(choose);
    activity->setStartTimeInMin(currentMin);
    return activity;
}

void PolarBasicActivitySearcher::finishOldActivity(TachoActivitiy * oldActivity,int currentMin)
{
    oldActivity->setEndTimeInMin(counter);
    oldActivity->setDuringTimeInMin(currentMin-oldActivity->getStartTimeInMin());


}

int PolarBasicActivitySearcher::validateActivity(int buff[],int length,double param1,double param2,double param3,double treshold)
{
    int computedData=computeDataFromBuffor(buff, length, treshold);
    return decideWhichActivity(computedData,length, param1, param2, param3);
}


int PolarBasicActivitySearcher::computeDataFromBuffor(int buff[],int length,double treshold)
{
    int counter=0;
    for(int i=0;i<length;i++)
    {
        if(buff[i]<treshold)
        {
            counter++;
        }

    }
return counter;

}

int PolarBasicActivitySearcher::decideWhichActivity(int counter,int length,double param1,double param2,double param3)
{
    if(counter<param1*length)
    {
        return 0;
    }
    else if(counter>=param1*length && counter< param2*length)
    {
        return 1;
    }
    else if(counter>=param2*length && counter< param3*length)
    {
        return 2;
    }
    else if( counter>= param3*length)
    {
        return 3;
    }
    else
    {
        return -1;
    }


}
