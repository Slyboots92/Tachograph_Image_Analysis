#ifndef BASICCROPIMAGEIMPL_H
#define BASICCROPIMAGEIMPL_H
#include "TachoImageProccesing/CropImage/cropimage.h"
class BasicCropImageImpl:public CropImage
{
public:
    BasicCropImageImpl();
    TachoImage * cropImage(TachoImage *);
};

#endif // BASICCROPIMAGEIMPL_H
