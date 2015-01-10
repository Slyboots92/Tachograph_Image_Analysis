#include "cropimage.h"

CropImage::CropImage()
{

}

CropImage::~CropImage()
{

}
void  CropImage::cropImage(TachoImage * image,int x, int y,int width,int height)
 {



    int ** oldArray=image->getArray();
    int ** array = new int *[image->getHeight()];
    for(int i=0;i<height;i++)
    {
        array[i]= new int[width];
    }
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            array[i][j]=oldArray[i+y][j+x];
        }
    }
    image->setArray(array);
    delete[]oldArray;

}
