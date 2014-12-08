#ifndef POLARBASICACTIVITYSEARCHER_H
#define POLARBASICACTIVITYSEARCHER_H
#include <vector>
#include <math.h>
#include <QDebug>
#include"TachoImageShared/tachoimage.h"
#include"TachoImageAnalysis/TachoActivities/tachoactivitiy.h"
#include"TachoImageAnalysis/TachoActivities/tachodrivingactivity.h"
#include"TachoImageAnalysis/TachoActivities/tachorestactivity.h"
#include"TachoImageAnalysis/TachoActivities/tachostandbyactivity.h"
#include"TachoImageAnalysis/TachoActivities/tachoworkingactivity.h"
#include "TachoImageAnalysis/TachoActivities/polarbasictachoactivityfactory.h"

class PolarBasicActivitySearcher
{
public:
    PolarBasicActivitySearcher();
    std::vector<TachoActivitiy*> getAllActivities(TachoImage *tacho);

private:
    int validateActivity(int buff[],int length,double param1,double param2,double param3,double treshold);
    int computeDataFromBuffor(int buff[],int length,double treshold);
    int decideWhichActivity(int counter,int length,double param1,double param2,double param3);
    void finishOldActivity(TachoActivitiy * oldActivity,int currentMin);
    TachoActivitiy * createNewActivtiy(int choose,int currentMin,TachoActivityFactory *factory);


};
#endif // POLARBASICACTIVITYSEARCHER_H
