#include "rgb2graylightnessalgo.h"

//RGB2GrayLightnessAlgo::RGB2GrayLightnessAlgo(): RGB2GrayAlgo()
//{
//}
short int  RGB2GrayLightnessAlgo::computeGrayColorFromRGB(int red,int green,int blue){
    return 0;
}

int short max( short int red,short int green,short int blue){

    if( red>=green ){
        if(red>=blue){
            return red;
        }
        else{
            return blue;
        }
    }
    else{
        if(green>=blue){
            return green;
        }
        else{
            return blue;
        }
    }
}
int short min( short int red,short int green,short int blue){

    if( red<=green ){
        if(red<=blue){
            return red;
        }
        else{
            return blue;
        }
    }
    else{
        if(green<=blue){
            return green;
        }
        else{
            return blue;
        }
    }
}
