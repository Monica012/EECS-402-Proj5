//Name: Nai Shih
//EECS402 proj5
//Date:12/2018
//Purpose:read values from file and see if it is valid


#include "readVal.h"
using namespace std;


bool readVal(ifstream &inFileName, int &inputVal)
{
    inFileName >> inputVal;
    if(inFileName.eof())
    {
        return false;
    }
    else if (inFileName.fail())
    {
        inFileName.clear();
        inFileName.ignore(IGNORE_NUM, '\n');
        return false;
    }
    else
    {
        return true;
    }
}



