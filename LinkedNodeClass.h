//Name: Nai Shih
//EECS project4
//Date: 11/2018
//Purpose: declares Linkednodeclass variables/functions


#ifndef _LINKEDNODECLASS_H_
#define _LINKEDNODECLASS_H_

#include <iostream>
using namespace std;

template < class T >

class LinkedNodeClass
{
private:
    LinkedNodeClass< T >* prevNode;
    T nodeVal;
    LinkedNodeClass< T >* nextNode;

public:
    //The ONLY constructor for the linke node class
    LinkedNodeClass(LinkedNodeClass< T >* inPrev, const T &inVal, \
                    LinkedNodeClass< T >* inNext);
    //Returns the value stored within this node.
    T getValue() const;
    //Returns the address of the node that follows this node.
    LinkedNodeClass< T >* getNext() const;
    //Returns the address of the node
    //that comes before this node.
    LinkedNodeClass< T >* getPrev() const;
    //Sets the object’s next node
    //pointer to NULL.
    void setNextPointerToNull();
    //Sets the object's previous
    //node pointer to NULL.
    void setPreviousPointerToNull();
    //it uses //the pointers contained
    //within this node to change the previous /
    ///and next nodes so that they point to
    //this node appropriately.
    void setBeforeAndAfterPointers();
};

#include "LinkedNodeClass.inl"
#endif
