#ifndef TACHOIMAGE_H
#define TACHOIMAGE_H
#include <QImage>
class TachoImage
{
public:
    enum RGB2GrayAlgo{Lightness, Average,Luminosity};
    TachoImage();
    TachoImage(QImage *image,RGB2GrayAlgo algo);
private:
    int width;
    int height;
    int gray_scale;
    short int **array;
};

#endif // TACHOIMAGE_H
