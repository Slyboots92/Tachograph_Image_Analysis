#ifndef CIRCLEDETECTION_H
#define CIRCLEDETECTION_H
#include <string>
#include <QDebug>
#include "TachoImageShared/tachoimage.h"
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
class CircleDetection
{
public:
    CircleDetection();
    void findMainTachoCircleAndLoadData2TachoImage(std::string pathName,TachoImage * image);
    cv::Vec3f findMainTachoCircle(std::string pathName);
    cv::Mat cropImage(cv::Mat,TachoImage * image);
    std::vector<cv::Vec3f> findImportantCircleToComputeAngle(std::string pathName ,TachoImage * image);
    ~CircleDetection();
};

#endif // CIRCLEDETECTION_H
