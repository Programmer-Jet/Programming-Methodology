#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

struct Portfolio
{
    string symbol;
    string company;
    int amount;
    double price;
    double total;

};

#endif // STRUCTURE_H_INCLUDED
