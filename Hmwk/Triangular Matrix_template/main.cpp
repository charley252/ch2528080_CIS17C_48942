//Han, Charley - CIS17C - Triangular Matrix

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Array.h"

using namespace std;

int main(int argc, char** argv) 
{
    //random seed generator
    srand(static_cast<unsigned int>(time(0)));
    
    //int array object instantiation
    Array<int> one(5);
    one.prntAry();
    
    cout << endl;
    
    //float or int object instantiation
    Array<int> two(one, 5);
    two.prntAry();
    
    
    
    
    return 0;
}

