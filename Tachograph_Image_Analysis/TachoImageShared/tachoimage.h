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


     int getActivityExternalRadius() const
     {
        return activityExternalRadius;
     }
     void setActivityExternalRadius(int value)
     {
            this->activityExternalRadius=value;
     }

     int getActivityInternalRadius() const
     {
        return activityInternalRadius;
     }
     void setActivityInternalRadius(int value)
     {
        this->activityInternalRadius=value;
     }
     int getYCenterCord() const
     {
           return yCenterCord;
     }
     void setYCenterCord(int value)
     {
            this->yCenterCord=value;
     }
     int getXCenterCord() const
     {
            return xCenterCord;
     }
     void setXCenterCord(int value)
     {
            this->xCenterCord=value;
     }

     int getXCenterCordOnRawImage() const;
     void setXCenterCordOnRawImage(int value);

     int getYCenterCordOnRawImage() const;
     void setYCenterCordOnRawImage(int value);

     int getMainCircleRadius() const;
     void setMainCircleRadius(int value);

     int getSmallMainCircleRadius() const;
     void setSmallMainCircleRadius(int value);

     int getSecondSmallCircleXCord() const;
     void setSecondSmallCircleXCord(int value);

     int getSecondSmallCircleYCord() const;
     void setSecondSmallCircleYCord(int value);

     int getSecondSmallCircleRadius() const;
     void setSecondSmallCircleRadius(int value);

     double getRotation() const;
     void setRotation(double value);

private:
     int width;
     int height;
     int gray_scale;
     int **array;
     int xCenterCord;
     int yCenterCord;
    int activityInternalRadius;
    int activityExternalRadius;
    int xCenterCordOnRawImage;
    int yCenterCordOnRawImage;
    int mainCircleRadius;
    int smallMainCircleRadius;
    int secondSmallCircleXCord;
    int secondSmallCircleYCord;
    int secondSmallCircleRadius;
    double rotation;
};

#endif // TACHOIMAGE_H
