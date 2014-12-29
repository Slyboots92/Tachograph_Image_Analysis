
#include <QApplication>
#include "GUI/mainwindow.h"
//#include "TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/averagergb2grayscale.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    // w.show();
    cv::Mat src, src_gray;

      /// Read the image
      src = cv::imread( "/home/slyboots/development/workspace/qt_workspace/Tachograph_Image_Analysis/Tachograph_Image_Analysis/Resource/techo1_moja_kadrowana_obrot.jpg", 1 );
       qDebug()<<src.empty();
      if( !src.data )
        { return -1; }

      /// Convert it to gray
      cv::cvtColor( src, src_gray, cv::COLOR_BGR2GRAY);

      /// Reduce the noise so we avoid false circle detection
      cv::GaussianBlur( src_gray, src_gray, cv::Size(9, 9), 2, 2 );

     std::vector<cv::Vec3f> circles;

      /// Apply the Hough Transform to find the circles
      HoughCircles( src_gray, circles, CV_HOUGH_GRADIENT, 1, src_gray.rows/8, 200, 100, 0, 0 );

      for(std::vector<cv::Vec3f>::iterator it = circles.begin(); it != circles.end(); ++it) {
          qDebug()<<(*it).val[0];
      }
      /// Draw the circles detected
    // for( size_t i = 0; i < circles.size(); i++ )
    // {
    //     cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
     //    int radius = cvRound(circles[i][2]);
          // circle center
      //   cv::circle( src, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
          // circle outline
      //    cv::circle( src, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
     // }

      /// Show your results
     // cv::namedWindow( "Hough Circle Transform Demo", CV_WINDOW_AUTOSIZE );
     // cv::imshow( "Hough Circle Transform Demo", src );

    //  cv::waitKey(0);
    qDebug()<<"done";
    return a.exec();
}
