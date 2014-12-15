#ifndef TACHOIMAGEANALYSISMAIN_H
#define TACHOIMAGEANALYSISMAIN_H
#include <vector>
#include "TachoImageAnalysis/TachoActivities/tachoactivitiy.h"
#include "TachoImageShared/tachoimage.h"
class TachoImageAnalysisMain
{
public:
    //virtual std::vector<TachoActivitiy> getAllActivities(TachoImage *tacho)=0;
    virtual std::vector<TachoActivitiy*> getAllActivities(TachoImage *tacho)=0;
};

#endif // TACHOIMAGEANALYSISMAIN_H
