#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

class Card
{
private:
    int m_face;
    int m_suit;
public:
    Card(int face, int suit);
    Card();
    int getsuit();
    int getface();
};

#endif // CARD_HPP_INCLUDED
