//Name: Nai Shih
//EECS project4
//Date: 11/2018
//Purpose:declares sortedlistclass functions implemented here


template < class T >
SortedListClass< T >::SortedListClass()
{
    head = 0;
    tail = 0;
}

template < class T >
int SortedListClass< T >::getNumElems() const
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
bool SortedListClass< T >::getElemAtIndex(const int index, T &outVal) const
{
    LinkedNodeClass< T >* temp;
    temp = head;
    int num = 0;
    //also check is index is less than 0
    if (index >= getNumElems() || index < 0)
    {
        return false;
    }
    else
    {
        while (num != index)
        {
            temp = temp->getNext();
            num = num + 1;
        }
        outVal = temp->getValue();
        return true;
    }
}


template < class T >
bool SortedListClass< T >::removeLast(T &theVal)
{
    bool status = true;
    LinkedNodeClass< T >* temp;
    if (tail == 0)
    {
        status = false;
    }
    else
    {
        temp = tail;
        theVal = tail->getValue();
        if (head == tail)
        {
            head = 0;
            tail = 0;
        }
        else
        {
            tail = temp->getPrev();
            tail->setNextPointerToNull();
        }
        delete temp;
    }
    return status;
}

template < class T >
bool SortedListClass< T >::removeFront(T &theVal)
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
        theVal = head->getValue();
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
void SortedListClass< T >::printBackward() const
{
    cout<< "Backward List Contents Follow:\n";
    LinkedNodeClass< T >* temp = tail;
    while (temp != 0)
    {
        cout << "  " << temp->getValue() << endl;
        temp = temp->getPrev();
    }
    cout << "End Of List Contents\n";
}

template < class T >
void SortedListClass< T >::printForward() const
{
    cout<< "Forward List Contents Follow:\n";
    LinkedNodeClass< T >* temp = head;
    while (temp != 0)
    {
        cout << "  " << temp->getValue() << endl;
        temp = temp->getNext();
    }
    cout << "End Of List Contents\n";
}


template < class T >
void SortedListClass< T >::insertValue(const T &valToInsert)
{
    if (head == 0)
    {
        LinkedNodeClass< T >* tempNode;
        tempNode = new LinkedNodeClass< T >(0, valToInsert, 0);
        head = tempNode;
        tail = tempNode;
        tempNode->setBeforeAndAfterPointers();
    }
    else if (valToInsert < head->getValue())
    {
        LinkedNodeClass< T >* tempNode;
        tempNode = new LinkedNodeClass< T >(0, valToInsert, head);
        tempNode->setBeforeAndAfterPointers();
        head = tempNode;
    }
    else if (valToInsert >= tail->getValue())
    {
        LinkedNodeClass< T >* tempNode;
        tempNode = new LinkedNodeClass< T >(tail, valToInsert, 0);
        tempNode->setBeforeAndAfterPointers();
        tail = tempNode;
    }
    else
    {
        LinkedNodeClass< T >* temp;
        temp = head;
        while (valToInsert >= temp->getValue())
        {
            temp = temp->getNext();
        }
        LinkedNodeClass< T >* tempNode;
        tempNode = new LinkedNodeClass< T >(temp->getPrev(), valToInsert, temp);
        tempNode->setBeforeAndAfterPointers();
    }
}


template < class T >
void SortedListClass< T >::clear()
{
    int listNum = getNumElems();
    T theVal;
    for (int i = 0; i < listNum; i++)
    {
        removeFront(theVal);
    }
    head = 0;
    tail = 0;
}

template < class T >
SortedListClass< T >::~SortedListClass()
{
    clear();
}

template < class T >
SortedListClass< T >::SortedListClass(const SortedListClass< T > &rhs)
{
    T inVal;
    for (int i = 0; i < getNumElems(); i++)
    {
        rhs.getElemAtIndex(i, inVal);
        insertValue(inVal);
    }
    head = 0;
    tail = 0;
}
