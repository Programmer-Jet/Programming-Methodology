#include <iostream>
#include "Card.h"
#include "DeckOfCards.h"
#include "Card.cpp"
#include "DeckOfCards.cpp"

using namespace std;
//The driver program should create a DeckOfCards object, shuffle the cards, then deal the 52 cards
int main()
{
DeckOfCards deck;
//Card currentCard;
deck.shuffle();
//determine how many cards you want to print out to the user
/*for( int i = 0; i <= 52; i++)
{
currentCard = deck.dealCard();
cout << currentCard.toString() << endl;
}
*/
    return 0;
}
