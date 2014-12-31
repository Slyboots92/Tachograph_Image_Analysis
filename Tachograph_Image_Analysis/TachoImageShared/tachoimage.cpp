#include "tachoimage.h"

TachoImage::TachoImage()
{
}

TachoImage::TachoImage(QImage *image)
{
    this->setWidth(image->width());
    this->setHeight(image->height());
    this->setGrayScale(256);
    int  **array= new  int *[image->height()];
    for(int i=0;i<image->height();i++)
    {
        array[i]=new  int[image->width()];
    }
    this->setArray(array);
}
int TachoImage::getXCenterCordOnRawImage() const
{
    return xCenterCordOnRawImage;
}

void TachoImage::setXCenterCordOnRawImage(int value)
{
    xCenterCordOnRawImage = value;
}
int TachoImage::getYCenterCordOnRawImage() const
{
    return yCenterCordOnRawImage;
}

void TachoImage::setYCenterCordOnRawImage(int value)
{
    yCenterCordOnRawImage = value;
}
int TachoImage::getMainCircleRadius() const
{
    return mainCircleRadius;
}

void TachoImage::setMainCircleRadius(int value)
{
    mainCircleRadius = value;
}






