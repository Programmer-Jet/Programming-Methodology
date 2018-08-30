#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;
//a program to manage a bank account and a stock portfolio
//write a loop using fstream to read the file line by line and parse according to tabs
//then create three vectors
//turn 16 bit to utf8
//need getline
//********************************** ACCOUNT ***********************************
class Account
{
protected:
    double m_cashBalance;
public:
    Account(double cashBalance = 10000.00) //default constructor; starting balance for any account will be $10000.00
        : m_cashBalance(cashBalance)
    {

    }
    double getCashBalance() const
    {cout << "Cash balance = $" << m_cashBalance << endl;
    return m_cashBalance;}
};

//******************************** BANKACCOUNT ******************************
class Stock;
class BankAccount : public Account //derived class "BankAccount" from base class "Account"
{
private:
public:
    double displayCurrentBalance()
    {
    //figure out code for this
    return 0;
    }
    void depositMoney(BankAccount &bAccount) //testing depositMoney concept
    {
    cout << "Enter amount to be deposit: ";
    double deposit;
    cin >> deposit;
    cout << "\nDeposit $" << deposit << " to bank account" << endl;
    bAccount.m_cashBalance += deposit;
    //cout << "Cash balance = $" << bAccount.m_cashBalance << endl;
    }
    void withdrawMoney()
    {}
    void calculatePortfolioValue(vector <Stock> &portfolio)
    {
        //for each element in portfolio vector
        for (unsigned int i = 0; i < portfolio.size(); i++) {
            //portfolio[i].
            //m_totalPortfolioValue = price*stock
            //cout << "Total portfolio value: $" << m_cashBalance + portfolio[i].m_numberOfShares*portfolio[i].m_price;
            //something like that; probably should not be inside the for loop
        }
    }
};
//******************************** STOCKACCOUNT *********************************
class Stock;
class StockAccount : public Account //derived class "stockAccount" from base class "Account"
{
private:
    vector <Stock> m_portfolio;
    double m_totalPortfolioValue;

public:
    double displayPrice()
    {
    cout << "Enter stock symbol for checking price: ";
    string stock;
    cin >> stock;
    //if ()
    }
    buyStock(){}
    sellStock(){}
    displayPortfolio(){}


};
//********************************** STOCK ***************************
class Stock
{
private:
    string m_stockSymbol;
    string m_name;
    double m_price;
    int m_numberOfShares;
public:
    Stock(string stockSymbol, string name, double price, int numberOfShares = 0) //stock default constructor
        : m_stockSymbol(stockSymbol), m_name(name), m_price(price), m_numberOfShares(numberOfShares)
    {

    }

    int getNumberOfShares(){return m_numberOfShares;}
    void setNumberOfShares(int numberOfShares){m_numberOfShares = numberOfShares;}
    string getStockSymbol(){return m_stockSymbol;}
    double getPrice(){return m_price;}
    double setPrice(double price){return m_price = price;}
    string getName(){return m_name;}
};
//**************************** ACCOUNT MANAGEMENT MENUS ********************************************
void mainMenu(int* num)
{
int selection = 0;
cout << "Welcome to the Account Management System." << endl;
cout << "Please select an account to access" << endl;
cout << "\t 1. Stock Portfolio Account" << endl;
cout << "\t 2. Bank Account." << endl;
cout << "\t 3. Exit" << endl;
cout << "Your selection: ";

cin >> selection;
*num = selection;
cout << endl;
}

void stockMenu(int* num)
{
int selection = 0;
cout << "Please select an option" << endl;
cout << "\t 1. Display current price for a stock symbol" << endl;
cout << "\t 2. Buy stock" << endl;
cout << "\t 3. Sell stock" << endl;
cout << "\t 4. Display current portfolio" << endl;
cout << "\t 5. Display transactions history" << endl;
cout << "\t 6. Return to main menu" << endl;
cout << "Your selection: ";

cin >> selection;
*num = selection;
cout << endl;
}
/*
    vector <Account> bankAccounts;
    bool val = true;
    while (val) {

        mainMenu(inputPtr);

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
    */

//********************************** MAIN ****************************************

int main()
{
    cout << "Hello world!" << endl;
    BankAccount myAccount;
    myAccount.getCashBalance();
    myAccount.depositMoney(myAccount);
    myAccount.getCashBalance();

    // ifstream is used for reading files
    // We'll read from a file called Sample.dat
    ifstream inf("stock1.txt");

    // If we couldn't open the output file stream for reading
    if (!inf)
    {
        // Print an error and exit
        cerr << "Uh oh, Sample.dat could not be opened for reading!" << endl;
        exit(1);
    }

    // While there's still stuff left to read
    while (inf)
    {
        // read stuff from the file into a string and print it
        string strInput;
        getline(inf, strInput);
        cout << strInput << endl;
    }
    return 0;
}
