#ifndef IMAGECOLORREDUCTION_H
#define IMAGECOLORREDUCTION_H
#include "QImage"
#include <QColor>
#include "TachoImageShared/tachoimage.h"
#include <QDebug>
class ImageColorReduction
{
public:
    ImageColorReduction();
    virtual void reduceColor(QImage * image,TachoImage *tachoImage)=0;
};

#endif // IMAGECOLORREDUCTION_H
