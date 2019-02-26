//Name: Nai Shih
//EECS project4
//Date: 11/2018
//Purpose: define FIFOQueue methods/ variables

template < class T >
FIFOQueueClass< T >::FIFOQueueClass()
{
    head = 0;
    tail = 0;
}

template < class T >
FIFOQueueClass< T >::~FIFOQueueClass()
{
    clear();
}


template < class T >
void FIFOQueueClass< T >::enqueue(const T &newItem)
{
    if (head == 0)
    {
        LinkedNodeClass< T >* tempNode;
        tempNode = new LinkedNodeClass< T >(0, newItem, 0);
        head = tempNode;
        tail = tempNode;
        tempNode->setBeforeAndAfterPointers();
    }
    else
    {
        LinkedNodeClass< T >* tempNode;
        tempNode = new LinkedNodeClass< T >(tail, newItem, 0);
        tempNode->setBeforeAndAfterPointers();
        tail = tempNode;
    }
}


template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
    bool status = true;
    LinkedNodeClass< T >* temp;
    if (head == 0)
    {
        status = false;
    }
    else
    {
        temp = head;
        outItem = head->getValue();
        //test if there is only node in the list
        if (head == tail)
        {
            head = 0;
            tail = 0;
        }
        else
        {
            head = temp->getNext();
            head->setPreviousPointerToNull();
        }
        delete temp;
    }
    return status;
}

template < class T >
void FIFOQueueClass< T >::print() const
{
    if (head == 0)
    {
        cout << "\n";
    }
    else
    {
        LinkedNodeClass< T >* temp = head;
        while (temp != 0)
        {
            cout << " " << temp->getValue();
            temp = temp->getNext();
        }
        cout << "\n";
    }
}

template < class T >
int FIFOQueueClass< T >::getNumElems() const
{
    int sum = 0;
    LinkedNodeClass< T >* temp;
    temp = head;
    while (temp != 0)
    {
        temp = temp->getNext();
        sum += 1;
    }
    return sum;
}

template < class T >
void FIFOQueueClass< T >::clear()
{
    //assign the getNumElems() to list Num
    //just so the num will not change
    int listNum = getNumElems();
    T theVal;
    for (int i = 0; i < listNum; i++)
    {
        dequeue(theVal);
    }
    head = 0;
    tail = 0;
}


