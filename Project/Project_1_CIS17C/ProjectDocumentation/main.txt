//Han, Charley - Project 1 - CIS17C - 48942

#include <cstdlib>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include "Card.h"
#include "Player.h"
#include "Dealer.h"
using namespace std;

//function prototypes: mainly the house/casino role functions
void deal(queue<Card> *, Player *, Dealer *);
void deal(queue<Card> *, Player *);
void deal(queue<Card> *, Dealer *);
void fillDeck(vector<Card> *, const int, string [], string [], int []);
void fillShoe(queue<Card> *, vector<Card> &, vector<Card> &, vector<Card> &, vector<Card> &);
void displayDeck(vector<Card> *);
void displayShoe(queue<Card> *);

void displayPlayerH(Player *, Dealer *);
void displayDealerH(Dealer *, Player *);

void displayHouseRules();
void displayOptions();

void split(Player *);

void reconcileBet(Player *, Dealer *); //game loop end calculations regarding bets and who won

int countingCards(Player *, Dealer *);



int main(int argc, char** argv) 
{
    /*************************Game assets/elements*************************/
    srand(static_cast<unsigned int>(time(0)));
    const int DECK_SIZE = 52;
    
    string suit[] = {"Hearts", "Diamonds", "Spades", "Clubs"};
    string face[] = {"Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King", "Ace"};
    int value[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11};
    
    
    
    /*************************Setup decks and shoe(card dispenser)*************************/
    vector<Card> deck1;
    vector<Card> deck2;
    vector<Card> deck3;
    vector<Card> deck4;
      
    fillDeck(&deck1, DECK_SIZE, face, suit, value);
    fillDeck(&deck2, DECK_SIZE, face, suit, value);
    fillDeck(&deck3, DECK_SIZE, face, suit, value);
    fillDeck(&deck4, DECK_SIZE, face, suit, value);
    
    queue<Card> shoe;
    fillShoe(&shoe, deck1, deck2, deck3, deck4);
    
/*************************To test the decks and shoe****************************
********************Dr. Lehr, if you want to test, display deck(1-4) and shoe separately due to 'pop'******************
 
    //to display all decks to see if they were filled correctly
    cout << "Deck 1: " << endl;
    displayDeck(&deck1);
    cout << "Deck 2: " << endl;
    displayDeck(&deck2);
    cout << "Deck 3: " << endl;
    displayDeck(&deck3);
    cout << "Deck 4: " << endl;
    displayDeck(&deck4);
    
    //have to display shoe separately from the decks, due to 'pop'
    cout << "Shoe: " << endl;
    displayShoe(&shoe);
    
********************************************************************************/
  
    
    
    
    /*************************Display house rules*************************/
    cout << endl;
    cout << endl;
    displayHouseRules();
    
    
    /*************************Setup player(s)*************************/
    string name;
    int money;
    cout << "Please enter your name: ";
    getline(cin, name);
    cout << "How much in chips would you like exchange?($): ";
    cin >> money;
    
    //instantiate player and dealer
    Dealer dealer;
    Player player1(name, money);

    cout << endl;
    cout << endl;
    
    /*************************Enter game loop*************************/
    int bet;
    char quit;
    int choice;
    char answer;
    char daction; //for player to 'hit' through dealer turn
    int cardCount;
    bool CardsCounted = false;
    char icount;
    int min = 25;
    int max = 500;
    
    cout << "Would you like for me to count cards(Hi Lo)?(y/n): ";
    cin >> icount;
    if(icount == 'y')
        CardsCounted = true;
    
    do
    {
        player1.reset();
        dealer.reset();
        
        if(player1.getTotalMoney()>0)
        {
            
            cout << "You have $" << player1.getTotalMoney() << ". ";
            cout << "Please place your bet($): ";
            cin >> bet;
            do
            {
                if(bet<min || bet>max && bet<=player1.getTotalMoney())
                {
                    cout << "Please bet the correct amount: ";
                    cin >> bet;
                }
                if(bet>player1.getTotalMoney())
                {
                    cout << "You don't have enough. Bet less: ";
                    cin >> bet;
                }
            }while(bet>player1.getTotalMoney() || bet<min || bet>max);
        }
        else
        {
            do
            {
            cout << "You have no more money. Quit?(y/n): ";
            cin >> quit;
            if(quit == 'y')
                exit(0);
            else
                cout << "You should really quit. Press 'y': ";
            cin >> quit;
            if(quit == 'y')
                exit(0);
            }while(quit != 'y');
        }

        player1.setBet(bet);
        
        cout << endl;
        cout << endl;
    
        //first deal
        deal(&shoe, &player1, &dealer);
        cout << "-------------------------------------------------------------------------" << endl;
        displayDealerH(&dealer, &player1);
        cout << endl;
        displayPlayerH(&player1, &dealer);
        cout << "-------------------------------------------------------------------------" << endl;
        if(CardsCounted)
        {
            cout << "Card Count: ";
            cout << countingCards(&player1, &dealer) << " ";
            cout << " | Shoe deck is " << (shoe.size()*100)/(52*4) << "% full." << endl;
            cout << endl;
        }
        
        displayOptions();
        cout << endl;
        cin >> choice;
    
        /********************************Main Game Loop************************/
        do
        {
            //this is where dealer turn loop begins after player is done with his turn
            if(!dealer.getDone() && player1.getDone()) 
            {
                cout << "Dealer's turn. ";
                cout << "Please hit any letter key to continue: ";
                cin >> daction;
                
                do
                {
                    //dealer keeps hitting on soft 17
                    if(daction)
                    {    
                        if(!dealer.isBust() && dealer.calcSumVal() < 17)
                        {
                            cout << "Dealer must hit. Please hit any letter key. ";
                            cin >> daction;
                            deal(&shoe, &dealer);
                            cout << endl;
                            cout << "-------------------------------------------------------------------------" << endl;
                            displayDealerH(&dealer, &player1);
                            cout << endl;
                            displayPlayerH(&player1, &dealer);
                            cout << "-------------------------------------------------------------------------" << endl;
                            if(CardsCounted)
                            {
                                cout << "Card Count: ";
                                cout << countingCards(&player1, &dealer);
                                cout << " | Shoe deck is " << (shoe.size()*100)/(52*4) << "% full." << endl;
                                cout << endl;
                            }
                        }
                        cout << endl;
                    }
                    
                }while(dealer.calcSumVal() < 17);
                dealer.setDone();
                
            }
            else
            {
                //this is player's turn loop
                switch(choice)
                {
                    //hit
                    case 1:
                        deal(&shoe, &player1);
                        break;
                    //stand
                    case 2:
                        if(player1.getSplit() && player1.getHandStand())
                        {
                            player1.setDone();
                        }
                        else if(player1.getSplit())
                        {
                            player1.setHandStand();
                        }
                        else
                        {
                            player1.setDone();
                        }
                        break;
                    //double    
                    case 3:
                        if(player1.getSplit())
                        {
                            cout << "You can't double on split.";
                        }
                        else
                        {
                            deal(&shoe, &player1);
                            player1.setDouble();
                            player1.setDone();
                        }
                        break;
                    //split
                    case 4:
                        if(player1.hand[0].getValue() == player1.hand[1].getValue())
                        {
                            split(&player1);
                        }
                        else
                        {
                            cout << "You cannot split.";
                        }
                        break;
                    //surrender
                    case 5:
                        player1.setSurrender();
                        cout << "You lose half your bet." << endl;
                        player1.setTotalMoney(player1.getTotalMoney() - (player1.getBet()/2) );
                        player1.setDone();
                        player1.setFinished();
                        dealer.setDone();
                        break;
                }
                cout << endl;
                cout << "-------------------------------------------------------------------------" << endl;
                displayDealerH(&dealer, &player1);
                cout << endl;
                displayPlayerH(&player1, &dealer);
                cout << "-------------------------------------------------------------------------" << endl;
                if(CardsCounted)
                {
                    cout << "Card Count: ";
                    cout << countingCards(&player1, &dealer);
                    cout << " | Shoe deck is " << (shoe.size()*100)/(52*4) << "% full." << endl;
                    cout << endl;
                }
                
                //if player is not done, continues to display choice
                if(!player1.getDone())
                {
                    displayOptions();
                    cin >> choice;
                }

            }
        }while(!dealer.getDone() && !player1.getFinished() && !player1.getSurrender());
        
        //go into reconcileBet function if both player and dealer is not bust
        if(!dealer.isBust() && !player1.getSurrender())
        {
            reconcileBet(&player1, &dealer);
        }
        
        
        //reset hands(clear vector))
        player1.hand.clear();
        player1.split.clear();
        dealer.hand.clear();
    
        cout << "Do you want to play again?(y/n): ";
        cin >> answer;
    }while(answer != 'n');
    
    

    return 0;
}

/*******************************Function Definitions*******************************/

//first deal to both player and dealer
void deal(queue<Card> *shoe, Player *p, Dealer *d)
{
    p->hand.push_back(shoe->front()); shoe->pop();
    d->hand.push_back(shoe->front()); shoe->pop();
    p->hand.push_back(shoe->front()); shoe->pop();
    d->hand.push_back(shoe->front()); shoe->pop(); 
}

//deal only to player
void deal(queue<Card> *shoe, Player *p)
{
    //if not split, deal one hand, else deal/play one hand at a time x 2
    if(!p->getSplit())
    {
        p->hand.push_back(shoe->front()); shoe->pop();
    }
    else if(p->getSplit() && !p->getFirstDone())
    {
        p->hand.push_back(shoe->front()); shoe->pop();
    }
    else if(p->getSplit() && p->getFirstDone() && !p->getSecondDone())
    {
        p->split.push_back(shoe->front()); shoe->pop();
    }
}

//deal only to dealer
void deal(queue<Card> *shoe, Dealer *d)
{
    d->hand.push_back(shoe->front()); shoe->pop();
}

//fill 52 card deck with card objects
void fillDeck(vector<Card> *deck, const int DECK_SIZE, string face[], string suit[], int value[])
{
    
    for(int k=0; k<DECK_SIZE; k++)
    {
        for(int j=0; j<4;j++)
        {
            for(int i=0; i<13; i++)
            {
                Card card(face[i], suit[j], value[i]);
                deck->push_back(card);
            }
        }
    }
    
    //random shuffle after deck is filled
    vector<Card>::iterator itr1;
    vector<Card>::iterator itr2;
    
    itr1 = deck->begin();
    itr2 = deck->end();
    
    random_shuffle(itr1, itr2);
}

//fill shoe with all 4 decks
void fillShoe(queue<Card> *shoe, vector<Card> &deck1, vector<Card> &deck2, vector<Card> &deck3, vector<Card> &deck4)
{
    for(int i=0; i<52; i++)
    {
        shoe->push(deck1[i]);
        shoe->push(deck2[i]);
        shoe->push(deck3[i]);
        shoe->push(deck4[i]);
    }
}

//this is just to test the deck was filled correctly
void displayDeck(vector<Card> *deck)
{
    int count = 0;
    for(int i=0; i<52; i++)
    {
        cout << deck->back().getFace() << "of" << deck->back().getSuit() << "(" << deck->back().getValue() << ")" << endl;
        deck->pop_back();
        count++;
    }
    cout << "Full deck displayed: " << count;
    cout << endl;
}

//this is just to test the shoe was filled correctly
void displayShoe(queue<Card> *shoe)
{
    int size = shoe->size();
    int count = 0;
    for(int i=0; i<size; i++)
    {
        cout << shoe->front().getFace() << "of" << shoe->front().getSuit() << "(" << shoe->front().getValue() << ")" << endl;
        shoe->pop();
        count++;
    }
    cout << "Full shoe displayed: " << count;
    cout << endl;
}

//display player hand
void displayPlayerH(Player *p, Dealer *d)
{
    //display this part if player did not split hand
    if(!p->getSplit())
    {
        
        cout << p->getName() << "'s Hand: " << "bet: $" << p->getBet() << "  Total Money: $" << p->getTotalMoney() << endl;
        cout << "******************************************" << endl;
        for(int i=0; i<p->hand.size(); i++)
        {
            cout << p->hand[i].getFace() << "of" << p->hand[i].getSuit() << "(" << p->hand[i].getValue() << ")" << " ";
        }
        if(p->calcSumVal() >= 21 && p->thereIsAce()) //if there is Ace and player is over 21, count Ace as value 1
        {
            p->setSumVal(p->calcSumVal()-10);
            cout << " \t\t-Total Value: " << p->getSumVal() << endl;   
        }
        else
        {
            cout << " \t\t-Total Value: " << p->getSumVal() << endl;
        }
        cout << "******************************************" << endl;

        if(p->isBust())
        {
            cout << "You are bust!" << endl;
            if(p->getDouble())
            {
                p->setTotalMoney(p->getTotalMoney()-(p->getBet()*2));
            }
            else
            {
                p->setTotalMoney(p->getTotalMoney()-p->getBet());
            }
            p->setFinished();
            d->setDone();
        }
        if(p->isNatural())
        {
            cout << "BlackJack(natural 21)! You win! We pay you 3:2." << endl;
            p->setTotalMoney(p->getTotalMoney()+(p->getBet()*1.5));
            p->setFinished();
            d->setDone();
        }
    }
    //display here if player did split hand
    else if(p->getSplit())
    {
        p->setSplitTrue();
        
        //Hand 1, after split
        cout << p->getName() << "'s Hand: " << "Hand 1 bet: $" << p->getBet() << " | " << "Hand 2 bet: $" << p->getSplitBet() << endl;
        cout << "******************************************" << endl;
        cout << "Hand 1: ";
        for(int i=0; i<p->hand.size(); i++)
        {
            cout << p->hand[i].getFace() << "of" << p->hand[i].getSuit() << "(" << p->hand[i].getValue() << ")" << " ";
        }
        if(p->calcSumVal() > 21 && p->thereIsAce()) //if there is Ace and player is over 21, count Ace as value 1
        {
            cout << " \t\t-Total Value: " << p->calcSumVal() - 10 << endl;
            p->setSumVal(p->calcSumVal()-10);
        }
        else
        {
            cout << " \t\t-Total Value: " << p->calcSumVal() << endl;
        }
        cout << endl;
        
        //Hand 2, after split
        cout << "Hand 2: ";
        for(int i=0; i<p->split.size(); i++)
        {
            cout << p->split[i].getFace() << "of" << p->split[i].getSuit() << "(" << p->split[i].getValue() << ")" << " ";
        }
        
        if(p->calcSplitSumVal() > 21 && p->thereIsAce())
        {
            cout << " \t\t-Total Value: " << p->calcSplitSumVal() - 10 << endl;
            p->setSplitSumVal(p->calcSplitSumVal()-10);
        }
        else
        {
            cout << " \t\t-Total Value: " << p->calcSplitSumVal() << endl;
        }
        cout << "******************************************" << endl;
        
        //test for bust, if so set 'finished' flag so that it round ends
        if(p->getSumVal() > 21)
        {
            //p->isBust();
            cout << "You are bust!" << endl;;
            if(p->getDouble())
            {
                p->setTotalMoney(p->getTotalMoney()-(p->getBet()*2));
            }
            else
            {
                p->setTotalMoney(p->getTotalMoney()-p->getBet());
            }
            p->setFirstDone();
        }
        if(p->getSplitSumVal() > 21)
        {
            //p->isBust();
            cout << "You are bust!" << endl;
            if(p->getDouble())
            {
                p->setTotalMoney(p->getTotalMoney()-(p->getSplitBet()*2));
            }
            else
            {
                p->setTotalMoney(p->getTotalMoney()-p->getSplitBet());
            }
            p->setSecondDone();
        }
        if(p->getFirstDone() && p->getSecondDone())
        {
            p->isBust();
            p->setFinished();
            d->setDone();
            p->setBothDone();
        }
    }
}

void displayDealerH(Dealer *d, Player *p)
{
    cout << "Dealer Hand: " << endl;
    cout << "******************************************" << endl;
    int size;
    //if player is not done with his turn, hide the dealer's second card by simply reducing the hand size by one card
    if(!p->getDone())
    {
        size = (d->hand.size()) - 1;
    }
    else
    {
        size = d->hand.size();
    }
    
    for(int i=0; i<size; i++)
    {
        cout << d->hand[i].getFace() << "of" << d->hand[i].getSuit() << "(" << d->hand[i].getValue() << ")" << " ";
    }
    //display only the dealer's first card
    if(!p->getDone())
    {
        cout << " \t\t\t-Total Value: " << d->calcSumVal()-(d->hand[1].getValue()) << endl;
        cout << "******************************************" << endl;
    }
    //players is done with his turn, so reveal dealer's second card
    else
    {
        cout << " \t\t\t-Total Value: " << d->calcSumVal() << endl;
        cout << "******************************************" << endl;
        
        if(d->isBust())
        {
            cout << "Dealer bust. You win!" << endl;
            if(p->getDouble())
            {
                p->setTotalMoney((p->getBet()*2)+p->getTotalMoney());
            }
            else
            {
                p->setTotalMoney(p->getBet()+p->getTotalMoney());
            }
            d->setDone();
        }
        if(d->isNatural())
        {
            cout << "Dealer has BlackJack(natural 21)." << endl;
            d->setDone();
        }
    }
}

void displayHouseRules()
{
    cout << "\tWelcome to Shoe Black Jack! " << endl;
    cout << "\tHere are the house rules: " << endl;
    cout << "\t1.Splits allowed on same rank." << endl;
    cout << "\t2.Multi splits allowed." << endl;
    cout << "\t3.No Ace splits." << endl;
    cout << "\t4.No Double down after split." << endl;
    cout << "\t5.Dealer stands on soft 17." << endl;
    cout << "\t6.Four decks shoe." << endl;
    cout << "\t7.Minimum bet $25 - Maximum bet $500." << endl;
    cout << "\t8.After split no 'Natural 21'. Pays 1:1." << endl;
            
    cout << endl;
}

void displayOptions()
{
    cout << "Option to player: " << endl;
 
    cout << "1).Hit  2).Stand  3).DoubleDown  4).Split  5).Surrender"  << endl;
}

void split(Player *p)
{
    p->split.push_back(p->hand[0]);
    p->hand.pop_back();
    p->setSplitTrue();
    p->setSplitBet();
}

void reconcileBet(Player *p, Dealer *d)
{
    if(!p->getBust() && !d->getBust())
    {
        if(p->getSumVal() == d->getSumVal())
        {
            cout << "It's a push." << endl;
        }
    
        if(p->getSumVal()>d->getSumVal())
        {
            cout << "You win!" << endl;
            if(p->getDouble())
            {
                p->setTotalMoney((p->getBet()*2)+p->getTotalMoney());
            }
            else
            {
                p->setTotalMoney(p->getBet()+p->getTotalMoney());
            }
        }
    
        if(p->getSumVal()<d->getSumVal())
        {
            cout << "Dealer wins." << endl;
            if(p->getDouble())
            {
                p->setTotalMoney(p->getTotalMoney()-(p->getBet()*2));
            }
            else
            {
                p->setTotalMoney(p->getTotalMoney()-p->getBet());
            }
        }
    
        if(p->getSplitSumVal()>d->getSumVal() && p->getSplit())
        {
            cout << "You win the split hand!" << endl;
            if(p->getDouble())
            {
                p->setTotalMoney((p->getSplitBet()*2)+p->getTotalMoney());
            }
            else
            {
                p->setTotalMoney(p->getSplitBet()+p->getTotalMoney());
            }
        }
    
        if(p->getSplitSumVal()<d->getSumVal() && p->getSplit())
        {
            cout << "Dealer wins over your split hand." << endl;
            if(p->getDouble())
            {
            p->setTotalMoney(p->getTotalMoney()-(p->getSplitBet()*2));
            }
            else
            {
                p->setTotalMoney(p->getTotalMoney()-p->getSplitBet());
            }
        }
    }

}

int countingCards(Player *p, Dealer *d)
{
    int cardCount;
    
    for(int i=0; i<p->hand.size(); i++)
    {
        if(p->hand[i].getValue() < 7)
            cardCount++;
        else if(p->hand[i].getValue() > 9)
            cardCount--;
    }
    for(int i=0; i<p->split.size(); i++)
    {
        if(p->split[i].getValue() < 7)
            cardCount++;
        else if(p->split[i].getValue() > 9)
            cardCount--;
    }
    
    //if player is not done yet, don't count the dealer's hidden card in counting cards
    if(!p->getDone())
    {
        for(int i=0; i<d->hand.size()-1; i++)
        {
            if(d->hand[i].getValue() < 7)
                cardCount++;
            else if(d->hand[i].getValue() > 9)
                cardCount--;
        }
    }
    else
    {
        for(int i=0; i<d->hand.size(); i++)
        {
            if(d->hand[i].getValue() < 7)
                cardCount++;
            else if(d->hand[i].getValue() > 9)
                cardCount--;
        }
    }
    
    return cardCount;
}
