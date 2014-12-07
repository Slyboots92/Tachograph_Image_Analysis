#ifndef AVERAGERGB2GRAYSCALE_H
#define AVERAGERGB2GRAYSCALE_H
#include"imagecolorreduction.h"

class AverageRGB2GrayScale: public ImageColorReduction
{
public:

    void reduceColor(QImage * image,TachoImage *tachoImage);


private:
     int convert1Pixel(QRgb color);

};

#endif // AVERAGERGB2GRAYSCALE_H
