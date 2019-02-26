//Name: Nai Shih
//EECS project4
//Date: 11/2018
//Purpose:declares sortedlistclass vairables/functions


#ifndef _SortedListClass_TEMPLATE_H_
#define _SortedListClass_TEMPLATE_H_


//The sorted list class does not store any data directly. Instead,
//it contains a collection
//contains one element.


#include <iostream>
#include "LinkedNodeClass.h"
using namespace std;

template < class T >
class SortedListClass
{
private:
    LinkedNodeClass< T > *head;
    LinkedNodeClass< T > *tail;

public:
    //Default Constructor
    SortedListClass();
    //Copy constructor
    SortedListClass(const SortedListClass< T > &rhs);
    //Destructor
    ~SortedListClass();
    //Clears the list
    //memory leaks.
    void clear();
    //Allows the user to insert a value into the list
    void insertValue(const T &valtoinsert);
    //Prints the contents of the list
    //from head to tail to the screen.
    void printForward() const;
    //Prints the contents of the list
    //from tail to head to the screen.
    void printBackward() const;
    //Removes the front item from the list and returns the value that
    ////was contained in it via the reference parameter.
    bool removeFront(T &theval);
    //Removes the last item from the list and returns the value that
    //was contained in it via the reference parameter.
    bool removeLast(T &theVal);
    //Returns the number of nodes contained in the list.
    int getNumElems() const;
    //Provides the value stored in the node at index provided in the
    ////0-based "index" parameter.
    bool getElemAtIndex(const int index, T &outVal) const;
};

#include "SortedListClass.inl"
#endif
