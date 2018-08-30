#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Term
{
private:
    int m_coefficient;
    int m_exponent;
public:
    Term(int coeff, int expon)
    {
        m_coefficient = coeff;
        m_exponent = expon;
    }
    int getExponent(){return m_exponent;}
    int getCoefficient(){return m_coefficient;}
    void setExponent(int exponent){m_exponent = exponent;}
    void setCoefficient(int coefficient){m_coefficient = coefficient;}

    void printTerm()
    {
    cout << m_coefficient << "x^" << m_exponent << endl;
    }
}; //end Class Term

class Polynomial
{
private:
    vector<Term> polynomial; //polynomial is an array of terms
public:
    Polynomial(vector<Term> P) //default constructor
    {
        polynomial = P;
    }

    void printPolynomial(vector<Term> &P)
    {
    for (auto i: P)
    cout << i << ' ';
    }
    //Polynomial operator+ (const Polynomial & P) {}
    Polynomial operator+(vector<Term> &firstPoly,vector<Term> &secondPoly)
    {
        Polynomial sum;
        for(unsigned int i=0; i<firstPoly.size(); ++i) //for each Term in vector firstPoly
        {
        Term firstTemp = firstPoly[i]; /*Store each term of this array in a variable to compare it's
        exponent value with the exponent value for each element in the second loop*/
            for (unsigned int j=0; j<secondPoly.size(); ++j)
            {
            Term secondTemp = secondPoly[j];
                if (firstTemp.getExponent() == secondTemp.getExponent())
                {
                    int coeff = firstTemp.getCoefficient() + secondTemp.getCoefficient();
                    int newExponent = firstTerm.getExponent();
                    Term newTerm;
                    newTerm.setExponent(newExponent);
                    newTerm.setCoefficient(newCoefficient);
                    //add newTerm to Polynomial sum vector
                }
            }
        }
    }

    Polynomial operator-(vector<Term> &firstPoly,vector<Term> &secondPoly)
    {
        Polynomial subtraction;
        for(unsigned int i=0; i<firstPoly.size(); ++i) //for each Term in vector firstPoly
        {
        Term firstTemp = firstPoly[i]; /*Store each term of this array in a variable to compare it's
        exponent value with the exponent value for each element in the second loop*/
            for (unsigned int j=0; j<secondPoly.size(); ++j)
            {
            Term secondTemp = secondPoly[j];
                if (firstTemp.getExponent() == secondTemp.getExponent())
                {
                    int coeff = firstTemp.getCoefficient() - secondTemp.getCoefficient();
                    int newExponent = firstTerm.getExponent();
                    Term newTerm;
                    newTerm.setExponent(newExponent);
                    newTerm.setCoefficient(newCoefficient);
                    //add newTerm to Polynomial sum vector
                }
            }
        }
    }

    void assignPolynomial(vector<Term>& newPoly, vector<Term>& original)//assign one Polynomial to another
    {
        newPoly.swap(original); //the new Vector is assigned the original vector
        copy(begin(newPoly), end(newPoly), ostream_iterator<Term>(cout, " ")); //print out elements of vector
    }

};

int main()
{
    Term term1(5,2); //5x^2
    Term term2(3,1); //3x
    Term term3(7,0); //7
    Polynomial p(vector<Term>{term1,term2,term3}); //creates polynomial 5x^2 + 3x +7
    Term term4(3,2); //3x^2
    Term term5(6,1); //6x
    Term term6(4,0); //4
    Polynomial w(vector<Term>{term4,term5,term6}); //creates polynomial 3x^2 + 6x +4
    return 0;
}

//do normal functions, polynomial.add, etc., then focus on overloading. Easier to debug that way.
