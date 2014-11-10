#ifndef TACHOIMAGEANALYSISRINGIMPLEMENTATION_H
#define TACHOIMAGEANALYSISRINGIMPLEMENTATION_H
#include "TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"

class TachoImageAnalysisRingImplementation:public TachoImageAnalysisMain
{
public:
    TachoImageAnalysisRingImplementation();
    std::vector<TachoActivitiy> getAllActivities(TachoImage *tacho);
};

#endif // TACHOIMAGEANALYSISRINGIMPLEMENTATION_H
