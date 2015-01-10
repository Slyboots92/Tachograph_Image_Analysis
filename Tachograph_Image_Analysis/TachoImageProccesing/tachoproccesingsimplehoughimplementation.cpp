#include "tachoproccesingsimplehoughimplementation.h"

TachoProccesingSimpleHoughImplementation::TachoProccesingSimpleHoughImplementation()
{

}

TachoProccesingSimpleHoughImplementation::~TachoProccesingSimpleHoughImplementation()
{

}
TachoImage *TachoProccesingSimpleHoughImplementation::produceTachoImage2Analysis(std::string imagePath)
{
QImage * image = new  QImage();
image->load(QString::fromStdString(imagePath));
TachoImage * tachoImage= new TachoImage(image);
ImageColorReduction *colorReduction = new LuminosityRGB2GrayScale();
colorReduction->reduceColor(image,tachoImage);
CircleDetection *circleDetection = new CircleDetection();
SimpleHoughComputeHelper *computeHelper = new SimpleHoughComputeHelper();
circleDetection->findMainTachoCircleAndLoadData2TachoImage(imagePath,tachoImage);
std::vector <cv::Vec3f> circles=circleDetection->findImportantCircleToComputeAngle(imagePath,tachoImage);
computeHelper->computeExternalAndInternalRadiusWithActivitiesAndLoad(tachoImage);
computeHelper->find2ImportantCirclesAndLoad(tachoImage,circles);
computeHelper->computeImageRotation(tachoImage);
CropImage *cropImage= new CropImage();
cropImage->cropImage(tachoImage,tachoImage->getXCenterCordOnRawImage()-tachoImage->getMainCircleRadius()
                                ,tachoImage->getYCenterCordOnRawImage()-tachoImage->getMainCircleRadius(),
                                2*tachoImage->getMainCircleRadius(),
                                2*tachoImage->getMainCircleRadius());
return tachoImage;

}
