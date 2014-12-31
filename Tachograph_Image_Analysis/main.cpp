
#include <QApplication>
#include "GUI/mainwindow.h"
//#include "TachoImageProccesing/TachoProccesingLogic/ImageColorReducitionAlgorithms/averagergb2grayscale.h"
#include <QDebug>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <vector>
#include <QDebug>
#include<QImage>

using namespace cv;
void test()
{

    ImageColorReduction * algo1= new LightnessRGB2GrayScale();

   QImage * image = new  QImage();
   image->load("/home/slyboots/development/workspace/qt_workspace/Tachograph_Image_Analysis/Tachograph_Image_Analysis/Resource/techo1_moja_kadrowana_obrot.jpg" );
    //image->load("/home/slyboots/development/workspace/qt_workspace/Tachograph_Image_Analysis/Tachograph_Image_Analysis/Resource/techo1_moja.jpg" );
   qDebug()<<"is null"<<image->isNull();
   TachoImage * tacho = new TachoImage(image );
   algo1->reduceColor(image,tacho);

   cv::Mat mat = cv::Mat(image->height(), image->width(), CV_8UC4, (uchar*)image->bits(), image->bytesPerLine());
      cv::Mat mat2 = cv::Mat(mat.rows, mat.cols, CV_8UC3 );
      int from_to[] = { 0,0,  1,1,  2,2 };
      cv::mixChannels( &mat, 1, &mat2, 1, from_to, 3 );





       cv::Mat src, tar1,tar2,tar3,tar4;
    /// Read the image
   //src = cv::imread( "/home/slyboots/development/workspace/qt_workspace/Tachograph_Image_Analysis/Tachograph_Image_Analysis/Resource/techo1_moja_kadrowana_obrot.jpg", 1 );
 src = cv::imread( "/home/slyboots/development/workspace/qt_workspace/Tachograph_Image_Analysis/Tachograph_Image_Analysis/Resource/techo1_moja.jpg", 1 );
    qDebug()<<src.empty();

    //src_gray.
    /// Convert it to gray
    cv::cvtColor( src, tar1, cv::COLOR_BGR2GRAY);
 qDebug()<<"done";
;
 qDebug()<<"done";
   std::vector<cv::Vec3f> circles;

    /// Apply the Hough Transform to find the circles
   int threshold_value = 150;
   int threshold_type = 0;
   int const max_value = 255;
   int const max_type = 4;
   int const max_BINARY_value = 255;
    ///
    ///
    /// int
  int dilation_size=1;
  // threshold( tar1, tar2, threshold_value, max_BINARY_value,threshold_type );
  cv::Mat element = getStructuringElement(  cv::MORPH_CROSS,
                                         cv::Size( 2*dilation_size + 1, 2*dilation_size+1 ),
                                         cv::Point( dilation_size, dilation_size ) );
    //src.copyTo(
  //Mat new_image = Mat::zeros( tar2.size(), tar2.type() );

      // create a matrix with all elements equal to 255 for subtraction
     // Mat sub_mat = Mat::ones(tar2.size(), tar2.type())*255;

      //subtract the original matrix by sub_mat to give the negative output new_image
      //subtract(sub_mat, tar2, new_image);

   //cv::erode(tar2,tar3,element);
// HoughCircles( tar1, circles, CV_HOUGH_GRADIENT, 4, tar1.rows/15, 300, 200, tar1.rows/30, tar1.rows/16 );
   HoughCircles( tar1, circles, CV_HOUGH_GRADIENT, 4, tar1.rows/2, 300, 200, tar1.cols/4, tar1.cols/2 );
   qDebug()<<"done";
    for(std::vector<cv::Vec3f>::iterator it = circles.begin(); it != circles.end(); ++it) {
        qDebug()<<"x"<<(*it).val[0]<<" y"<<(*it).val[1]<<"r "<<(*it).val[2];
    }
    /// Draw the circles detected
   // tar4=new_image;
   for( size_t i = 0; i < circles.size(); i++ )
  {
      cv::Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
       int radius = cvRound(circles[i][2]);
        //circle center
       cv::circle( src, center, 3, cv::Scalar(0,255,0), -1, 8, 0 );
        // circle outline
        cv::circle( src, center, radius, cv::Scalar(0,0,255), 3, 8, 0 );
   }

    /// Show your results
    ///

   // Transform it into the C++ cv::Mat format

    int r=circles[0][2];
    int x=circles[0][0];
    int y=circles[0][1];
   // Setup a rectangle to define your region of interest
   cv:Rect myROI(x-r,y-r,2*r,2*r);
   //cv::Rect myROI(1000, 1000, 1000, 1000);

   // Crop the full image to that image contained by the rectangle myROI
   // Note that this doesn't copy the data
   cv::Mat croppedImage = src(myROI);
    //src.copyTo(croppedImage);

   cv::namedWindow( "Hough Circle Transform ", CV_WINDOW_KEEPRATIO);
    cv::imshow( "Hough Circle Transform ", croppedImage );

    cv::waitKey(0);
  qDebug()<<"done";


}
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
  // MainWindow w;
   // w.show();


    test();
    return a.exec();
}

