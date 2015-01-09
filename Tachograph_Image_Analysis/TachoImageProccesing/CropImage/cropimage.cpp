#include "cropimage.h"

CropImage::CropImage()
{

}

CropImage::~CropImage()
{

}
void  CropImage::cropImage(TachoImage * image,int x, int y)
 {



    int ** oldArray=image->getArray();
    int ** array = new int *[image->getHeight()];
    for(int i=0;i<image->getHeight();i++)
    {
        array[i]= new int[image->getWidth()];
    }
    for(int i=0;i<image->getHeight();i++)
    {
        for(int j=0;j<image->getWidth();j++)
        {
            array[i][j]=oldArray[i+y][j+x];
        }
    }
    image->setArray(array);
    //delete[]oldArray;

}
