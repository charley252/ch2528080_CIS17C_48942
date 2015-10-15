//Han, Charley - CIS17C - 48942 - Assignment #6 Stacks

#include <cstdlib>
#include <iostream>

#include "StackList.h"

using namespace std;

int main(int argc, char** argv)
{
    
    StackList<int> myStack;
    
    myStack.push(5);
    myStack.push(4);
    myStack.push(3);
    myStack.push(2);
    myStack.push(1);
    myStack.push(0);
    
    cout << "Stack linked list: ";
    myStack.printNodeValue();
    
    cout << endl;
    
    myStack.pop();
    myStack.pop();
    
    cout << "Stack linked list after couple of 'pops': ";
    myStack.printNodeValue();
    
    cout << endl;
    
    StackList<int> copyStack(myStack);
    
    cout << "Stack linked list after copy constructor - it copies 'backwads': ";
    copyStack.printNodeValue();
    cout << endl << endl;
    
    StackList<char> charStack;
    
    charStack.push('A');
    charStack.push('B');
    charStack.push('C');
    charStack.push('D');
    
    cout << "Stack linked list of characters: ";
    charStack.printNodeValue();
    
    cout << endl;
    
    StackList<string> strStack;
    
    strStack.push("Hello");
    strStack.push("World");
    
    cout << "Stack linked list of strings: ";
    strStack.printNodeValue();
    
    cout << endl;
    
    
    
    
    
    

    return 0;
}

