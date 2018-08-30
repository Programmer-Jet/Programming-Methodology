#include "project1.h"

    template <typename t>
    void validInput(t &myInput){
    while( (!(cin>>myInput)) || (myInput < 0)){
    cin.fail() ? cout << "\nInvalid input. \nEnter new number: " : (!(myInput<0)) ? cout << " " : cout << "\nEnter positive number: ";
    cin.clear();
    cin.ignore(10000,'\n');
    }
}
    template <typename t>
    void  makeAccount(vector <t> &bank) {
    t newacc;

    int number = rand() % 9000 + 1000;;
    newacc.accountNumber = number;

    cout << "Creating bank account number " << number;

    cout << "\n\nEnter first name: ";
    cin >> newacc.firstName;
    cout << "Enter last name: ";
    cin>> newacc.lastName;
    cout << "Enter starting balance: ";
    validInput(newacc.accountBalance);

    bank.push_back(newacc);

    cout << endl;
}

template <typename t>
void printAccount (vector <t> &bank) {
cout << "Enter account number to print: ";
int num;
validInput(num);
bool accountFound = false;
for (t newacc : bank) {
	if (newacc.accountNumber == num) {
    cout << "Account number: " << newacc.accountNumber << "\t Balance: " << newacc.accountBalance << endl;
    cout << "Last name: " << newacc.lastName << "\t\t First name: " << newacc.firstName << endl << endl;
    accountFound = true;
    }
}
if (!accountFound) {
cout << "Account not found." << endl;
}
}

template <typename t>
void printAllAccounts(vector <t> &bank){
for (t newacc : bank)
	{
	cout << "Account number: " << newacc.accountNumber << "\t Balance: " << newacc.accountBalance << endl;
    cout << "Last name: " << newacc.lastName << "\t\t First name: " << newacc.firstName << endl << endl;
}
}

template <typename t>
void withdrawAccount (vector <t> &bank) {
double withdrawal;
cout << "Enter account number for withdrawal: ";
int num;
validInput(num);
bool accountFound = false;
for (unsigned int i = 0; i < bank.size(); i++) {
	if (bank[i].accountNumber == num) {
		cout << "Enter amount to be withdrawn: ";
        validInput(withdrawal);
        bank[i].accountBalance -= withdrawal;
        accountFound = true;
}
    }
    if (!accountFound) {
        cout << "Account not found." << endl;
        }
}

template <typename t>
void depositAccount(vector <t> &bank){
double deposit;
cout << "Enter account number for deposit: ";
int num;
validInput(num);
bool accountFound = false;
for (unsigned int i = 0; i < bank.size(); i++) {
	if (bank[i].accountNumber == num) {
        cout << "Enter amount to be deposit: ";
        validInput(deposit);
        bank[i].accountBalance += deposit;
        accountFound = true;
    }

    }
     if (!accountFound) {
        cout << "Account not found." << endl;
        }
}

template <typename t>
void sortAccounts(vector <t> &bank){
int ismall;
    for(unsigned int i = 0; i < bank.size(); i++){
        ismall = i;
        for(unsigned int j=i; j < bank.size(); j++){
            if(bank[ismall].accountNumber > bank[j].accountNumber){
                ismall = j;
            }
        }
        swap(bank[i],bank[ismall]);
    }
}

template <typename t>
void deleteAccount(vector <t> &bank){
cout << "Enter account number to be deleted: ";
int num;
validInput(num);
bool accountFound = false;
for (int counter = 0; counter < bank.size(); counter++) {

    if (bank[counter].accountNumber == num) {
    bank.erase(bank.begin() + counter);
    accountFound = true;
    }
}
if (!accountFound){
cout << "Account not found." << endl;
}
}

void menu(int* num) {
    int selection = 0;
    cout << "Welcome to MadeUp Banking. Select options below: " << endl;
    cout << "\t 1. Make new account." << endl;
    cout << "\t 2. Display all accounts." << endl;
    cout << "\t 3. Deposit to an account." << endl;
    cout << "\t 4. Withdraw from an account." << endl;
    cout << "\t 5. Print account." << endl;
    cout << "\t 6. Delete an account." << endl;
    cout << "\t 7. Quit." << endl;
    cout << "Selection: ";

cin >> selection;
*num = selection;
cout << endl;
}

