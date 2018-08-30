#ifndef COMPLEX_H_INCLUDED
#define COMPLEX_H_INCLUDED
// Lab 1: Complex.h
// Complex numbers have the form realPart + imaginaryPart * i;
// Below is the complex class definition
class Complex
{
public:
    Complex(double = 0, double = 0);
    void setComplexNumber(double, double);
    Complex add(const Complex &right);
    Complex subtract(const Complex &right);
    void printComplex();
private:
    double realPart;
    double imaginaryPart;
};


#endif // COMPLEX_H_INCLUDED
