#ifndef CROPIMAGE_H
#define CROPIMAGE_H
#include "TachoImageShared/tachoimage.h"
class CropImage
{
public:
    CropImage();
    virtual TachoImage * cropImage(TachoImage *)=0;
};

#endif // CROPIMAGE_H
