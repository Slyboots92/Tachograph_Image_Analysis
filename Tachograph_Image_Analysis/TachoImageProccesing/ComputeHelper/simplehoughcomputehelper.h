#ifndef SIMPLEHOUGHCOMPUTEHELPER_H
#define SIMPLEHOUGHCOMPUTEHELPER_H
#include "TachoImageShared/tachoimage.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <cmath>
#include <QDebug>
class SimpleHoughComputeHelper
{
public:
    SimpleHoughComputeHelper();
    ~SimpleHoughComputeHelper();
    void computeExternalAndInternalRadiusWithActivitiesAndLoad(TachoImage * image);
    void computeImageRotation(TachoImage * image);
    void find2ImportantCirclesAndLoad(TachoImage * image,std::vector<cv::Vec3f> circle);


private:
int checkWhichPart(int x1,int y1,int x2,int y2);
static int computeExternalRadiusWithActivities(TachoImage * image);
static int computeInternalRadiusWithActivities(TachoImage * image);
bool checkCondition4ThisCircle(TachoImage * image,cv::Vec3f circle);
cv::Vec3f findFirstImportantCircle(TachoImage * image,std::vector<cv::Vec3f> circles);
std::vector<cv::Vec3f> findSecondImportantCircle(TachoImage * image,std::vector<cv::Vec3f> circles);
double static const internalRadius=0.5;
double static const externalRadius=0.55;
};

#endif // SIMPLEHOUGHCOMPUTEHELPER_H
