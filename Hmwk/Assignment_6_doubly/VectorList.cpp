/* 
 * File:   VectorList.cpp
 * Author: Owner
 * 
 * Created on September 25, 2015, 12:31 PM
 */
#include <cstdlib>
#include <iostream>
#include "VectorList.h"

using namespace std;

VectorList::VectorList() 
{
    head = 0; //head pointer is made to point to NULL when there is nothing in the list.
}

VectorList::VectorList(const VectorList &orig)
{

    head = 0;
    VectorNode *ptr;
    for(ptr = orig.head; ptr != 0; ptr = ptr->next)
    {
        appendNode(ptr->number);
    }
}

VectorList::VectorList &operator = (VectorList const &orig)
{
 
}

VectorList::~VectorList() 
{
}

//returns value of first node
void VectorList::firstNode()
{
    VectorNode *traverse;
    
    traverse = head;
    cout << "First node value = " << traverse->number << endl;
}

//returns the value of last node
void VectorList::lastNode()
{
    VectorNode *traverse;
    
    while(traverse->next)
    {
        traverse = traverse->next;
    }
    if(traverse->next == 0)
    {
        cout << "Last node value = " << traverse->number << endl;
    }
}

//appends a node at the beginning of the list
void VectorList::prependNode(int x)
{
    VectorNode *newNode;
    
    newNode = new VectorNode;
    newNode->number = x;
    
    newNode->next = head;
    head = newNode;
    
    
}

//appends node at the end of the list
void VectorList::appendNode(int x)
{
    VectorNode *newNode; //this dynamically creates a new node or data class, in this case a struct that holds one int value.
    VectorNode *traverse; //this node pointer is used later to traverse the list for purpose of displaying or even inserting a node.
    
    newNode = new VectorNode; //create new node
    newNode->number = x; //initialize the number value to x
    newNode->next = 0; //once a new node is inserted, it's 'next' pointer is made to point to NULL because it's the last on the list.
    
    //when we insert a new node, this checks to see if the head pointer is actually pointing anything, which means there is something
    //in the list, if NOT then the node we just inserted becomes the first in the list so this makes the head point to it.
    if(!head)
    {
        head = newNode;
    }
    //if the list is not empty, travNode is made to traverse the list to find where the end of the list is so we can find 
    //the end to insert/append the new node
    else
    {
        traverse = head;
        
        //Sooner or later, the while statement won't be true because
        //it will run into a next pointer that will be pointing to NULL
        //at which point it will come out of the loop and assign the next pointer
        //to the new node and by that act, the new node is made the last node in the list
        //NOTE: the new node's next pointer was already made to point to NULL when instantiated.
        while(traverse->next)
        {
            traverse = traverse->next; //this is basically a pointer to a pointer
        }
        
        traverse->next = newNode;
    }
    
}

//deletes node at position x
void VectorList::extractNode(int x)
{
    //to count how many nodes it traversed
    int count = 1;
    
    VectorNode *traverse;
    VectorNode *previous;
    
    //initialize two pointers. Make traverse point to whatever head is pointing to
    //and make 'previous' point to the head itself, so what it will always be on
    //step behind.
    traverse = head;
    previous = head;
    
    //if the user wants to move the first node, check it. If so, make 'head' point to the next one over
    //before deleting what 'previous' pointer was pointing to, in this case the first node as initiated
    //in previous line.
    if(count == x)
    {
        head = traverse->next;
        delete previous;
    
    }
    //otherwise, traverse down the list to find which node index to delete
    else
    {
        while(traverse->next && traverse != NULL)
        {
            count++;
            previous = traverse;
            traverse = traverse->next; //one step ahead of 'previous'.
            
            //if the traversing count equals what the user input, then
            //before deleting that node, make the previous node pointer point
            //to the next node in line.
            if(count == x)
            {
                previous->next = traverse->next; //leap frogs over to the next node.
                delete traverse; //delete the node
            }
        }
        
    }

}
   
//insert node at with given x value at position p in the list
void VectorList::insertNode(int x, int p)
{
    VectorNode *newNode;
    VectorNode *traverse;
    VectorNode *previous = NULL;
    
    newNode = new VectorNode;
    newNode->number = x;
    
    int count = 1;
    
    if(!head)
    {
        head = newNode;
        newNode->next = NULL;
    }
    else
    {
        traverse = head;
        previous = NULL;
        
        while(traverse != NULL && count < p)
        {
            count++;
            previous = traverse;
            traverse = traverse->next;
        }
       
        previous->next = newNode;
        newNode->next = traverse;
      
    }    
}

//prints node values
void VectorList::printNodeValue()
{
    VectorNode *traverse; //pointer to move through the list
    
    traverse = head; //makes the traverse pointer start at the beginning
    
    //while the pointer is doing what it's supposed to do, point to a node
    //display the 'number' value stored in the node that it's pointing to
    //and afterwards, move onto the next node and do it again.
    while(traverse)
    {
        cout << traverse->number << " ";
        
        traverse = traverse->next; //this is basically a pointer to a pointer
    }
}


