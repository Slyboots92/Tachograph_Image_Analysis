#ifndef TACHOACTIVITIY_H
#define TACHOACTIVITIY_H

class TachoActivitiy
{
public:
    TachoActivitiy();
    int getEndTimeInMin() const;
    void setEndTimeInMin(int value);

    int getStartTimeInMin() const;
    void setStartTimeInMin(int value);

    int getDuringTimeInMin() const;
    void setDuringTimeInMin(int value);

protected:
    int duringTimeInMin;
    int startTimeInMin;
    int endTimeInMin;
};


int TachoActivityFactory::getEndTimeInMin() const
{
return endTimeInMin;
}

void TachoActivityFactory::setEndTimeInMin(int value)
{
endTimeInMin = value;
}
int TachoActivityFactory::getStartTimeInMin() const
{
return startTimeInMin;
}

void TachoActivityFactory::setStartTimeInMin(int value)
{
startTimeInMin = value;
}
int TachoActivityFactory::getDuringTimeInMin() const
{
return duringTimeInMin;
}

void TachoActivityFactory::setDuringTimeInMin(int value)
{
duringTimeInMin = value;
}
#endif // TACHOACTIVITIY_H
