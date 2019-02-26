//Name: Nai Shih
//EECS402 proj5
//Date:12/2018
//Purpose: declares variables for simClass.cpp

#ifndef _RESTAURANTCLASS_H_
#define _RESTAURANTCLASS_H_

#include <string>
#include "constants.h"
#include "EventClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "random.h"
#include "readVal.h"
using namespace std;

class RestaurantClass
{
private:
    //A list stors each event
    SortedListClass< EventClass > eventList;
    //A list represents a queue
    FIFOQueueClass< EventClass > serveLine;
    //if the user input is valid
    bool isValid;
    //the percentage of cusomters who 
    //do not wan to wait 
    int percentage;
    //The num of ppl line which drives customers 
    //who are relectuat to wait away
    int pplLongLine;
    //the mean for normal distribution 
    int mean;
    //the sd for normal distribution 
    int sd;
    int closedTime;
    //the  max interval to generate 
    //next customer arrival
    int max;
    //the min interval to generate 
    //next customer arrival 
    int min;
    //the seed to generate random number
    int seed;
    //customers who left due to long waiting line
    int custLeft;
    //customers who show up
    int custNum;
    //if the server is busy or not
    bool isBusy;
    //the total time that server is busy
    int busyTime;
    //how many customer have to wait in line
    int custWaitNum;
    //the length of the longest line 
    int longestLine;
    //the total amount of time between each customer
    //arrival 
    int totoCustArrTime;
    //the total num of customer arrival events
    int totoCustArrEvent;
    //the longest interval time among each customer 
    //arrival event
    int longestArrTime;
    //the time of the last customer arrival event
    int lastCustTime;

public:
    //To get the next event in the eventlist 
    void getNext();
    //void setFirst();
    //read user's input into the simulation
    bool getInput(ifstream &inFileName);
    //
    int getEventListNum();
    //print out the stats
    void print();
    //the defualt constructor
    RestaurantClass();
};

#endif
