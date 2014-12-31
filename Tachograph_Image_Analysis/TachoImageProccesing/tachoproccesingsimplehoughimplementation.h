#ifndef TACHOPROCCESINGSIMPLEHOUGHIMPLEMENTATION_H
#define TACHOPROCCESINGSIMPLEHOUGHIMPLEMENTATION_H
#include "TachoImageProccesing/tachoproccesingmain.h"

class TachoProccesingSimpleHoughImplementation : public TachoProccesingMain
{
public:
    TachoProccesingSimpleHoughImplementation();
    TachoImage* produceTachoImage2Analysis(std::string imagePath);
    ~TachoProccesingSimpleHoughImplementation();
};

#endif // TACHOPROCCESINGSIMPLEHOUGHIMPLEMENTATION_H
