//Name: Nai Shih
//EECS proj5
//Date: 12/2018
//Purpose: examines what the next event is

#include "RestaurantClass.h"
#include "readVal.h"

using namespace std;

//initilize varibles 
RestaurantClass::RestaurantClass()
{
    isBusy = false;
    percentage = 0;
    pplLongLine = 0;
    mean = 0;
    sd = 0;
    closedTime = 0;
    max = 0;
    min = 0;
    seed = 0;
    custLeft = 0;
    custNum = 0;
    custNum = 0;
    longestLine = 0;
    totoCustArrTime = 0;
    totoCustArrEvent = 0;
    longestArrTime = 0;
}

bool RestaurantClass::getInput(ifstream &inFileName)
{
    if (readVal(inFileName, percentage) == false)
    {
        cout << "The value of the percentage that ppl " <<\
             "do not want to  wait in line  is invalid!\n";
        isValid = false;
    }
    else if (readVal(inFileName, pplLongLine) == false)
    {
        cout << "The value of number of people in long line is invalid.\n";
        isValid = false;

    }
    else if (readVal(inFileName, mean) == false)
    {
        cout << "The mean value for a server to wait " <<\
             "on a customeris invalid.\n";
        isValid = false;
    }
    else if (readVal(inFileName, sd) == false)
    {
        cout << "The sd value for a server to " <<\
             "wait on a customer is invalid.\n";
    }
    else if (readVal(inFileName, closedTime) == false)
    {
        cout << "The closedTime of a restaurant value is invalid.\n";
        isValid = false;
    }
    else if (readVal(inFileName, max) == false)
    {
        cout << "The max value between customer time is invalid.\n";
        isValid = false;
    }
    else if (readVal(inFileName, min) == false)
    {
        cout << "The min value between customer time  is invalid.\n";
        isValid = false;
    }
    else if (readVal(inFileName, seed) == false)
    {
        cout << "The seed value is invalid.\n";
        isValid = false;
    }
    else
    {
        //if all user's inputs are valid, then set up a seed and 
        //begin the simulation
        cout << "The percentage value is: " << percentage << endl
             << "The value of number of people in long line is: "
             << pplLongLine << endl
             << "The mean value for a server to wait on a customer: "
             << mean << endl
             << "The sd value for a server to wait on a customer: "
             << sd << endl
             << "The closed time of a restaurant: "
             << closedTime << endl
             << "The max value between customer time: "
             << max << endl
             << "The min value between customer time: "
             << min << endl
             << "The seed value: " << seed << endl
             << "The simulation will begin!\n";
        setSeed(seed);
        isValid = true;
    }
    return isValid;

}

/*
void RestaurantClass::setFirst()
{
    EventClass event(CUST_ARRIVAL, 0, 0);
    eventList.insertValue(event);
    totoCustArrEvent = totoCustArrEvent + 1;
}
*/

void RestaurantClass::getNext()
{
    cout << "**********************************\n";
    //check if there is other events waiting in the eventlist
    if (getEventListNum() == 0)
    {
        //first customer arrival event 
        EventClass event(CUST_ARRIVAL, 0, 0);
        // add the first customer arrival evnet 
        // into the eventlist 
        eventList.insertValue(event);
        totoCustArrEvent = totoCustArrEvent + 1;
    }
    else
    {
        EventClass event;
        //if there is another event waiting in the eventlist,
        //remove the first one out of the eventlist and deal with
        //it
        eventList.removeFront(event);
        if (event.getEventType() == CUST_ARRIVAL)
        {
            cout << "A customer just arrived!" << endl;
            if (event.getTime() > closedTime)
            {
                cout << "Reject this customer since" << \
                    "the restaurant was closed.\n";
                totoCustArrEvent = totoCustArrEvent + 1;
            }
            else
            {
                //the customer arrives in the opening time
                //once we start deal with customer arrival event,
                //we should start to schedule next customer arrival
                //event.
                int nextArrTime = getUniform(min, max);
                EventClass event2(CUST_ARRIVAL, event.getTime() + \
                                  nextArrTime, event.getCustomerID() + 1);
                eventList.insertValue(event2);
                totoCustArrTime = totoCustArrTime + nextArrTime;
                totoCustArrEvent = totoCustArrEvent + 1;
                //test the longest arrival interval between 
                //each customer arrival 
                if (nextArrTime > longestArrTime)
                {
                    longestArrTime = nextArrTime;
                }
            }
            //dosent work
            /*
            if (serveLine.getNumElems() != 0)
            {
                if (getUniform(0, 100) < percentage)
                {
                    if (serveLine.getNumElems() <= pplLongLine)
                    {
                        EventClass event2(CUST_ENQUEUE, event.getTime(), \
                        event.getCustomerID());
                        eventList.insertValue(event2);
                    }
                    else
                    {

                        cout << "The customer left!\n";
                        custLeft = custLeft + 1;
                    }
                }
                else
                {
                    EventClass event2(CUST_ENQUEUE, event.getTime(), \
                    event.getCustomerID());
                    eventList.insertValue(event2);

                 }
            }
            else
            {
                if (isBusy == true)
                {
                    EventClass event2(CUST_ENQUEUE, event.getTime(), \
                    event.getCustomerID());
                    eventList.insertValue(event2);
                }
                else
                {
                    EventClass event2(SERVICE_STARTED, event.getTime(), \
                    event.getCustomerID());
                    eventList.insertValue(event2);
                }
            }
            */
            //doesnt work end
            //check if the server is busy serving customers.
            //The server not being busy indicates he is done serveing 
            //the previous customer, which means he is a fast server.
            if (isBusy == false)
            {
                //server is done serving the previous customer, so he can
                //start take next customer
                EventClass event2(SERVICE_STARTED, event.getTime(), \
                                  event.getCustomerID());
                eventList.insertValue(event2);
            }
            else
            {
                //server being busy indicates he is with a customer 
                //right now,
                //so we should check if the new customer wants to get 
                //in line or not
                if (getUniform(0, 100) < percentage)
                {
                    if (serveLine.getNumElems() <= pplLongLine)
                    {
                        EventClass event2(CUST_ENQUEUE, event.getTime(),\
                                          event.getCustomerID());
                        eventList.insertValue(event2);
                    }
                    else
                    {
                        cout << "The customer left due to line length!\n";
                        custLeft = custLeft + 1;
                    }
                }
                //the customers who are paitient with waiting 
                else
                {
                    EventClass event2(CUST_ENQUEUE, event.getTime(), \
                                      event.getCustomerID());
                    eventList.insertValue(event2);
                }
            }
            custNum = custNum + 1;
        }
        //once the service starts, we should generate 
        //a serve done event, so that we can know 
        //the served period for this service event
        if (event.getEventType() == SERVICE_STARTED)
        {
            isBusy = true;
            cout << "The customer got served! " << endl;
            int serveTime = getNormal(mean, sd);
            EventClass event2(SERVICE_DONE, event.getTime() + serveTime, \
                              event.getCustomerID());
            eventList.insertValue(event2);
            busyTime =  busyTime + serveTime;
        }
        //once the service is done, we should dequeue an await customer
        //in line
        if (event.getEventType() == SERVICE_DONE)
        {
            cout << "The current service is done.\n";
            if (serveLine.getNumElems() != 0)
            {
                EventClass event2;
                serveLine.dequeue(event2);
                EventClass event3(SERVICE_STARTED, event.getTime(), \
                                  event2.getCustomerID());
                eventList.insertValue(event3);

            }
            else
            {
                isBusy = false;
            }
        }

        if (event.getEventType() == CUST_ENQUEUE)
        {
            serveLine.enqueue(event);
            cout << "The customer got in line\n";
            custWaitNum = custWaitNum + 1;
        }
        //get the longest number in line
        if (serveLine.getNumElems() > longestLine)
        {
            longestLine = serveLine.getNumElems();
        }
        cout << "The current event time: " << event.getTime() << endl;
        cout << "The number of people in queue: " << serveLine.getNumElems() \
             << endl;
        cout << "The current customerID: " << event.getCustomerID() << endl;
        cout << " is server busy? " << isBusy << endl;
        cout << " number of event list: " << getEventListNum() << endl;
        cout << "**********************************\n";
        lastCustTime = event.getTime();
    }
}

int RestaurantClass::getEventListNum()
{
    return eventList.getNumElems();
}

void RestaurantClass::print()
{
    double serverBusyPercent = double(busyTime) / double(lastCustTime);
    double custWaitNumPercent = double(custWaitNum) / double(custNum);
    double meanCustArrTime = double(totoCustArrTime) / double(totoCustArrEvent);
    cout << "Total number of customers that showed up: " << custNum << endl;
    cout << "Percentage of time the server was busy helping customers: " \
         << serverBusyPercent << endl;
    cout << "Percentage of customers had to wait in line: " \
         << custWaitNumPercent << endl;
    cout << "The number of customers that arrived, but left due to excessive" << \
        "line length: " << custLeft << endl;
    cout << "The longest the line was throughout the simulation: " \
         << longestLine << endl;
    cout << "The mean customer arrival time: " << meanCustArrTime << endl;
    cout << "The longest customer arrival time: " << longestArrTime << endl;
}







