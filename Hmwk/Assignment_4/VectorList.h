/* 
 * File:   VectorList.h
 * Author: Owner
 *
 * Created on September 25, 2015, 12:31 PM
 */

#ifndef VECTORLIST_H
#define	VECTORLIST_H

using namespace std;

class VectorList {
public:
    VectorList();
    VectorList(const VectorList& orig);
    virtual ~VectorList();
    
    void appendNode(int); //function to append a data node to the list.
    void printNodeValue(); //displays a list of values stored in struct
private:
    //Class within a class because struct is basically a class from C days.
    //Another term for this is 'container adaptor', where linked-list is an implemented
    //container adaptor abstract to contain a data structure(array). Together, this can be construed as ADT.
    struct VectorNode
    {
        int number; //to hold sample test int value
        struct VectorNode *next; //this is the linked list concept, where a pointer in this class is pointing to the next class
                                 //in the list.
    };
    
    VectorNode *head; //this pointer is the head pointer. Initially, it is made to point to NULL.
};

#endif	/* VECTORLIST_H */

