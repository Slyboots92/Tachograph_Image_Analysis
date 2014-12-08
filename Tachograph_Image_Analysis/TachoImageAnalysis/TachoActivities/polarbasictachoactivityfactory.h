#ifndef POLARBASICTACHOACTIVITYFACTORY_H
#define POLARBASICTACHOACTIVITYFACTORY_H
#include"tachoactivityfactory.h"
class PolarBasicTachoActivityFactory : public TachoActivityFactory
{
public:
    PolarBasicTachoActivityFactory();
    TachoActivitiy* produceTachoActivtiy(int choose);
};

#endif // POLARBASICTACHOACTIVITYFACTORY_H
