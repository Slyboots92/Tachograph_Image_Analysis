#include "polarbasicimpl.h"

PolarBasicImpl::PolarBasicImpl()
{
}

std::vector<TachoActivitiy> PolarBasicImpl::getAllActivities(TachoImage *tacho)
{

    ////////////////tests
std::vector<TachoActivitiy> result;
int ** array =tacho->getArray();
for(int i=0;i<tacho->getWidth();i++)
{
    array[tacho->getHeight()/2][i]=0;
}
for(int i=0;i<tacho->getHeight();i++)
{
    array[i][tacho->getWidth()/2]=0;
}


int a=tacho->getHeight()/2;
int b=tacho->getWidth()/2;
int r1=363;
int r2=387;
int x1;
int y1;

///////////////////
// TODO
//scanCircle(tacho,4,0,r1,r2,a,b);

return result;
}
