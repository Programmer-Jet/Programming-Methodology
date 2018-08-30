#include "card.hpp"

Card::Card(int face, int suit){//:m_face(face),m_suit(suit){;}
    m_face = face;
    m_suit = suit;
}

Card::Card(){;}

int Card::getsuit(){
    return m_suit;
}

int Card::getface(){
    return m_face;
}
