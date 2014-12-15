#include "lightnessrgb2grayscale.h"

LightnessRGB2GrayScale::LightnessRGB2GrayScale()
{
}



void LightnessRGB2GrayScale::reduceColor(QImage *image, TachoImage *tachoImage)
{
    int ** array= tachoImage->getArray();
    for(int i=0;i<tachoImage->getHeight();i++)
    {
        for(int j=0;j<tachoImage->getWidth();j++)
        {
            array[i][j]=convert1Pixel(image->pixel(j,i));
        }
      // if(i%100==0)
       {
       //    qDebug()<<i<<"  "<<array[i][i];
       }
    }
    qDebug()<<"skonczylem";


}
int LightnessRGB2GrayScale::convert1Pixel(QRgb rgb)
{

    QColor color(rgb);
    int result=std::min(std::min(color.red(), color.blue()), color.green());
    result+=std::max(std::min(color.red(), color.blue()), color.green());
    result=result/2;
    return result;

}




