
#ifndef ARRAY_H
#define	ARRAY_H

class Array {
public:
    Array(int);
    Array(const Array &, int);
    
    virtual ~Array();
    
    void prntAry();
    void destroy();
    
private:
    int *d1ary;
    int **d2ary;
    int columns;
    int objcolumns;

};

#endif	/* ARRAY_H */

