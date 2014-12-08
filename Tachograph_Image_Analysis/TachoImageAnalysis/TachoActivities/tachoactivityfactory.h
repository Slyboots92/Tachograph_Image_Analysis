#ifndef TACHOACTIVITYFACTORY_H
#define TACHOACTIVITYFACTORY_H
#include <stdexcept>
#include "tachoactivitiy.h"
#include "tachodrivingactivity.h"
#include "tachoworkingactivity.h"
#include"tachostandbyactivity.h"
#include"tachorestactivity.h"
class TachoActivityFactory
{
public:

    virtual TachoActivitiy* produceTachoActivtiy(int choose)=0;

};

#endif // TACHOACTIVITYFACTORY_H




