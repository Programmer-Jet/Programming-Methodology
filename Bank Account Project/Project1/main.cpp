/*
Jonathan Tsai
Program Methodology I
Project 1: Banking System
*/

#include <iostream>
#include <cstdlib>
#include <ctime> //used later on for generating a random seed value using current time
#include <vector>
#include <cmath>
#include <algorithm>
#include "project1.cpp"
using namespace std;

int main(){
    srand( time(NULL) );
    int input = 0;
    int* inputPtr = &input;

    struct Account{
        int accountNumber;
        string lastName;
        string firstName;
        double accountBalance;
    };

    vector <Account> bankAccounts;
    bool val = true;
    while (val) {

        menu(inputPtr);

        switch(input){
        case 1:
        makeAccount(bankAccounts);
        sortAccounts(bankAccounts);
        break;
        case 2:
        printAllAccounts(bankAccounts);
        break;
        case 3:
        depositAccount(bankAccounts);
        break;
        case 4:
        withdrawAccount(bankAccounts);
        break;
        case 5:
        printAccount(bankAccounts);
        break;
        case 6:
        deleteAccount(bankAccounts);
        break;
        case 7:
            cout << "Program terminated.";
        val = false;
        }
    }
    cout << endl;
    return 0;
}

/* Questions:
1) What should be the function arguments?
2) Verify all functions working as they should

*/
