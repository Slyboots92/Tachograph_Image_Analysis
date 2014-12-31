#include "circledetection.h"

CircleDetection::CircleDetection()
{

}

CircleDetection::~CircleDetection()
{

}

void CircleDetection::findMainTachoCircleAndLoadData2TachoImage(std::string pathName,TachoImage * image)
{
   cv::Vec3f vectorWithCircleDetails= findMainTachoCircle(pathName);
   image->setMainCircleRadius(vectorWithCircleDetails[2]);
   image->setXCenterCordOnRawImage(vectorWithCircleDetails[0]);
   image->setYCenterCordOnRawImage(vectorWithCircleDetails[1]);
}

cv::Vec3f CircleDetection::findMainTachoCircle(std::string pathName)
{


    cv::Mat RGB_src, gray_src;
 /// Read the image
 RGB_src = cv::imread(pathName, 1 );
 qDebug()<<RGB_src.empty();

 //src_gray.
 /// Convert it to gray
 cv::cvtColor( RGB_src, gray_src, cv::COLOR_BGR2GRAY);

std::vector<cv::Vec3f> circles;
HoughCircles( gray_src, circles, CV_HOUGH_GRADIENT, 4, gray_src.rows/2, 300, 200, gray_src.cols/4, gray_src.cols/2 );


//To display
for( size_t i = 0; i < circles.size(); i++ )
{
   cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
    int radius = cvRound(circles[i][2]);
    cv::circle( RGB_src, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
     cv::circle( RGB_src, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
}
cv::namedWindow( "Hough Circle Transform ", CV_WINDOW_KEEPRATIO);
cv::imshow( "Hough Circle Transform ", RGB_src );

 cv::waitKey(0);


return circles[0];
}


cv::Mat CircleDetection::cropImage(cv::Mat src,TachoImage * image)
{
    int r=image->getMainCircleRadius();
    int x=image->getXCenterCordOnRawImage();
    int y=image->getYCenterCordOnRawImage();

   // Setup a rectangle to define your region of interest
   cv::Rect myROI(x-r,y-r,2*r,2*r);

   // Crop the full image to that image contained by the rectangle myROI
   // Note that this doesn't copy the data
   cv::Mat croppedImage = src(myROI);;
    //To display to Debug
   cv::namedWindow( "Hough Circle Transform ", CV_WINDOW_KEEPRATIO);
   cv::imshow( "Hough Circle Transform ", croppedImage );
   cv::waitKey(0);
    //
    return croppedImage;
}

std::vector<cv::Vec3f> CircleDetection::findImportantCircleToComputeAngle(std::string pathName ,TachoImage * image)
{
    cv::Mat src,croppedImage;
    src = cv::imread(pathName, 1 );
    croppedImage=cropImage(src,image);

    std::vector<cv::Vec3f> circles;
    HoughCircles( croppedImage, circles, CV_HOUGH_GRADIENT, 4, croppedImage.rows/15, 300, 200, croppedImage.rows/30, croppedImage.rows/16 );

    //Display to Debug
      for( size_t i = 0; i < circles.size(); i++ )
     {
         cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
          int radius = cvRound(circles[i][2]);
          cv::circle( croppedImage, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
           cv::circle( croppedImage, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
      }
      cv::namedWindow( "Hough Circle Transform ", CV_WINDOW_KEEPRATIO);
      cv::imshow( "Hough Circle Transform ", croppedImage );
      cv::waitKey(0);
     qDebug()<<"done";
    return circles;
}
