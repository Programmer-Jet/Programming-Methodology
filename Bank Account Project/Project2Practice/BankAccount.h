# ifndef BANKACCOUNT_H
# define BANKACCOUNT_H

# include <iostream>
using namespace std;

class BankAccount: public Account {
public:
	BankAccount();
	void menu(Account&);
	void deposit(Account&,double);
	void withdraw(Account&,double);
	void displayPortfolio(Account&);
	void displayTransactions(Account&);
};
# endif


