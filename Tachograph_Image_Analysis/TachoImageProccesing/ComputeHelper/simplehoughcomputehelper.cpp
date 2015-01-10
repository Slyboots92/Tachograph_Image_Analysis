#include "simplehoughcomputehelper.h"

SimpleHoughComputeHelper::SimpleHoughComputeHelper()
{

}

SimpleHoughComputeHelper::~SimpleHoughComputeHelper()
{

}

int SimpleHoughComputeHelper::computeInternalRadiusWithActivities(TachoImage *image)
{
int result;
result=image->getMainCircleRadius()*SimpleHoughComputeHelper::internalRadius;
return result;

}
int SimpleHoughComputeHelper::computeExternalRadiusWithActivities(TachoImage *image)
{
int result;
result=image->getMainCircleRadius()*SimpleHoughComputeHelper::externalRadius;
return result;

}

void SimpleHoughComputeHelper::computeExternalAndInternalRadiusWithActivitiesAndLoad(TachoImage * image)
{

    int internalRadius=computeInternalRadiusWithActivities(image);
    int externalRadius=computeExternalRadiusWithActivities(image);
    qDebug()<<"internal "<<internalRadius;
    qDebug()<<"external "<<externalRadius;
    image->setActivityInternalRadius(internalRadius);
    image->setActivityExternalRadius(externalRadius);

}

void SimpleHoughComputeHelper::find2ImportantCirclesAndLoad(TachoImage * image,std::vector<cv::Vec3f> circles)
{
    cv::Vec3f circle=findFirstImportantCircle(image,circles);
    qDebug()<<"small x "<<circle[0];
    qDebug()<<"small y "<<circle[1];
    image->setSmallMainCircleRadius(circle[2]);
    image->setXCenterCord(circle[0]);
    image->setYCenterCord(circle[1]);
    std::vector<cv::Vec3f> small_second_circles=findSecondImportantCircle(image,circles);
    qDebug()<<"size "<<small_second_circles.size();
    image->setSecondSmallCircleXCord(circles[0][0]);
    image->setSecondSmallCircleYCord(circles[0][1]);
    image->setSecondSmallCircleRadius(circles[0][2]);

}

cv::Vec3f SimpleHoughComputeHelper::findFirstImportantCircle(TachoImage * image,std::vector<cv::Vec3f> circles)
{
    cv::Vec3f result=circles[0];
    int distanceNow;
    int x=image->getWidth()/2;
    int y=image->getHeight()/2;
    int distance=sqrt((x-circles[0][0])*(x-circles[0][0])+ (y-circles[0][1])*(y-circles[0][1]) );
    for( size_t i = 0; i < circles.size(); i++ )
    {
        distanceNow=sqrt((x-circles[i][0])*(x-circles[i][0])+ (y-circles[i][1])*(y-circles[i][1]) );
        if(distanceNow<distance)
        {
            distance=distanceNow;
            result=circles[i];
        }

    }
    qDebug()<<"x "<<result[0]<<"y "<<result[1]<<"r "<<result[2];
    return result;
}

std::vector<cv::Vec3f> SimpleHoughComputeHelper::findSecondImportantCircle(TachoImage * image,std::vector<cv::Vec3f> circles)
{

    std::vector<cv::Vec3f> result;
    int x=image->getXCenterCord();
    int y=image->getYCenterCord();
    for( size_t i = 0; i < circles.size(); i++ )
    {
        if(checkCondition4ThisCircle(image,circles[i]))
        {
            result.push_back(circles[i]);
        }

    }
    return result;


}

bool SimpleHoughComputeHelper::checkCondition4ThisCircle(TachoImage * image,cv::Vec3f circle)
{

    int x1=image->getXCenterCord();
    int y1=image->getYCenterCord();
    int x2=circle[0];
    int y2=circle[1];
    int radius1=image->getSmallMainCircleRadius();
    int radius2=circle[2];
    double distance=sqrt((x1-x2)*(x1-x2)+ (y1-y2)*(y1-y2));
  //  qDebug()<<"check "<<" "<<radius1+radius2<<" "<<distance<<" "<<radius1;
    if(radius1+radius2>distance&&distance>radius1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void SimpleHoughComputeHelper::computeImageRotation(TachoImage * image)
{
//Ax+By+C=0
double x1=image->getXCenterCord();
double y1=image->getYCenterCord();
double x2=image->getSecondSmallCircleXCord();
double y2=image->getSecondSmallCircleYCord();
qDebug()<<"x1 "<<x1;
qDebug()<<"y1 "<<y1;
qDebug()<<"x2 "<<x2;
qDebug()<<"y2 "<<y2;



double angle;
if(abs(x2-x1)<5)
{
    if(y2>y1)
    {
        angle=90;
    }
    else
    {
        angle=270;
    }
}
else if(abs(y2-y1)<5)
{
    if(x2>x1)
    {
        angle=0;
    }
    else
    {
        angle=180;
    }
}
else
{

    double direction=-(y2-y1)/(x2-x1);
     qDebug()<<"direction "<<direction;
    angle=atan(direction);
    angle=angle*180/M_PI;
    int part=checkWhichPart(x1,y1,x2,y2);
    qDebug()<<"part "<<part;
    if(part==2||part==3)
    {
        angle+=180;
    }
    if(part==1)
    {
        angle+=270;
    }
}
qDebug()<<"angle "<<angle;
image->setRotation(angle);


}
int SimpleHoughComputeHelper::checkWhichPart(int x1,int y1,int x2,int y2)
{
    /*
            |
            |
        II  |   I
   x< --------------------
        III |   IV
            |
            |
           \/
           y
     */
if(x2<x1 && y2>y1)
    return 4;
else if(x2>x1 && y2<y1)
    return 1;
else if(x2>x1&&y2 > y1)
    return 3;
else
    return 2;


}
