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

VectorList::VectorList(const VectorList& orig)
{
    
}

VectorList::~VectorList() 
{
    
}

void VectorList::appendNode(int x)
{
    VectorNode *newNode; //this dynamically creates a new node or data class, in this case a struct that holds one int value.
    VectorNode *travNode; //this node pointer is used later to traverse the list for purpose of displaying or even inserting a node.
    
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
        travNode = head;
        
        //Sooner or later, the while statement won't be true because
        //it will run into a next pointer that will be pointing to NULL
        //at which point it will come out of the loop and assign the next pointer
        //to the new node and by that act, the new node is made the last node in the list
        //NOTE: the new node's next pointer was already made to point to NULL when instantiated.
        while(travNode->next)
        {
            travNode = travNode->next; //this is basically a pointer to a pointer
        }
        
        travNode->next = newNode;
    }
    
}

void VectorList::printNodeValue()
{
    VectorNode *traverse; //pointer to move through the list
    
    traverse = head; //makes the traverse pointer start at the beginning
    
    //while the pointer is doing what it's supposed to do, point to a node
    //display the 'number' value stored in the node that it's pointing to
    //and afterwards, move onto the next node and do it again.
    while(traverse)
    {
        cout << traverse->number << " " << endl;
        
        traverse = traverse->next; //this is basically a pointer to a pointer
    }
}

