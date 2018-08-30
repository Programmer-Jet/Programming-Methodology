# ifndef STOCKACCOUNT_H
# define STOCKACCOUNT_H

# include <iostream>
using namespace std;

class StockAccount: public Account {
public:
	StockAccount();
	void menu(Account&);
	void stockPrice(string);
	void buyStock(Account&, string, int, double);
	void sellStock(Account&, string, int, double);
    void displayPortfolio(Account&);
    void displayTransactions(Account&);
private:

};
# endif

