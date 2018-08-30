/*Class DeckOfCards should contain:
1) Two Card objects named deck to store two cards.
2) A constructor that takes no arguments and initializes both cards in the deck. You can give these
two cards a random face value and suit value, but make sure they are not the same.
3) A printCards function that prints the two cards */
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "deckofcards.hpp"
#include <cstdlib>
#include <ctime>
using namespace std;

DeckOfCards::DeckOfCards(){
    srand(time(NULL));
    int m_suit = rand() % 4 +1;
    int m_face = rand() % 13 + 1;
    int m_suit2 =rand() % 4 +1;
    int m_face2 = rand() % 13 + 1;

    m_card1 = Card(m_suit, m_face);
    m_card2 = Card(m_suit2, m_face2);
}
 void DeckOfCards::printCards()
    {
        cout << "You have the " << m_card1.getface() << " of " << m_card1.getsuit() << endl;
        cout << "You also have the " << m_card2.getface() << " of " << m_card2.getsuit() << endl;
    }
