# ifndef ACCOUNT_H
# define ACCOUNT_H

#include "Structure.h"
#include <iostream>
using namespace std;

class Account {
public:
	Account();
	double getBalance();
	void setBalance(double);
    vector <Portfolio> portfolioList;
    double m_cashBalance;
};
# endif
