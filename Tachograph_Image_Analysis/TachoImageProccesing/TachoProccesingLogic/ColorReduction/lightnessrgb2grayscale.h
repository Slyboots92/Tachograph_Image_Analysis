#ifndef LIGHTNESSRGB2GRAYSCALE_H
#define LIGHTNESSRGB2GRAYSCALE_H
#include "imagecolorreduction.h"
class LightnessRGB2GrayScale: public ImageColorReduction
{
public:
    LightnessRGB2GrayScale();

    void reduceColor(QImage * image,TachoImage *tachoImage);


private:
     int convert1Pixel(QRgb color);

};


#endif // LIGHTNESSRGB2GRAYSCALE_H
