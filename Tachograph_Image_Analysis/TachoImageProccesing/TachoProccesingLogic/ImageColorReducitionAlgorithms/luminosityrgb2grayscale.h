#ifndef LUMINOSITYRGB2GRAYSCALE_H
#define LUMINOSITYRGB2GRAYSCALE_H
#include"imagecolorreduction.h"

class LuminosityRGB2GrayScale: public ImageColorReduction
{
public:
    LuminosityRGB2GrayScale();
    void reduceColor(QImage * image,TachoImage *tachoImage);


private:
    int convert1Pixel(QRgb color);

};



#endif // LUMINOSITYRGB2GRAYSCALE_H
