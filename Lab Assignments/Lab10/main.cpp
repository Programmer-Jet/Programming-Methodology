#include <iostream>
#include "card.cpp"
#include "card.hpp"
#include "deckofcards.cpp"
#include "deckofcards.hpp"

using namespace std;

int main()
{
    DeckOfCards deck = DeckOfCards();
    deck.printCards();
    return 0;
}

/*
Main function should be simple:
1) invoke an instance of a DeckOfCards class
2) call a print function

2 classes: DeckOfCards, Card
- Card would be like a hand of cards
- print function inside DeckOfCards should print out something like "you have the ace of spades"
*/
