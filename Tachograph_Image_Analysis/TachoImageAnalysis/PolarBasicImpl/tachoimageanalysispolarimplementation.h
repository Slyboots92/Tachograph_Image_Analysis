#ifndef TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
#define TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
#include "TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"
#include "TachoImageAnalysis/TachoActivities/tachoactivitiy.h"
#include "TachoImageAnalysis/TachoActivities/tachodrivingactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachoworkingactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachostandbyactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachorestactivity.h"
#include "TachoImageAnalysis/TachoActivities/polarbasictachoactivityfactory.h"
#include <vector>
#include <math.h>
#include <QDebug>
#include <cstddef>
#include <iostream>
#include <cstddef>
class TachoImageAnalysisPolarImplementation:public TachoImageAnalysisMain
{
public:
    TachoImageAnalysisPolarImplementation();
    //std::vector<TachoActivitiy> getAllActivities(TachoImage *tacho);
    std::vector<TachoActivitiy*>getAllActivities(TachoImage *tacho);
private:
int ** transformRing2Rectangle(TachoImage * tacho,int resolution);
int *validateActivity();
int decideWhichActivity(int counter,int buffSize);
int countBlackPixelInBuff(int * buff,int length);
int *scanRectangle(int **rectangleWithActivities,int resolution,int length);
void markActivities (int * activities,int resolution,QImage * image);
std::vector<TachoActivitiy*> createAndComputeActivityDetails(int *activities,int resolution);
static const double STAND_BY_TRESHOLD=0.25;
static const double ANOTHER_WORK_TRESHOLD=0.7;
static const double DRIVE_TRESHOLD=0.85;
static const int BLACK_POINT_TRESHOLD=100;

};

#endif // TACHOIMAGEANALYSISPOLARIMPLEMENTATION_H
