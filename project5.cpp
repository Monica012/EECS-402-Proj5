//Name: Nai Shih
//EECS402 project5
//Date: 12/2018
//Purpose: read in input parameters and run the restaurant simulation 


#include <iostream>
#include <string>
#include "LinkedNodeClass.h"
#include "SortedListClass.h"
#include "FIFOQueueClass.h"
#include "EventClass.h"
#include "RestaurantClass.h"
#include "readVal.h"

using namespace std;

//Do NOT remove any of the preprocessor directives in this file.
//They should not affect your ability to write test code in your
//main function below, and they must be in your submitted main
//file exactly as provided to you with the project.
#ifdef ANDREW_TEST
#include "andrewTest.h"

#else
/*
// testing eventClass in Sorted list and queue
ostream& operator<<(ostream &os, const EventClass &iObj)
{
    //os << iObj.getTime();
    os << iObj.getCustomerID();
    //os << iObj.getEventType();
    return (os);
}
*/


int main()
{
    //This is just a placeholder main function - it does exceptionally
    //little actual testing, so you'll want to add your own tests here.
    //Feel free to leave your tests in the version of this file you
    //submit, but we will not be running your main function, so the
    //output, etc., of your main doesn't need to match anything from
    //a sample output, etc.
    /*
    SortedListClass< int  > testlist;
    testlist.printForward();
    testlist.printBackward();
    cout << "add 10, 11, 12, 13, 14\n";
    testlist.insertValue(10);
    testlist.insertValue(11);
    testlist.insertValue(12);
    testlist.insertValue(13);
    testlist.insertValue(14);
    testlist.printForward();
    testlist.printBackward();
    cout << "remove front 10 and last 14";
    int valOut;
    testlist.removeFront(valOut);
    cout << valOut << endl;
    testlist.removeLast(valOut);
    cout << valOut << endl;
    testlist.printForward();
    cout << "numList should be 3";
    int numList = testlist.getNumElems();
    int outPut;
    for (int i = 0; i < numList; i++)
    {
        testlist.getElemAtIndex(i, outPut);
        cout << i << "    " << outPut << endl;
    }
    int j = numList;
    cout << testlist.getElemAtIndex(j, outPut) << endl;
    testlist.clear();
    testlist.printForward();
    testlist.printBackward();
    testlist.insertValue(50);
    testlist.insertValue(50);
    testlist.insertValue(50);
    testlist.insertValue(50);
    testlist.printForward();
    testlist.printBackward();



    SortedListClass< double  > testlist2;
    testlist2.printForward();
    testlist2.printBackward();
    cout << "add 10.12, 11.23, 12.34, 13.45, 14.56\n";
    testlist2.insertValue(10.12);
    testlist2.insertValue(11.23);
    testlist2.insertValue(12.34);
    testlist2.insertValue(13.45);
    testlist2.insertValue(14.56);
    testlist2.printForward();
    testlist2.printBackward();
    cout << "remove front 10.12 and last 14.56";
    double valOut2;
    testlist2.removeFront(valOut2);
    cout << valOut2 << endl;
    testlist2.removeLast(valOut2);
    cout << valOut2 << endl;
    testlist2.printForward();
    cout << "numList should be 3";
    numList = testlist2.getNumElems();
    double outPut2;
    for (int i = 0; i < numList; i++)
    {
        testlist2.getElemAtIndex(i, outPut2);
        cout << i << "    " << outPut2 << endl;
    }
    j = numList;
    cout << testlist2.getElemAtIndex(j, outPut2) << endl;
    testlist2.clear();
    testlist2.printForward();
    testlist2.printBackward();
    testlist2.insertValue(50.1234);
    testlist2.insertValue(50.2345);
    testlist2.insertValue(50.3456);
    testlist2.insertValue(50.4567);
    testlist2.printForward();
    testlist2.printBackward();


    SortedListClass< string > testlist3;
    testlist3.printForward();
    testlist3.printBackward();
    cout << "add 10.12, 11.23, 12.34, 13.45, 14.56\n";
    testlist3.insertValue("10.12");
    testlist3.insertValue("11.23");
    testlist3.insertValue("12.34");
    testlist3.insertValue("13.45");
    testlist3.insertValue("14.56");
    testlist3.printForward();
    testlist3.printBackward();
    cout << "remove front 10.12 and last 14.56";
    string valOut3;
    testlist3.removeFront(valOut3);
    cout << valOut3 << endl;
    testlist3.removeLast(valOut3);
    cout << valOut << endl;
    testlist3.printForward();
    cout << "numList should be 3";
    numList = testlist3.getNumElems();
    string outPut3;
    for (int i = 0; i < numList; i++)
    {
        testlist3.getElemAtIndex(i, outPut3);
        cout << i << "    " << outPut3 << endl;
    }
    j = numList;
    cout << testlist3.getElemAtIndex(j, outPut3) << endl;
    testlist3.clear();
    testlist3.printForward();
    testlist3.printBackward();
    testlist3.insertValue("50.1234");
    testlist3.insertValue("50.2345");
    testlist3.insertValue("50.3456");
    testlist3.insertValue("50.4567");
    testlist3.printForward();
    testlist3.printBackward();


    SortedListClass< char > testlist4;
    testlist4.printForward();
    testlist4.printBackward();
    cout << "add a, b, c, d, e\n";
    testlist4.insertValue('a');
    testlist4.insertValue('b');
    testlist4.insertValue('c');
    testlist4.insertValue('d');
    testlist4.insertValue('e');
    testlist4.printForward();
    testlist4.printBackward();
    cout << "remove front a and last e";
    char valOut4;
    testlist4.removeFront(valOut4);
    cout << valOut4 << endl;
    testlist4.removeLast(valOut4);
    cout << valOut4 << endl;
    testlist4.printForward();
    cout << "numList should be 3";
    numList = testlist4.getNumElems();
    char outPut4;
    for (int i = 0; i < numList; i++)
    {
        testlist4.getElemAtIndex(i, outPut4);
        cout << i << "    " << outPut4 << endl;
    }
    j = numList;
    cout << testlist4.getElemAtIndex(j, outPut4) << endl;
    testlist4.clear();
    testlist4.printForward();
    testlist4.printBackward();
    testlist4.insertValue('a');
    testlist4.insertValue('o');
    testlist4.insertValue('m');
    testlist4.insertValue('n');
    testlist4.printForward();
    testlist4.printBackward();



    SortedListClass< EventClass > testlist5;
    testlist5.printForward();
    testlist5.printBackward();
    cout << "add 10, 15, 20, 25, 30\n";
    EventClass event1(1, 10, 3);
    EventClass event2(9, 11, 4);
    EventClass event3(3, 11, 5);
    EventClass event4(2, 8, 1);
    EventClass event5(1, 9, 2);
    testlist5.insertValue(event1);
    testlist5.insertValue(event2);
    testlist5.insertValue(event3);
    testlist5.insertValue(event4);
    testlist5.insertValue(event5);
    testlist5.printForward();
    testlist5.printBackward();

    */
    cout<< "In the file, please enter the num in the following order: \
    the value of the percentage that people do not want to wait in line, \
    the number of people in long line, the mean value for \
    a server to wait, the sd value for a server to wait on a customer, \
    the closed time, the max between customer time, the min \
    between customer time, and the seed value.\n";
    cout<< "Plase insert the file name: \n";
    string fileName;
    cin >> fileName;
    ifstream inFileName;
    //read user's input file into fileName in string type
    inFileName.open(fileName.c_str());
    
    RestaurantClass ladyM;
    if (inFileName.fail() == false)
    {
        ladyM.getInput(inFileName);
        //use the first customer arrival event as a trigger 
        //to start popping up the next event untill there
        //is not events in the eventlist
        do
        {
            ladyM.getNext();
        } while (ladyM.getEventListNum() != 0);
        //print out stats
        ladyM.print();
    }
    else
    {
        cout << "input parameter file does not exist!\n";
    }
    return 0;
}
#endif
