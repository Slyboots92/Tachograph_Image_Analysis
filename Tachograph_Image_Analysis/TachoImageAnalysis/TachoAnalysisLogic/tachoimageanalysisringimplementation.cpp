#include "tachoimageanalysisringimplementation.h"

TachoImageAnalysisRingImplementation::TachoImageAnalysisRingImplementation()
{
}

std::vector<TachoActivitiy> TachoImageAnalysisRingImplementation::getAllActivities(TachoImage *tacho)
{
std::vector<TachoActivitiy> result;
int ** array =tacho->getArray();
for(int i=0;i<tacho->getWidth();i++)
{
    array[tacho->getHeight()/2  -105][i]=0;
}
for(int i=0;i<tacho->getHeight();i++)
{
    array[i][tacho->getWidth()/2 +155]=0;
}



return result;
}
