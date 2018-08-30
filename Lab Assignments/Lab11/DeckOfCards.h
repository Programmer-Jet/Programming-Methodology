#ifndef DECKOFCARDS_H_INCLUDED
#define DECKOFCARDS_H_INCLUDED

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
class DeckOfCards{
private:
    Card deck[52];
    int currentCard;
public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    //bool moreCards();
};

#endif // DECKOFCARDS_H_INCLUDED
