//Han, Charley - CIS17C - SimpleVector
#include <cstdlib>
#include <iostream>
#include <ctime>     
#include "SimpleVector2.h"


using namespace std;

int main(int argc, char** argv) 
{    
    srand(static_cast<unsigned int>(time(0)));
    
    //pointers to array to receive returned array for push and pull
    int *arraypushptr;
    int *arraypullptr;    
    
    //array class instantiation and print
    SimpleVector<int> array(10);
    array.printArray();
    
    //instantiate array after push to original class array
    arraypushptr = array.pushArray(55);
    
    //instantiate array after pull from original class array
    arraypullptr = array.pullArray();
    
    //print out array after push
    cout << "Array after push and size doubled with 1st element inserted: " << endl;
    for(int i=0; i<array.size()*2; i++)
    {
        cout << arraypushptr[i] << " ";
    }
    
    cout << endl << endl;
    
    //print out array after pull
    cout << "Array after pull(1st element) and size reduced by one: " << endl;
    for(int i=0; i<array.size()-1; i++)
    {
        cout << arraypullptr[i] << " ";
    }
    return 0;
}

