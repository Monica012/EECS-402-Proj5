//Name: Nai Shih
//EECS project 5
//Date: 12/2018
//Purpose: Declares EventClass variables

#ifndef _EVENTCLASS_H_
#define _EVENTCLASS_H_

#include <iostream>
using namespace std;

class EventClass
{
private:
    int eventType;
    int time;
    int customerID;

public:
    //constructor
    EventClass();
    //customized constructor
    EventClass(int inEventType, int inTime, int inCustomerID);
    //return each event type
    int getEventType() const;
    //return each event starting time
    int getTime() const;
    //rerturn each customer's ID 
    int getCustomerID() const;
    //operation overloading to examine if it is 
    //past closed time 
    bool operator < (const EventClass &in) const;
    //operation overloading to examine if the event 
    //is past closed time 
    bool operator >= (const EventClass &in) const;
    //destructor 
    ~EventClass();
};

#endif
