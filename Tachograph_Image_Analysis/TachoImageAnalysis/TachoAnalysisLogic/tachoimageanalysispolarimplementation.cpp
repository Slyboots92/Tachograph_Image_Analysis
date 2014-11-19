#include "tachoimageanalysispolarimplementation.h"

TachoImageAnalysisPolarImplementation::TachoImageAnalysisPolarImplementation()
{
}


int TachoImageAnalysisPolarImplementation::validateActivity(int buff[],int length,double param1,double param2,double param3,double treshold)
{
int counter=0;
for(int i=0;i<length;i++)
{
    if(buff[i]<treshold)
    {
        counter++;
    }

}

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
else
{
    return 3;
}

}

int TachoImageAnalysisPolarImplementation::findTranslationToStartScaning(TachoImage * tachoImage,int resolution,int r1,int r2,int a,int b)
{
    int translation=0;
    int actualActivity;
    int *buff= new int[r2-r1];
    int x1;
    int y1;
    int **array=tachoImage->getArray();
    for(int i=-180*resolution;i<resolution*180;i++)
    {
        for(int k=0;k<=r2-r1;k++)
        {
            y1=round((r1+k)*sin( M_PI*i/(180*resolution)));
            x1=round((r1+k)*cos( M_PI*i/(180*resolution)));
            y1=y1+b;
            x1=x1+a;
            buff[k]=array[y1][x1];
            //debug
            array[y1][x1]=0;
        }
        if(translation>1)
        {
            qDebug()<<actualActivity<<" "<<validateActivity(buff,r2-r1,0.4,0.75,0.9,100);
            if(validateActivity(buff,r2-r1,0.4,0.75,0.9,100)!=actualActivity)
            {
                return translation;
            }

        }
        actualActivity=validateActivity(buff,r2-r1,0.4,0.75,0.9,100);
        translation++;

    }
    return translation;



}





std::vector<TachoActivitiy> TachoImageAnalysisPolarImplementation::scanCircle(TachoImage * tachoImage,int resolution,double translation,int r1,int r2,int a,int b)
{

    std::vector<TachoActivitiy> activity;
    int y1;
    int x1;

    int start=findTranslationToStartScaning(tachoImage,4,r1,r2,a,b);
    int **array=tachoImage->getArray();
    for(int i=-180*resolution+start;i<-resolution*170;i++)
    {
        for(int k=0;k<=r2-r1;k++)
        {
            y1=round((r1+k)*cos( M_PI*i/(180*resolution)));
            x1=round((r1+k)*sin( M_PI*i/(180*resolution)));
            y1=y1+b;
            x1=x1+a;
            //array[y1][x1]=0;
        }
    }
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
int r1=363;
int r2=387;
int x1;
int y1;

///////////////////
// TODO
scanCircle(tacho,4,0,r1,r2,a,b);

return result;
}

