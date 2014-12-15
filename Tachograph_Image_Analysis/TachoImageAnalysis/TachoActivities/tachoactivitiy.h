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

   virtual int getType()=0;

protected:
    int duringTimeInMin;
    int startTimeInMin;
    int endTimeInMin;

};



#endif // TACHOACTIVITIY_H
