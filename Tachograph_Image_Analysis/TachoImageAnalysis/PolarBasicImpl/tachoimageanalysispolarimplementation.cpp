#include "tachoimageanalysispolarimplementation.h"

TachoImageAnalysisPolarImplementation::TachoImageAnalysisPolarImplementation()
{
}
std::vector<TachoActivitiy*> TachoImageAnalysisPolarImplementation::getAllActivities(TachoImage *tacho)
{
    int buffLength=tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius();
    int **rectangleWithActivities=transformRing2Rectangle(tacho,4);
    int * activities=scanRectangle(rectangleWithActivities,4,buffLength);
    std::vector<TachoActivitiy*> tmp=createAndComputeActivityDetails(activities,4);
    std::vector<TachoActivitiy*> result=filterActivities(tmp);
    return result;
}
std::vector<TachoActivitiy*>
TachoImageAnalysisPolarImplementation::createAndComputeActivityDetails(int *activities,int resolution)
{
    std::vector<TachoActivitiy*> result;
    double unit=(24*60)/(360*resolution);
    int currentActivityNumber=-1;
    int duringTime=0;
    TachoActivitiy *currentActivity=NULL;
    PolarBasicTachoActivityFactory *factory = new PolarBasicTachoActivityFactory();
    for(int i=0;i<resolution*360;i++)
    {
        if(activities[i]!=currentActivityNumber)
        {
            currentActivityNumber=activities[i];
            if(currentActivity!=NULL)
            {
                currentActivity->setDuringTimeInMin(duringTime*unit);
                currentActivity->setEndTimeInMin(i*unit);
                result.push_back(currentActivity);
            }
            currentActivity=factory->produceTachoActivtiy(currentActivityNumber);
            currentActivity->setStartTimeInMin(i*unit);
            duringTime=0;
        }


            duringTime++;


    }
return result;

}

int ** TachoImageAnalysisPolarImplementation::transformRing2Rectangle(TachoImage * tacho,int resolution)
{
    qDebug()<<"getActivityExternalRadius() "<<tacho->getActivityExternalRadius();
    qDebug()<<"getActiviternaltyInRadius() "<<tacho->getActivityInternalRadius();
    int **array=tacho->getArray();
    int x;
    int y;
    int counter=0;
    int ** result = new int*[360*resolution];
    for(int i=0;i<360*resolution;i++)
    {
        result[i]=new int[tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius()];
    }
    for(int i=-180*resolution;i<resolution*180;i++)
    {
         for(int k=0;k<=tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius();k++)
         {
             x=round((tacho->getActivityInternalRadius()+k)*cos( M_PI*i/(180*resolution)));
             y=round((tacho->getActivityInternalRadius()+k)*sin( M_PI*i/(180*resolution)));
             y=y+tacho->getYCenterCord();
             x=x+tacho->getXCenterCord();
             result[counter][k]=array[y][x];
         }
         counter++;
   }
    return result;

}
int * TachoImageAnalysisPolarImplementation::scanRectangle(int **rectangleWithActivities,int resolution,int length)
{
    int *result= new int[360*resolution];
    for(int i=0;i<360*resolution;i++)
    {
        double percent=countPercenteBlackPixelInBuff(rectangleWithActivities[i],length);
        result[i]=decideWhichActivity(percent);
    }
    return result;
}
int * filterActivities(int * activities,int resolution,int length)
{


}

double TachoImageAnalysisPolarImplementation::countPercenteBlackPixelInBuff(int buff[],int length)
{
    double counterBlack=0;
    double counterAll=0;
    bool countingAlready=false;
    for(int i=0;i<length;i++)
    {
        if(buff[i]<TachoImageAnalysisPolarImplementation::BLACK_POINT_TRESHOLD)
        {
            countingAlready=true;
            if(countingAlready)
            {
                counterBlack++;
            }

        }
        if(countingAlready)
        {
            counterAll++;
        }

    }
   // qDebug()<<" percent"<<(double)counter/length<< " ";
    if(countingAlready)
    {
        return counterBlack/counterAll;
    }
    else
    {
        return 0;
    }

}
int TachoImageAnalysisPolarImplementation::decideWhichActivity(double percent)
{
    if(percent<TachoImageAnalysisPolarImplementation::STAND_BY_TRESHOLD)
    {
        return 0;
    }
    else if(percent>=TachoImageAnalysisPolarImplementation::STAND_BY_TRESHOLD &&
            percent< TachoImageAnalysisPolarImplementation::ANOTHER_WORK_TRESHOLD)
    {
        return 1;
    }
    else if(percent>=TachoImageAnalysisPolarImplementation::ANOTHER_WORK_TRESHOLD &&
            percent< TachoImageAnalysisPolarImplementation::DRIVE_TRESHOLD)
    {
        return 2;
    }
    else if( percent>= TachoImageAnalysisPolarImplementation::DRIVE_TRESHOLD)
    {
        return 3;
    }
    else
    {
        return -1;
    }


}

std::vector<TachoActivitiy*> TachoImageAnalysisPolarImplementation::filterActivities(std::vector<TachoActivitiy*> activities)
{
    std::vector<TachoActivitiy*> result;
    TachoActivityFactory  * factory= new PolarBasicTachoActivityFactory();
    int duringTime=0;
    TachoActivitiy * currActivity=NULL;
    qDebug()<<" filtr start";
    bool inserted=false;
    for(std::vector<TachoActivitiy*>::iterator it = activities.begin(); it != activities.end(); ++it) {

         qDebug()<<" filtr iteracja";
        if(currActivity!=NULL&&(( (*it)->getDuringTimeInMin()<=3)||((*it)->getType()==currActivity->getType())))
        {
            qDebug()<<" if ";
            currActivity->setDuringTimeInMin(currActivity->getDuringTimeInMin()+(*it)->getDuringTimeInMin());
            currActivity->setEndTimeInMin(currActivity->getEndTimeInMin()+(*it)->getDuringTimeInMin());
            inserted=false;
        }
        else
        {
              qDebug()<<" else ";
            if(currActivity!=NULL)
            {
                result.push_back(currActivity);
                inserted=true;
            }
            currActivity=factory->produceTachoActivtiy((*it)->getType());
            currActivity->setStartTimeInMin((*it)->getStartTimeInMin());
            currActivity->setDuringTimeInMin((*it)->getDuringTimeInMin());
            currActivity->setEndTimeInMin((*it)->getEndTimeInMin());
        }
        duringTime+=(*it)->getDuringTimeInMin();
        qDebug()<<duringTime;
   }
    if(inserted==false)
    {
        result.push_back(currActivity);
    }
    return result;
}
