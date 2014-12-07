#include "averagergb2grayscale.h"
#include <QDebug>
void AverageRGB2GrayScale:: reduceColor(QImage * image,TachoImage *tachoImage)
{
    int ** array= tachoImage->getArray();
    for(int i=0;i<tachoImage->getHeight();i++)
    {
        for(int j=0;j<tachoImage->getWidth();j++)
        {
            array[i][j]=convert1Pixel(image->pixel(j,i));
        }
       if(i%100==0)
       {
           qDebug()<<i<<"  "<<array[i][i];
       }
    }
    qDebug()<<"skonczylem";
}

 int AverageRGB2GrayScale::convert1Pixel(QRgb rgb)
{

    QColor color(rgb);
   short int result= color.red()+color.blue()+color.green();
   result=result/3;
    return result;
}


