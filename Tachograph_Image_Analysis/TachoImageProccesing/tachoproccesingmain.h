#ifndef TACHOPROCCESINGMAIN_H
#define TACHOPROCCESINGMAIN_H
#include "TachoImageShared/tachoimage.h"
#include <string>
class TachoProccesingMain
{
public:
    virtual TachoImage* produceTachoImage2Analysis(std::string imagePath)=0;
};

#endif // TACHOPROCCESINGMAIN_H
