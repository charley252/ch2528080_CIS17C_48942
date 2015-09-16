//Han, Charley - CIS17C - Triangular Matrix

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "Array.h"

using namespace std;

int main(int argc, char** argv) 
{
    //random seed
    srand(static_cast<unsigned int>(time(0)));
    
    //instantiate array object
    Array one(15);
    one.prntAry();
    
    cout << endl;
    
    //instantiate array object, passing in another object
    Array two(one, 20);
    two.prntAry();
    
    
    return 0;
}

