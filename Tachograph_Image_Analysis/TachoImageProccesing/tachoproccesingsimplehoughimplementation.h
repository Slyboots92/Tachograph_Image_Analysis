#ifndef TACHOPROCCESINGSIMPLEHOUGHIMPLEMENTATION_H
#define TACHOPROCCESINGSIMPLEHOUGHIMPLEMENTATION_H
#include "TachoImageProccesing/tachoproccesingmain.h"
#include "TachoImageProccesing/CirclesDetection/circledetection.h"
#include "TachoImageProccesing/ComputeHelper/simplehoughcomputehelper.h"
#include "TachoImageProccesing/ColorReduction/averagergb2grayscale.h"
#include "TachoImageProccesing/ColorReduction/imagecolorreduction.h"
#include "TachoImageProccesing/ColorReduction/lightnessrgb2grayscale.h"
#include "TachoImageProccesing/ColorReduction/luminosityrgb2grayscale.h"
#include "TachoImageProccesing/CropImage/cropimage.h"
class TachoProccesingSimpleHoughImplementation : public TachoProccesingMain
{
public:
    TachoProccesingSimpleHoughImplementation();
    TachoImage* produceTachoImage2Analysis(std::string imagePath);
    ~TachoProccesingSimpleHoughImplementation();
};

#endif // TACHOPROCCESINGSIMPLEHOUGHIMPLEMENTATION_H
