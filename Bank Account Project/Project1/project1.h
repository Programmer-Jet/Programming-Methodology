#ifndef PROJECT1_H_INCLUDED
#define PROJECT1_H_INCLUDED

# include <iostream>
using namespace std;

void menu(int*);
template <typename t>
void makeAccount(vector <t> &);
template <typename t>
void printAccount(vector <t> &);
template <typename t>
void printAllAccounts(vector <t> &);
template <typename t>
void depositAccount(vector <t> &);
template <typename t>
void withdrawAccount(vector <t> &);
template <typename t>
void sortAccounts(vector <t> &);
template <typename t>
void deleteAccount(vector <t> &);
template <typename t>
void validInput(vector <t> &);

#endif // PROJECT1_H_INCLUDED
