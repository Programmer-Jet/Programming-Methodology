#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

class Polynomial
{
private:
    vector<Term> polynomial; //polynomial is an array of terms
public:
    Polynomial(vector<Term> P) //default constructor
    {polynomial = P;}
    //Polynomial operator+ (Polynomial & P) {}
    ~Polynomial() //destructor
    {delete Polynomial;}
    //set and get functions
    void setPolynomial(vector<Term> P);
    int getPolynomial();
};


#endif // POLYNOMIAL_H_INCLUDED
