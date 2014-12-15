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



