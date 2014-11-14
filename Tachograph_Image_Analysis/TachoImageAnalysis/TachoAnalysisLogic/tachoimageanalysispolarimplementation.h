#ifndef TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
#define TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
#include "TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"
#include "TachoImageAnalysis/TachoActivities/tachoactivitiy.h"
#include "TachoImageAnalysis/TachoActivities/tachodrivingactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachoworkingactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachostandbyactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachorestactivity.h"
#include <vector>
#include <math.h>
#include <QDebug>
class TachoImageAnalysisPolarImplementation:public TachoImageAnalysisMain
{
public:
    TachoImageAnalysisPolarImplementation();
    std::vector<TachoActivitiy> getAllActivities(TachoImage *tacho);
private:
TachoActivitiy* validateActivity(int *array,int length);

std::vector<TachoActivitiy> checkCircle(int **array,int width,int height,int r1,int r2,int a,int b,double resoultion);

std::vector<TachoActivitiy> correctDelayCausedRatation( std::vector<TachoActivitiy> activities,double fi);

};

#endif // TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
