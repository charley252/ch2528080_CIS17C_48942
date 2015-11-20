
#ifndef PLAYER_H
#define	PLAYER_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "Card.h"
using namespace std;

class Player
{
private:
    string name;
    int totalMoney;
    int bet = 0;
    int splitBet = 0;
    
    int sumValue = 0;
    int altSumValue = 0;
    int splitSumValue = 0;
   
    bool Bust = false;
    bool Done = false;
    bool Split = false;
    bool Double = false;
    bool Surrender = false;
    bool BlackJack = false;
    bool Natural = false;
    bool hasAce = false;
    bool Finished = false;
    
    bool firstHandDone = false;
    bool secondHandDone = false;
    bool bothHandDone = false;
    
    bool handStand = false;
    bool splitStand = false;
    
public:
    Player();
    Player(string, int);
    ~Player();
    
    vector<Card> hand;
    vector<Card> split;
    
    string getName();
    int getTotalMoney();
    void setTotalMoney(int);
        
    void setBet(int b);
    int getBet();
    void setSplitBet();
    int getSplitBet();
    
    void setSumVal(int);
    int calcSumVal();
    int getSumVal();
    void setSplitSumVal(int);
    int calcSplitSumVal();
    int getSplitSumVal();
    int getAltSum();
    
    bool isBust();
    bool getBust();
    void setSurrender();
    bool getSurrender();
    bool isBlackJack();
    bool getBlackJack();
    bool isAce();
    bool isNatural();
    bool getNatural();
    void setDone();
    bool getDone();
    void setSplitTrue();
    bool getSplit();
    void setDouble();
    bool getDouble();
    void setFinished();
    bool getFinished();

    void setFirstDone();
    bool getFirstDone();
    void setSecondDone();
    bool getSecondDone();
    void setBothDone();
    bool getBothDone();
    
    void setHandStand();
    bool getHandStand();
    void setSplitStand();
    bool getSplitStand();
    
    bool thereIsAce();
    
    void reset();
};

Player::Player()
{
    
}

Player::Player(string n, int m)
{
    //vector<Card> hand;
    name = n;
    totalMoney = m;
}

Player::~Player()
{

}

string Player::getName()
{
    return name;
}

int Player::getTotalMoney()
{
    return totalMoney;
}

void Player::setTotalMoney(int m)
{
    totalMoney = m;
}

void Player::setBet(int b)
{
    bet = b;
}

int Player::getBet()
{
    return bet;
}

void Player::setSplitBet()
{
    splitBet = bet;
}

int Player::getSplitBet()
{
    return splitBet;
}

void Player::setSumVal(int v)
{
    sumValue = v;
}

int Player::calcSumVal()
{
    sumValue = 0;
    for(int i=0; i<hand.size(); i++)
    {
        sumValue += hand[i].getValue();
    }
    return sumValue;
}

int Player::getSumVal()
{
    return sumValue;
}

void Player::setSplitSumVal(int v)
{
    splitSumValue = v;
}

int Player::calcSplitSumVal()
{
    splitSumValue = 0;
    for(int i=0; i<split.size(); i++)
    {
        splitSumValue += split[i].getValue();
    }
    return splitSumValue;
}

int Player::getSplitSumVal()
{
    return splitSumValue;
}

int Player::getAltSum()
{
    return altSumValue;
}

/******************************************************************************/

bool Player::isBust()
{
    if(sumValue > 21 || splitSumValue > 21 || altSumValue > 21)
    {
        Bust = true;
        Done = true;
        return true;

    }else 
        return false;
}

bool Player::getBust()
{
    return Bust;
}

void Player::setSurrender()
{
    Surrender = true;
}

bool Player::getSurrender()
{
    return Surrender;
}

bool Player::isBlackJack()
{
    if(sumValue == 21)
    {
        BlackJack = true;
        Done = true;
        return true;
    }else 
        return false;
}

bool Player::getBlackJack()
{
    return BlackJack;
}

bool Player::isAce()
{
    if(hand[0].getFace() == "Ace" || hand[1].getFace() == "Ace" && !Split)
    {
        hasAce = true;
        return true;
    }else 
        return false;
}

bool Player::thereIsAce()
{
    for(int i=0; i<hand.size(); i++)
    {
        if(hand[i].getFace() == "Ace")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Player::isNatural()
{
    if(sumValue == 21 && hasAce)
    {
        Natural = true;
        Done = true;
        return true;
    }else
        return false;
}

bool Player::getNatural()
{
    return Natural;
}

void Player::setDone()
{
    Done = true;
}

bool Player::getDone()
{
    return Done;
}

void Player::setSplitTrue()
{
    Split = true;
}

bool Player::getSplit()
{
    return Split;
}

void Player::setDouble()
{
    Double = true;
}

bool Player::getDouble()
{
    return Double;
}

void Player::setFinished()
{
    Finished = true;
}

bool Player::getFinished()
{
    return Finished;
}

void Player::setFirstDone()
{
    firstHandDone = true;
}

bool Player::getFirstDone()
{
    return firstHandDone;
}

void Player::setSecondDone()
{
    secondHandDone = true;
}

bool Player::getSecondDone()
{
    return secondHandDone;
}

void Player::setBothDone()
{
    bothHandDone = true;
}

bool Player::getBothDone()
{
    return bothHandDone;
}

void Player::setHandStand()
{
    handStand = true;
}

bool Player::getHandStand()
{
    return handStand;
}

void Player::setSplitStand()
{
    splitStand = true;
}

bool Player::getSplitStand()
{
    return splitStand;
}



void Player::reset()
{        
    bet = 0;
    splitBet = 0;
    
    sumValue = 0;
    altSumValue = 0;
    splitSumValue = 0;
   
    Bust = false;
    Done = false;
    Split = false;
    Double = false;
    Surrender = false;
    BlackJack = false;
    Natural = false;
    hasAce = false;
    Finished = false;
    
    firstHandDone = false;
    secondHandDone = false;
    bothHandDone = false;
    
    handStand = false;
    splitStand = false;
}


#endif	/* PLAYER_H */

