#ifndef TACHOIMAGEANALYSISRINGIMPLEMENTATION_H
#define TACHOIMAGEANALYSISRINGIMPLEMENTATION_H
#include "TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"
#include <math.h>
#include <QDebug>

class TachoImageAnalysisRingImplementation:public TachoImageAnalysisMain
{
public:
    TachoImageAnalysisRingImplementation();
    std::vector<TachoActivitiy> getAllActivities(TachoImage *tacho);
};

#endif // TACHOIMAGEANALYSISRINGIMPLEMENTATION_H
