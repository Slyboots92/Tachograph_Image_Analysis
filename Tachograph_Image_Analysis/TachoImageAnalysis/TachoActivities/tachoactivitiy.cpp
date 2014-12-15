#include "tachoactivitiy.h"

TachoActivitiy::TachoActivitiy()
{
}

int TachoActivitiy::getEndTimeInMin() const
{
return endTimeInMin;
}

void TachoActivitiy::setEndTimeInMin(int value)
{
endTimeInMin = value;
}
int TachoActivitiy::getStartTimeInMin() const
{
return startTimeInMin;
}

void TachoActivitiy::setStartTimeInMin(int value)
{
startTimeInMin = value;
}
int TachoActivitiy::getDuringTimeInMin() const
{
return duringTimeInMin;
}

void TachoActivitiy::setDuringTimeInMin(int value)
{
duringTimeInMin = value;
}
