#include "tachoimageanalysispolarimplementation.h"

TachoImageAnalysisPolarImplementation::TachoImageAnalysisPolarImplementation()
{
}
int* TachoImageAnalysisPolarImplementation::getAllActivities(TachoImage *tacho)
{
    // int a=tacho->getHeight()/2;
    // int b=tacho->getWidth()/2;
     //int r1=363;
     //int r2=387;
    int buffLength=tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius();
    int **rectangleWithActivities=transformRing2Rectangle(tacho,2);
    int * result=scanRectangle(rectangleWithActivities,2,buffLength);

    return result;
}

int ** TachoImageAnalysisPolarImplementation::transformRing2Rectangle(TachoImage * tacho,int resolution)
{

    int **array=tacho->getArray();
    int x;
    int y;
    int counter=0;
    int ** result = new int*[360*resolution];
    for(int i=0;i<360*resolution;i++)
    {
        result[i]=new int[tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius()];
    }
    for(int i=180*resolution;i>-resolution*180;i--)
    {
         for(int k=0;k<=tacho->getActivityExternalRadius()-tacho->getActivityInternalRadius();k++)
         {
             x=round((tacho->getActivityInternalRadius()+k)*cos( M_PI*i/(180*resolution)));
             y=round((tacho->getActivityInternalRadius()+k)*sin( M_PI*i/(180*resolution)));
             y=y+tacho->getXCenterCord();
             x=x+tacho->getYCenterCord();
             result[counter][k]=array[y][x];
             //array[y][x]=0;

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
        int counter=countBlackPixelInBuff(rectangleWithActivities[i],length);
        result[i]=decideWhichActivity(counter,length);
    }
    return result;
}

int TachoImageAnalysisPolarImplementation::countBlackPixelInBuff(int buff[],int length)
{
    int counter=0;
    for(int i=0;i<length;i++)
    {
        if(buff[i]<TachoImageAnalysisPolarImplementation::BLACK_POINT_TRESHOLD)
        {
            counter++;
        }

    }
    qDebug()<<" percent"<<(double)counter/length<< " ";
return counter;

}
int TachoImageAnalysisPolarImplementation::decideWhichActivity(int counter,int buffSize)
{
    if(counter<TachoImageAnalysisPolarImplementation::STAND_BY_TRESHOLD*buffSize)
    {
        return 0;
    }
    else if(counter>=TachoImageAnalysisPolarImplementation::STAND_BY_TRESHOLD*buffSize &&
            counter< TachoImageAnalysisPolarImplementation::ANOTHER_WORK_TRESHOLD*buffSize)
    {
        return 1;
    }
    else if(counter>=TachoImageAnalysisPolarImplementation::ANOTHER_WORK_TRESHOLD*buffSize &&
            counter< TachoImageAnalysisPolarImplementation::DRIVE_TRESHOLD*buffSize)
    {
        return 2;
    }
    else if( counter>= TachoImageAnalysisPolarImplementation::DRIVE_TRESHOLD*buffSize)
    {
        return 3;
    }
    else
    {
        return -1;
    }


}