
#ifndef DEALER_H
#define	DEALER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Dealer
{
private:
    string name;
    int sumValue;
    
    bool Bust = false;
    bool Done = false;
    bool hasAce = false;
    bool Natural = false;
    bool BlackJack = false;
    
public:
    Dealer();
    ~Dealer();
    
    vector<Card> hand;
    
    string getName();
    int calcSumVal();
    int getSumVal();
   
    bool isBust();
    bool getBust();
    bool isBlackJack();
    bool getBlackJack();
    bool isNatural();
    bool getNatural();
    bool isAce();
    bool getAce();
    void setDone();
    bool getDone();
    
    void reset();
};

Dealer::Dealer()
{
    //vector<Card> hand;
    name = "Dealer";
    sumValue = 0;
}

Dealer::~Dealer()
{

}

string Dealer::getName()
{
    return name;
}

int Dealer::calcSumVal()
{
    sumValue = 0;
    for(int i=0; i<hand.size(); i++)
    {
        sumValue += hand[i].getValue();
    }
    return sumValue;
}

int Dealer::getSumVal()
{
    return sumValue;
}

bool Dealer::isBust()
{
    if(sumValue > 21)
    {
        Bust = true;
        Done = true;
        return true;
    }else
        return false;
}

bool Dealer::getBust()
{
    return Bust;
}

bool Dealer::isBlackJack()
{
    if(sumValue == 21)
    {
        BlackJack = true;
        Done = true;
        return true;
    }else 
        return false;
}

bool Dealer::getBlackJack()
{
    return BlackJack;
}

bool Dealer::isNatural()
{
    if(sumValue == 21 && hasAce)
    {
        Natural = true;
        Done = true;
        return true;
    }else
        return false;
}

bool Dealer::getNatural()
{
    return Natural;
}

bool Dealer::isAce()
{
    if(hand[0].getFace() == "Ace")
    {
        hasAce = true;
        return true;
    }else 
        return false;
}

bool Dealer::getAce()
{
    return hasAce;
}

void Dealer::setDone()
{
    Done = true;
}

bool Dealer::getDone()
{
    return Done;
}

void Dealer::reset()
{
    sumValue = 0;
    
    Bust = false;
    Done = false;
    hasAce = false;
    Natural = false;
    BlackJack = false;  
}


#endif	/* DEALER_H */

