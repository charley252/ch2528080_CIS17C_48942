
#include <cstdlib>
#include <iostream>
#include "BinTree.h"

using namespace std;


int main(int argc, char** argv)
{
    srand(time(0));
    
    
    BinTree tree;
    
    cout << "Inserting 6 nodes with random values: " << endl;
    tree.insertNode(rand()%100+1);
    tree.insertNode(rand()%100+1);
    tree.insertNode(rand()%100+1);
    tree.insertNode(rand()%100+1);
    tree.insertNode(rand()%100+1);
    tree.insertNode(rand()%100+1);
    
    int x = rand()%100+1;
    tree.insertNode(x);
    cout << endl;
    
    cout << "Values displayed using in-order traversal: " << endl;
    tree.displayInOrder();
    cout << endl;
    
    cout << "Values displayed using pre-order traversal: " << endl;
    tree.displayPreOrder();
    cout << endl;
    
    cout << "Values displayed using post-order traversal: " << endl;
    tree.displayPostOrder();
    cout << endl;
    
    cout << "Deleting a node: value " << x << " removed." << endl;
    tree.remove(x);
    
    cout << "Values displayed using in-order traversal after deleting node: " << endl;
    tree.displayInOrder();
    cout << endl;
    
    
    
    
    
    

    return 0;
}

