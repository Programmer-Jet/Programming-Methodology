#include "Account.h"
#include <iostream>
#include "Structure.h"
using namespace std;

Account::Account()
{
    m_cashBalance = 10000;
}
double Account::getBalance()
{
    return m_cashBalance;
}
void Account::setBalance(double initialBalance)
{
    m_cashBalance = initialBalance;
}

