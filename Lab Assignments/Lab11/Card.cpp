#include "Card.h"

//constructor with two parameters
Card::Card(int face, int suit)
{
m_face = face;
m_suit = suit;
}

string Card::toString()
{
return (m_face + " of " + m_suit);
}

//put all the face values in an array as strings
string faces[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};
//put all the suit values in an array as strings
string suits[] = {"Hearts", "Diamonds", "Clubs", "Spades"};
