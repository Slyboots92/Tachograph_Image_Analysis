#ifndef RGB2GRAYLIGHTNESSALGO_H
#define RGB2GRAYLIGHTNESSALGO_H
#include "rgb2grayalgo.h"
class RGB2GrayLightnessAlgo: public RGB2GrayAlgo
{
public:
  //  RGB2GrayLightnessAlgo();
    short int  computeGrayColorFromRGB(int red,int green,int blue);

private:
    int short max( short int red,short int green,short int blue);
     int short min( short int red,short int green,short int blue);
};

#endif // RGB2GRAYLIGHTNESSALGO_H
