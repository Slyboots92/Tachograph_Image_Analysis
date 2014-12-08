#ifndef POLARBASICIMPL_H
#define POLARBASICIMPL_H
#include "TachoImageAnalysis/TachoAnalysisLogic/tachoimageanalysismain.h"
#include "TachoImageAnalysis/TachoActivities/tachoactivitiy.h"
#include "TachoImageAnalysis/TachoActivities/tachodrivingactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachoworkingactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachostandbyactivity.h"
#include "TachoImageAnalysis/TachoActivities/tachorestactivity.h"
#include <vector>
#include <math.h>
#include <QDebug>
class PolarBasicImpl:public TachoImageAnalysisMain
{
public:
    PolarBasicImpl();
    std::vector<TachoActivitiy> getAllActivities(TachoImage *tacho);
};

#endif // POLARBASICIMPL_H
