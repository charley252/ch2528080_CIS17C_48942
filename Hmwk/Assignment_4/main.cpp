//Han, Charley - CIS17C - Assignment #4

#include <cstdlib>
#include <iostream>

#include "VectorList.h"

using namespace std;


int main(int argc, char** argv)
{
    VectorList testlist;
    
    testlist.appendNode(5);
    testlist.appendNode(6);
    testlist.appendNode(10);
    testlist.appendNode(1);
    
    testlist.printNodeValue();
    

    return 0;
}

