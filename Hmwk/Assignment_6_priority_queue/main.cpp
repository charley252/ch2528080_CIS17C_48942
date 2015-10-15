//Han, Charley - CIS17C - 48942 - Assignment #6 Queue

#include <cstdlib>
#include <iostream>

#include "QueueList.h"

using namespace std;


int main(int argc, char** argv) 
{
    
    QueueList<int> myQue;
    
    myQue.enq(5);
    myQue.enq(4);
    myQue.enq(3);
    myQue.enq(2);
    myQue.enq(1);
    
    cout << "Queue linked list values: ";
    myQue.printNodeValue();
    cout << endl;
    
    myQue.deq();
    myQue.deq();
    
    cout << "Queue linked list values after dequeuing 2 items: ";
    myQue.printNodeValue();
    cout << endl;
    
    myQue.enq(10);
    myQue.enq(11);
    
    cout << "Queue linked list values after adding 2 items: ";
    myQue.printNodeValue();
    cout << endl << endl;
    
    QueueList<char> myCharQ;
    
    myCharQ.enq('A');
    myCharQ.enq('B');
    
    cout << "Queue linked list of characters: ";
    myCharQ.printNodeValue();
    cout << endl;
    
    myQue.returnMin();
    myQue.removeMin();
    
    cout << "After min key has been removed from list: ";
    myQue.printNodeValue();
    cout << endl;
    
    
//    QueueList<int> copyQue(myQue);
//    cout << "Queue linked list after copy constructor: ";
//    copyQue.printNodeValue();
//    cout << endl;
    

    return 0;
}

