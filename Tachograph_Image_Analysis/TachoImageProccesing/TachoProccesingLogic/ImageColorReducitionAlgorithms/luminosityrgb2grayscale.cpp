#include "luminosityrgb2grayscale.h"

LuminosityRGB2GrayScale::LuminosityRGB2GrayScale()
{
}


void LuminosityRGB2GrayScale::reduceColor(QImage *image, TachoImage *tachoImage)
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
int LuminosityRGB2GrayScale::convert1Pixel(QRgb rgb)
{

    QColor color(rgb);
    int result= 0.21*color.red()+0.72*color.blue()+0.07*color.green();
    return result;

}

