#include "BankAccount.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <sstream>
#include <string>
#include <math.h>
#include <wchar.h>
#include <iomanip>
#include <errno.h>
#include <fstream>
#include "Structure.h"
using namespace std;

BankAccount::BankAccount() {

}

void BankAccount::menu(Account& account) {
	bool flag = true;
	int selection;
	char test[256];
	while (flag) {
		cout << "\nPlease select an option" << endl
			<< "\t1. View account balance" << endl
			<< "\t2. Deposit money" << endl
			<< "\t3. Withdraw money" << endl
			<< "\t4. Display transaction history" << endl
			<< "\t5. Return to previous menu" << endl;

		cout << "\tYour selection: ";

		cin.getline(test, 256);
        selection = atoi(test);

		switch(selection) {
			case 1:
				displayPortfolio(account);
				break;
			case 2: {
				string line;
				double amount;
				cout << "\n\tDeposit Amount" << endl;
				getline(cin,line);
				stringstream ss;
				ss << line;
				ss >> amount;
				deposit(account,amount);
				break;
			}
			case 3: {
				string line;
				double amount;
				cout << "\n\tWithdraw amount" << endl;
				getline(cin,line);
                stringstream ss;
				ss << line;
				ss >> amount;
				withdraw(account,amount);
				break;
			}
			case 4:
				displayTransactions(account);
				break;
			case 5:
				flag = false;
				break;
			default:
				cout << "\n\tBANK ACCOUNT - INPUT = default" << endl;
				break;
		}
	}
}
//______________________________________________FUNCTION DEFINITIONS________________________________________________
void BankAccount::displayPortfolio(Account& account)
{
    vector<Portfolio> port = account.portfolioList;
    cout << "\tCash Balance " << account.m_cashBalance << endl;
    double totalbal;
    for (unsigned int i = 0; i < port.size(); i++)
    {
        cout << "\tSYMBOL = " << port[i].symbol << "\tSHARE = " << port[i].amount << "\tPRICE = "
             << port[i].price << "\tCOMPANY = "  << port[i].company << "\tTOTAL = "  << port[i].total<< endl;
        totalbal += port[i].total;

    }
    cout << "\tTotal Portfolio Value " << account.m_cashBalance + totalbal << endl;
}

void BankAccount::deposit(Account& account,double val) {
	cout << "\tCALLING DEPOSIT FUNCTION\t\t AMOUNT = " << val << endl;
    account.m_cashBalance += val;

    stringstream sstream;
    sstream << val;
    stringstream anotherSS;
    anotherSS << account.m_cashBalance;
    string line = "Deposit\t" + sstream.str() + "\t" + anotherSS.str();

    ofstream myfile;
    myfile.open("bank_transaction_history.txt", ios_base::app);
    myfile << line;
    myfile.close();

    displayPortfolio(account);
}

void BankAccount::withdraw(Account& account,double val) {
	cout << "\tCALLING WITHDRAW FUNCTION\t\t AMOUNT = " << val << endl;
    account.m_cashBalance -= val;

    stringstream sstream;
    sstream << val;
    stringstream anotherSS;
    anotherSS << account.m_cashBalance;
    string line = "Withdraw\t" + sstream.str() + "\t" + anotherSS.str();

    ofstream myfile;
    myfile.open("bank_transaction_history.txt", ios_base::app);
    myfile << line;
    myfile.close();

    displayPortfolio(account);
}

void BankAccount::displayTransactions(Account& account)
{
    ifstream file("bank_transaction_history.txt");
    string line;
    cout << "Action\tAmount\tCash Balance" << endl << endl;
    while (getline(file, line))
    cout << line << endl;
    file.close();
}
