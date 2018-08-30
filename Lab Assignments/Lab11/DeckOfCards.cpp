#include "DeckOfCards.h"
#include <iostream>
using namespace std;
/*Class DeckOfCards should contain:
a) An array of Cards named deck to store the Cards.
b) An integer currentCard representing the next card to deal.
c) A default constructor that initializes the Cards in the deck.
d) A shuffle function that shuffles the Cards in the deck. The shuffle algorithm should iterate
through the array of Cards. For each Card, randomly select another Card in the deck and swap the two Cards.
e) A dealCard function that returns the next Card object from the deck.
f) A moreCards function that returns a bool value indicating whether there are more Cards to deal.*/
const int SIZE = 52;

DeckOfCards::DeckOfCards()
{
//initialize deck from the card class to a new array using the word "new"
Card deck[count] = deck[SIZE];
currentCard = 0;
//create a for loop to literally place each card into the new array
for(int count = 0; count < SIZE; count++)
{
//deck at postion count will be equal to card, each with a different face and suit
deck[count] = Card(faces[count % 13], suits[count / 13]);
}
}

void DeckOfCards::shuffle()
{
//start at current card
currentCard = 0;
//create a for loop so all 52 cards will be shuffled
for(int first = 0; first < SIZE; first++){
//create an int called second, which represents some random position
    int second = (rand() + time(0)) % SIZE;
//our goal in the following lines is to randomly select another Card in the deck and swap the two Cards.
    int temp = deck[first];
    deck[first] = deck[second];
    deck[second] = temp;
}
}

Card DeckOfCards::dealCard()
{
//if we are out of cards
if(currentCard > SIZE)
{
//shuffle
shuffle();
}
//if we are not out of cards
if( currentCard < SIZE)
{
//return deck at that current card and then increment
return (deck[currentCard++]);
}
//return the first card in the deck that we just found
return (deck[0]);
}




