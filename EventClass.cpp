//Name: Nai Shih
//EECS project5
//Date: 12/2018
//Purpose: define eventClass function
#include "EventClass.h"

EventClass::EventClass()
{
}

//Initialize vairables
EventClass::EventClass(int inEventType, int inTime, int inCustomerID)
{
    eventType = inEventType;
    time = inTime;
    customerID = inCustomerID;
}


int EventClass::getEventType() const
{
    return eventType;
}


int EventClass::getTime() const
{
    return time;
}


int EventClass::getCustomerID() const
{
    return customerID;
}

//check if the event is still in opening time
bool EventClass::operator < (const EventClass &in) const
{
    if (time < in.time)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check if the event is past closed time 
bool EventClass::operator >= (const EventClass &in) const
{
    if (time >= in.time)
    {
        return true;
    }
    else
    {
        return false;
    }
}


EventClass::~EventClass()
{
}
