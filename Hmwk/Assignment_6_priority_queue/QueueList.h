

#ifndef QUEUELIST_H
#define	QUEUELIST_H
#include <cstdlib>
#include <iostream>
using namespace std;

template<class T>
class QueueList
{
private:
    struct QueueNode
    {
        T value;
        QueueNode *next;
    };
    
    QueueNode *rear;
    QueueNode *front;
    QueueNode *min;
    QueueNode *minBefore;
    
    int numItems;
    
public:
    QueueList();
    QueueList(const QueueList &);
    ~QueueList();
    
    void enq(T);
    void deq();
    bool isEmpty();
    bool isFull();
    void clear();
    
    void returnMin();
    void removeMin();
    
    void printNodeValue();

    
};

template<class T>
QueueList<T>::QueueList()
{
    front = NULL;
    rear = NULL;
    numItems = 0;
}

template<class T>
QueueList<T>::QueueList(const QueueList &orig)
{
    QueueNode *ptr;
    
//    for(ptr = orig.front; ptr != NULL; ptr = ptr->next)
//    {
//        enq(ptr->value);
//        
//    }
    ptr = orig.front;
    while(ptr->next != NULL)
    {
        enq(ptr->value);
        ptr = ptr->next;
    }

}

template<class T>
QueueList<T>::~QueueList()
{
    clear();
}

template<class T>
void QueueList<T>::enq(T num)
{
    QueueNode *newNode;
    newNode = new QueueNode;
    newNode->value = num;
    newNode->next = NULL;
    
    if(isEmpty())
    {
        front = newNode;
        rear = newNode;
        min = newNode;    
        minBefore = newNode;
        
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        minBefore = rear;
        
    }
    
    
    if(newNode->value <= min->value)
    {
        rear = newNode;
        min = newNode;
        minBefore = rear;
    }
    

    numItems++;
}

template<class T>
void QueueList<T>::deq()
{
    QueueNode *traverse;
    
    if(isEmpty())
    {
        cout << "The queue is empty." << endl;
    }
    else
    {
        
        traverse = front;
        front = front->next;
        delete traverse;
        
        numItems--;
    }
}

template<class T>
bool QueueList<T>::isEmpty()
{
    bool status;
    
    if(numItems>0)
    {
        status = false;
    }
    else
    {
        status = true;
    }
    return status;
}

template<class T>
bool QueueList<T>::isFull()
{
    
}

template<class T>
void QueueList<T>::clear()
{
    while(!isEmpty())
    {
        deq();
    }
}

template<class T>
void QueueList<T>::returnMin()
{
    cout << "Minimum key is: " << min->value << endl;
}

template<class T>
void QueueList<T>::removeMin()
{
    while(front->next != NULL)
    {
        front = front->next;
        if(front->next <= min)
        {
            min = front->next;
            delete rear;
            rear = min;
            minBefore = rear;
        }
        
    }
}

template<class T>
void QueueList<T>::printNodeValue()
{
    QueueNode *traverse;
    
    traverse = front;
    
    //while the pointer is doing what it's supposed to do, point to a node
    //display the 'number' value stored in the node that it's pointing to
    //and afterwards, move onto the next node and do it again.
    while(traverse)
    {
        cout << traverse->value << " ";
        
        traverse = traverse->next; //this is basically a pointer to a pointer
    }
}



#endif	/* QUEUELIST_H */

