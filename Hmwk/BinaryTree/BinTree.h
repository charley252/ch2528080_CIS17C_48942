

#ifndef BINTREE_H
#define	BINTREE_H

#include <cstdlib>
#include <iostream>

using namespace std;

class BinTree
{
private:
    struct TreeNode
    {
        int value;
        TreeNode *left;
        TreeNode *right;
    };
    
    TreeNode *root; //points to first node in the tree
    
    void insert(TreeNode *&, TreeNode *&);
    void deleteNode(int, TreeNode *&);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    
public:
    BinTree()
    {
        root = NULL;
    }
    
    ~BinTree()
    {

    }
    
    void insertNode(int);
    void remove(int);
    
    void displayInOrder() const
    {
        displayInOrder(root);
    }
    
    void displayPreOrder() const
    {
        displayPreOrder(root);
    }
    
    void displayPostOrder() const
    {
        displayPostOrder(root);
    }
};

void BinTree::insertNode(int num)
{
    TreeNode *newNode;
    
    newNode = new TreeNode;
    newNode->value = num;
    newNode->left = newNode->right = NULL; //left, right initially set to NULL
                                           //when new node is instantiated.
    
    insert(root, newNode); //this private member function 'places' or inserts the new node.
}

void BinTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
    if(nodePtr == NULL) //is the root node(passed in as a reference to pointer/kind of like deep copy) pointing to NULL?
        nodePtr = newNode; //if so, point to new node.
    else if(newNode->value < nodePtr->value)
        insert(nodePtr->left, newNode); //recursive call with essentially an updated parameter using left pointer.
    else
        insert(nodePtr->right, newNode); //recursive call with essentially an updated parameter using right pointer.
}

void BinTree::displayInOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayInOrder(nodePtr->left);
        cout << nodePtr->value << endl;
        displayInOrder(nodePtr->right);
    }
}

void BinTree::displayPreOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        cout << nodePtr->value << endl;
        displayPreOrder(nodePtr->left);
        displayPreOrder(nodePtr->right);
    }
}

void BinTree::displayPostOrder(TreeNode *nodePtr) const
{
    if(nodePtr)
    {
        displayPostOrder(nodePtr->left);
        displayPostOrder(nodePtr->right);
        cout << nodePtr->value << endl;
    }
}

void BinTree::remove(int num)
{
    deleteNode(num, root);
}

void BinTree::deleteNode(int num, TreeNode *&nodePtr)
{
    if(num < nodePtr->value)
        deleteNode(num, nodePtr->left); //basically traversing using recursion.
    else if(num > nodePtr->value)
        deleteNode(num, nodePtr->right); //basically traversing using recursion.
    else
        makeDeletion(nodePtr); //finally removing/deleting value when found.
                               //But this function also takes care of reattaching nodes.
}

void BinTree::makeDeletion(TreeNode *&nodePtr)
{
    TreeNode *tempNodePtr; //temp node pointer to use in reattaching nodes via swap.
    
    if(nodePtr == NULL)
        cout << "Node is empty. Cannot delete." << endl;
    else if(nodePtr->right == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left; //reattach left child.
        delete tempNodePtr;
    }
    else if(nodePtr->left == NULL)
    {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right; //reattach right child.
        delete tempNodePtr;
    }
    else
    {   //when there is two children, reorder and reattach.
        tempNodePtr = nodePtr->right;
        
        while(tempNodePtr->left)
            tempNodePtr = tempNodePtr->left;
        
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}

#endif	/* BINTREE_H */

