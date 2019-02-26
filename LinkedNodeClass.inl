//Name: Nai Shih
//EECS project4
//Date: 11/2018
//Purpose: compose Linkednodeclass functions

#include "LinkedNodeClass.h"


using namespace std;

template <class T >
LinkedNodeClass< T >::LinkedNodeClass(LinkedNodeClass< T >* inPrev, const T &inVal, \
                                      LinkedNodeClass< T >* inNext)
{
    prevNode = inPrev;
    nodeVal = inVal;
    nextNode = inNext;
}

template <class T >
T LinkedNodeClass< T >::getValue() const
{
    return nodeVal;
}

template <class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getNext() const
{
    return nextNode;
}

template <class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getPrev() const
{
    return prevNode;
}

template <class T >
void LinkedNodeClass< T >::setNextPointerToNull()
{
    nextNode = 0;
}

template <class T >
void LinkedNodeClass< T >::setPreviousPointerToNull()
{
    prevNode = 0;
}

template <class T >
void LinkedNodeClass< T >::setBeforeAndAfterPointers()
{
    //points mutually
    if (prevNode != 0)
    {
        prevNode->nextNode = this;
    }
    if (nextNode != 0)
    {
        nextNode->prevNode = this;
    }
}
