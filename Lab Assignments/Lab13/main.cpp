/*  Jonathan Tsai
    4/27/17
    Section 01
    Lab 13: Bank Account */
#include <iostream>
using namespace std;
//***********************************ACCOUNT****************************
class Account
{
public:
    double m_accountBalance;
    Account(double initialBalance = 0.0) //default constructor
        : m_accountBalance(initialBalance)
    {

    }

    double getBalance() //return the current balance
    {cout << "Account balance = $" << m_accountBalance << endl;
    return m_accountBalance;}

    void credit() //add an amount to the current balance
    {
    cout << "Enter amount for credit: ";
    double credit;
    cin >> credit;
    cout << "\nCredit $" << credit << " to bank account" << endl;
    m_accountBalance += credit;
    cout << "Account balance = $" << m_accountBalance << endl;
    }

    void debit() //withdraw money from the Account
    {
    cout << "Enter amount for debit: ";
    double debit;
    //ensure that the debit amount does not exceed the Account balance
    while( (!(cin>>debit)) || (debit > m_accountBalance))
        {
        cin.fail() ? cout << "\nInvalid input. \nEnter new number: " : (!(debit > m_accountBalance)) ? cout << " " : cout << "\nEnter a debit smaller than the account balance: ";
        cin.clear();
        cin.ignore(10000,'\n');
        }
    cout << "\nWithdraw $" << debit << " from bank account" << endl;
    m_accountBalance -= debit;
    cout << "Account balance = $" << m_accountBalance << endl << endl;
    }
};
//********************************SAVINGSACCOUNT*******************************
class SavingsAccount : public Account
{
private:
    double m_interestRate; //interest rate (percentage) assigned to the account
public:
    SavingsAccount(double initialBalance, double interestRate) //default constructor
        : Account(initialBalance) , m_interestRate(interestRate)
    {

    }
    double calculateInterest()
    {
        double interestEarned = m_interestRate*.01*m_accountBalance;
        cout << "Interest earned is: $" << interestEarned << endl;
        return 0;
    }
};

int main()
{
    Account myAccount(500.00);
    myAccount.getBalance();
    myAccount.credit();
    myAccount.debit();
    SavingsAccount mySavings(200.00,100); //create a SavingsAccount with initial balance of $200 and 100 percent interest rate
    mySavings.calculateInterest(); //should output $200
    return 0;
}
