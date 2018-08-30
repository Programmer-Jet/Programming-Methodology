#include "Account.h"
#include "BankAccount.h"
#include "StockAccount.h"
#include "Structure.h"
#include "Account.cpp"
#include "BankAccount.cpp"
#include "StockAccount.cpp"
#include <iostream>
#include <string>
using namespace std;

Account account;

int main() {

    StockAccount a1;
    BankAccount a2;

    cout << "Welcome to the Account Management System." << endl;

    bool flag = true;
    int selection = 0;
    char test[256];
    string line;
    while (flag) {

        cout << "Please select an account to access" << endl
            << "\t1. Stock Portfolio Account" << endl
            << "\t2. Bank Account" << endl
            << "\t3. Exit" << endl
            << "\tYour selection: ";

        cin.getline(test, 256);
        selection = atoi(test);

        switch (selection) {
            case 1:
                a1.menu(account);
                break;
            case 2:
                a2.menu(account);
                break;
            case 3:
                cout << "Program terminated.\n";
                flag = false;
                break;
            default:
                break;
        }
    }

    return 0;
}
