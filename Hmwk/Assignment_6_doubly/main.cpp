//Han, Charley - CIS17C - Assignment #6 - Doubly Linked List operations

#include <cstdlib>
#include <iostream>

#include "VectorList.h"

using namespace std;


int main(int argc, char** argv)
{
    //instantiate linked list ADT
    VectorList<int> testlist;
    
    //test linked-list ADT operations
    testlist.appendNode(5);
    testlist.appendNode(6);
    testlist.appendNode(10);
    testlist.appendNode(1);
   
    cout << "Doubly Linked List: " << endl;
    
    cout << "After Append node: "; testlist.printNodeValue(); cout << endl;
    
    testlist.prependNode(55);
    cout << "After Prepend node: "; testlist.printNodeValue(); cout << endl;
    
    testlist.appendNode(99);
    cout << "After Append node: "; testlist.printNodeValue(); cout << endl;
  
    cout << "Returning value of first node: ";  testlist.printNodeValue(); cout << endl;
    testlist.firstNode();

    cout << "Returning value of the last node: "; testlist.printNodeValue(); cout << endl;
    testlist.lastNode();
    
    testlist.extractNode(2);
    cout << "List after deleting 2nd position: "; testlist.printNodeValue(); cout << endl;
    
    testlist.insertNode(25,5);
    cout << "List after inserting value 25 at position 5: "; testlist.printNodeValue(); cout << endl;
    
    VectorList<int> copylist(testlist);
    cout << "List after using copy constructor: "; copylist.printNodeValue(); cout << endl;
    
    
    
    return 0;
}

