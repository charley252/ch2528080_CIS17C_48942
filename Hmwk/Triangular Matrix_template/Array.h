
#ifndef ARRAY_H
#define	ARRAY_H

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

//template class for array
template<class T>
class Array 
{
public:
    //constructor
    Array(int);
    
    //copy constructor
    Array(const Array<T> &, int);
    
    virtual ~Array();
    
    void prntAry();
    void destroy();
    
private:
    T *d1ary;
    T **d2ary;
    int columns;
    int objcolumns;

};

template<class T>
Array<T>::Array(int n)
{
    columns = n;
    
    d1ary = new T[n];
    for(int i=0; i<n; i++)
    {
        //d1ary[i] = rand()%10+1;
        d1ary[i] = (rand() / (float)RAND_MAX * 19) + 1; //to create random float
    }
}

template<class T>
Array<T>::Array(const Array &obj, int n)
{
    objcolumns = obj.columns;
    columns = n;
    //create 2d array
    d2ary = new T*[n];
    for(int i=0; i<n; i++)
    {
        //d2ary[i] = new T[obj.d1ary[i]];
        d2ary[i] = new T[objcolumns]; //create 2d array or array of array
    }
    
    for(int row=0; row<n; row++)
    {
        for(int col=0; col<obj.columns; col++)
        {
            //d2ary[row][col] = rand()%90+10;
            d2ary[row][col] = (rand() / (float)RAND_MAX * 19) + 1; //to create random float

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
            cout << d1ary[i] << " ";
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

#endif	/* ARRAY_H */

