
#ifndef CARD_H
#define	CARD_H

#include <cstdlib>
#include <string>
using namespace std;

class Card
{
private:
    string face;
    string suit;
    int value;
    
public:
    Card();
    Card(string, string, int);
    ~Card();
    
    string getSuit();
    string getFace();
    int getValue();
    
};

Card::Card()
{
    
}

Card::Card(string f, string s, int v)
{

    face = f;
    suit = s;
    value = v;
}

Card::~Card()
{
    
}

string Card::getFace()
{
    return face;
}

string Card::getSuit()
{
    return suit;
}

int Card::getValue()
{
    return value;
}

#endif	/* CARD_H */

