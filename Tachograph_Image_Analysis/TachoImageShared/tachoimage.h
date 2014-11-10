#ifndef TACHOIMAGE_H
#define TACHOIMAGE_H
#include <QImage>
class TachoImage
{
public:

    TachoImage();
    TachoImage(QImage * image);
    void setWidth(int width)
    {
        this->width=width;
    }
    void setHeight(int height)
    {
        this->height=height;
    }
    void setGrayScale(int grayScale)
    {
        this->gray_scale=grayScale;
    }
    void setArray( int ** array)
    {
        this->array=array;
    }

    int getWidth()
    {
        return width;
    }
    int getHeight()
    {
        return height;
    }
    int getGrayScale()
    {
        return gray_scale;
    }
     int ** getArray()
    {
        return array;
    }


private:
    int width;
    int height;
    int gray_scale;
     int **array;
};

#endif // TACHOIMAGE_H
