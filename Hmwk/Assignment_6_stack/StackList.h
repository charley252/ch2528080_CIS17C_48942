

#ifndef STACKLIST_H
#define	STACKLIST_H
#include <cstdlib>
#include <iostream>

using namespace std;

template<class T>
class StackList
{
private:
    struct StackNode
    {
        T value;
        StackNode *next;
        
    };
    StackNode *top;
    
public:
    StackList();
    StackList(const StackList &);
    
    ~StackList();
    
    void push(T);
    void pop();
    bool isEmpty();
    void printNodeValue();

    
};

/*----------------------------definitions-------------------------*/

template<class T>
StackList<T>::StackList()
{
    top = NULL;
}

template<class T>
StackList<T>::~StackList()
{
    StackNode *traverse;
    StackNode *nextNode;
    
    //start at the beginning
    traverse = top;
    
    //traverse down the list
    while(traverse != NULL)
    {
        //nextNode points to the one after delete
        nextNode = traverse->next;
        delete traverse; //delete node
        traverse = nextNode; //points to the one after deleted node
                             //because that's one nextNode was pointing
                             //before deletion happened.
    }
    
}

template<class T>
StackList<T>::StackList(const StackList &orig)
{
    top = NULL;
    StackNode *ptr;
    //StackNode *newNode = new StackNode;
    for(ptr = orig.top; ptr != NULL; ptr = ptr->next)
    {
        push(ptr->value);
        
    }
}

template<class T>
void StackList<T>::push(T x)
{
    StackNode *newNode;
    
    newNode = new StackNode;
    newNode->value = x;
    
    if(isEmpty())
    {
        top = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = top;
        top = newNode;
    }
}

template<class T>
void StackList<T>::pop()
{
    StackNode *traverse;
    
    if(isEmpty())
    {
        cout << "The stack is empty." << endl;
    }
    else
    {
        //x = top->value;
        traverse = top->next;
        delete top;
        top = traverse;
    }
    
}   

template<class T>
bool StackList<T>::isEmpty()
{
    bool status;
    if(!top)
    {
        status = true;
    }
    else
    {   
        status = false;
    }
    return status;
}

template<class T>
void StackList<T>::printNodeValue()
{
    StackNode *traverse;
    
    traverse = top;
    
    //while the pointer is doing what it's supposed to do, point to a node
    //display the 'number' value stored in the node that it's pointing to
    //and afterwards, move onto the next node and do it again.
    while(traverse)
    {
        cout << traverse->value << " ";
        
        traverse = traverse->next; //this is basically a pointer to a pointer
    }
}

#endif	/* STACKLIST_H */

