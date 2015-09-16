#include <cstdlib>
#include <iostream>
#include <ctime>

#include "Array.h"

using namespace std;

template<class T>
Array<T>::Array(int n)
{
    columns = n;
    
    d1ary = new int[n];
    for(int i=0; i<n; i++)
    {
        d1ary[i]=i+1;
    }
}

template<class T>
Array<T>::Array(const Array &obj, int n)
{
    objcolumns = obj.columns;
    columns = n;
    d2ary = new int*[n];
    for(int i=0; i<n; i++)
    {
        d2ary[i] = new int[obj.d1ary[i]];
    }
    
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<obj.columns; col++)
        {
            d2ary[row][col] = rand()%90+10;
        }
    }
}

template<class T>
Array<T>::~Array()
{
    destroy();
}

template<class T>
void Array<T>::prntAry()
{
    if(d1ary[1] != 0)
    {
        cout << endl;
        for(int i=0; i<columns; i++)
        {
            cout << d1ary[i];
        }
    }
    else if(d2ary[1] != 0)
    {
        cout << endl;
        for(int row=0; row<columns; row++)
        {
            for(int col=0; col<objcolumns; col++)
            {
                cout << d2ary[row][col] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}

template<class T>
void Array<T>::destroy()
{
    delete []d1ary;
    
    for(int i=0; i<columns; i++)
    {
        delete []d2ary[i];
    }
    delete []d2ary;
}

