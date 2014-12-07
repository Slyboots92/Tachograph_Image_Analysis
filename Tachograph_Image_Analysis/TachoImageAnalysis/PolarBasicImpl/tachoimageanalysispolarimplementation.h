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
int findTranslationToStartScaning(TachoImage * tachoImage,int resolution,int r1,int r2,int a ,int b);
std::vector<TachoActivitiy> scanCircle(TachoImage * tachoImage,int resolution,double translation,int r1,int r2,int a,int b);
int validateActivity(int buff[],int length,double param1,double param2,double param3,double treshold);

};

#endif // TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
