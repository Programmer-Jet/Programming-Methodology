#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
/*Class Card should provide:
a) Data members face and suit of type int.
b) A constructor that receives two ints representing the face and suit and uses them to initialize the data members.
c) Two static arrays of strings representing the faces and suits.
d) A toString function that returns the Card as a string in the form “face of suit.” You can use the + operator to
concatenate strings.*/
class Card{
private:
//create two card variables face and suit
    int m_face;
    int m_suit;

public:
//constructer with parameters
    Card(int face, int suit);
    string toString();
    static const string faces[];
    static const string suits[];
};

#endif // CARD_H_INCLUDED
