//Name: Nai Shih
//EECS project4
//Date: 11/2018
//Purpose: Declares FIFOQueue variables


#ifndef _FIFOQUEUECLASS_TEMPLATE_H_
#define _FIFOQUEUECLASS_TEMPLATE_H_

#include <iostream>
using namespace std;

template < class T >
class FIFOQueueClass
{
private:
    LinkedNodeClass< T > *head;
    LinkedNodeClass< T > *tail;

public:
    //Default constructor. Initialize the queue to zero.
    FIFOQueueClass();
    //Destructor. freed up any dynamic memory is freed up when the
    //object is being destroyed.
    ~FIFOQueueClass();
    //Insert the value provided into the queue.
    void enqueue(const T &newItem);
    //Attemps to take the next item out of the queue.
    bool dequeue(T &outItem);
    //Print out the contents of the queue.
    void print() const;
    //returns the number of nodes contained in the queue.
    int getNumElems() const;
    //Clears the queue to an empty state without resulting in any
    //memory leaks.
    void clear();
};

#include "FIFOQueueClass.inl"
#endif
