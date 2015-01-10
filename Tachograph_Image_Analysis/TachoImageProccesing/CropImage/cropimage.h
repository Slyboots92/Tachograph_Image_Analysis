#ifndef CROPIMAGE_H
#define CROPIMAGE_H
#include "TachoImageShared/tachoimage.h"

class CropImage
{
public:
    CropImage();
    ~CropImage();
    void cropImage(TachoImage * image,int x, int y,int width,int height);
};

#endif // CROPIMAGE_H
