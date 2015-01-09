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
int TachoImage::getSmallMainCircleRadius() const
{
    return smallMainCircleRadius;
}

void TachoImage::setSmallMainCircleRadius(int value)
{
    smallMainCircleRadius = value;
}
int TachoImage::getSecondSmallCircleXCord() const
{
    return secondSmallCircleXCord;
}

void TachoImage::setSecondSmallCircleXCord(int value)
{
    secondSmallCircleXCord = value;
}
int TachoImage::getSecondSmallCircleYCord() const
{
    return secondSmallCircleYCord;
}

void TachoImage::setSecondSmallCircleYCord(int value)
{
    secondSmallCircleYCord = value;
}
int TachoImage::getSecondSmallCircleRadius() const
{
    return secondSmallCircleRadius;
}

void TachoImage::setSecondSmallCircleRadius(int value)
{
    secondSmallCircleRadius = value;
}
double TachoImage::getRotation() const
{
    return rotation;
}

void TachoImage::setRotation(double value)
{
    rotation = value;
}











