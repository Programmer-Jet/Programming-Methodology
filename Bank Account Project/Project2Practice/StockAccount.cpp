#include "StockAccount.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <windows.h>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include "Structure.h"
using namespace std;

//string to_string(int i);

StockAccount::StockAccount() {

}

void StockAccount::menu(Account& account) {
	bool flag = true;
    srand(time(NULL));
	int selection = 0;
	char test[256];

	while (flag) {
		cout << "\nPlease select an option" << endl
			<< "\t1. Display current price for a stock symbol" << endl
			<< "\t2. Buy stock" << endl
			<< "\t3. Sell stock" << endl
			<< "\t4. Display current portfolio" << endl
			<< "\t5. Display transaction history" << endl
			<< "\t6. Return to previous menu" << endl;

		cout << "\tYour selection: ";

		cin.getline(test, 256);
        selection = atoi(test);

		switch(selection) {
			case 1: {
				char line[256];
				cin.getline(line, 256);
				string symbol(line); // CONVERT TO STRING SO YOU CAN USE THE CODE SNIPPET IN THE PREVIOUS INSTRUCTION
				stockPrice(symbol);
				break;
			}
			case 2: {
				cout << "\n\tEnter buy options: " << endl;
				string line;
				getline(cin,line);
                string delim = " ";
                string symbol;

            int numShare;
            double price;
            for (int i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    symbol = line.substr(0,line.find(delim));
                }
                else if (i == 1)
                {
                    stringstream sstream;
                    sstream << line.substr(0,line.find(delim));
                    //numShare = sstream.str();
                }
                else if (i == 2)
                {

                    //price = stod(line);
                }
                line = line.substr(line.find(delim)+1, string::npos);
            }

            buyStock(account, symbol, numShare, price);
            break;
            }
            case 3: {
                cout << "\n\tEnter selling options" << endl;
                string line;
                getline(cin,line);
                string delim = " ";
                string symbol;

                int numShare;
                double price;
                for (int i = 0; i < 3; i++)
                {
                    if (i == 0)
                    {
                        symbol = line.substr(0,line.find(delim));
                    }
                    else if (i == 1)
                    {
                        //numShare = stoi(line.substr(0,line.find(delim)));
                    }
                    else if (i == 2)
                    {
                        //price = stod(line);
                    }
                    line = line.substr(line.find(delim)+1, string::npos);
                }
                sellStock(account, symbol, numShare, price);
                break;
        }
            case 4:
                displayPortfolio(account);
                break;
            case 5:
                displayTransactions(account);
                break;
            case 6:
                flag = false;
                break;
            default:
                break;
		}
	}
}
//____________________________________________________FUNCTION DEFINITIONS___________________________________________
void StockAccount::stockPrice(string symbol) {
        //the following code gets a random text file
            int num = rand()%4 + 1;
            stringstream ss;
            ss << num;
            string name = "stock" + ss.str() + ".txt";
            ifstream file;
            file.open(name);

            //ifstream file("example1.txt");
            string lineS;
            while (getline(file,lineS))
            {
            if (lineS.find(symbol) != string::npos)
                {
                cout << lineS << endl;
                }
            }
}

void StockAccount::buyStock(Account& account,string symbol, int numShare, double price)
{
    Portfolio port;
    port.amount = numShare;
    port.price = price;
    port.symbol = symbol;
    port.total = price * numShare;

    srand(time(NULL));
        int num = rand()%4 + 1;
        stringstream ss;
        ss << num;
        string name = "stock" + ss.str() + ".txt";
        ifstream file;
        file.open(name);

    string line;
    while (getline(file, line))
    {
        string delim = "\t";
        vector <string> tokens;
        string stockInfo;
        stockInfo = line;
        string substring;
        substring = line.substr(0,line.find(delim));
//        double stockPrice = stod(line.substr(line.rfind(delim)+1,string::npos));

            if(substring.compare(symbol) == 0)
            {
                cout << stockInfo << endl;
                if(price >= stockPrice)
            {
                line = line.substr(line.find(delim)+1,string::npos);
                string company = line.substr(0,line.find(delim));
                port.company = company;
                account.portfolioList.push_back(port);
                account.m_cashBalance -= numShare * price;

    //            string line = "Buy\t" + symbol + "\t" + to_string(numShare) + "\t" + to_string(price) + "\n";

                ofstream myfile;
                myfile.open("stock_transaction_history.txt", ios_base::app);
                myfile << line;
                myfile.close();
            }
            else
            {
            cout << "\nTransaction could not be completed." << endl;
            }
            break;
        }
    }
    file.close();
}

void StockAccount::sellStock(Account& account,string symbol, int numShare, double price)
{
    Portfolio port;
    port.amount = numShare;
    port.price = price;
    port.symbol = symbol;
    port.total = price * numShare;

    vector<Portfolio> portList = account.portfolioList;
    for(int j = 0; j < portList.size(); j++)
    {
        if(portList[j].symbol.compare(symbol) == 0)
        {
            if(portList[j].amount >= numShare)
            {
            srand(time(NULL));
            int num = rand()%4 + 1;
          //  string name = "stock" + to_string(num) + ".txt";
            ifstream file;
            file.open(name);

            string line;
            while (getline(file, line))
            {
            string delim = "\t";
            vector <string> tokens;
            string stockInfo;
            stockInfo = line;
            string substring;
            substring = line.substr(0,line.find(delim));
       //     double stockPrice = stod(line.substr(line.rfind(delim)+1,string::npos));

            if(substring.compare(symbol) == 0)
                {
                cout << stockInfo << endl;
                if(price <= stockPrice)
                {
                if(portList[j].amount > numShare)
                {
                account.m_cashBalance += numShare * price;
                portList[j].amount = portList[j].amount - numShare;
                portList[j].total = portList[j].amount * portList[j].price;
                account.portfolioList[j] = portList[j];

                string line = "Sell\t" + symbol + "\t" + to_string(numShare) + "\t" + to_string(price) + "\n";

                ofstream myfile;
                myfile.open("stock_transaction_history.txt", ios_base::app);
                myfile << line;
                myfile.close();
                }
                else if(portList[j].amount = numShare){
                    account.m_cashBalance += numShare * price;

                    portList.erase(portList.begin()+ j);
                    account.portfolioList = portList;

                string line = "Sell\t" + symbol + "\t" + to_string(numShare) + "\t" + to_string(price) + "\n";

                ofstream myfile;
                myfile.open("stock_transaction_history.txt", ios_base::app);
                myfile << line;
                myfile.close();
                }
        }
            else
            {
            cout << "\nTransaction could not be completed" << endl;
            }
            break;
        }
    }
    file.close();
            }
        }
    }
}

void StockAccount::displayPortfolio(Account& account)
{
    vector<Portfolio> port = account.portfolioList;
    cout << "\tCash Balance " << account.m_cashBalance << endl;
    double totalbal;
    for (int i = 0; i < port.size(); i++)
    {
        cout << "\tSYMBOL = " << port[i].symbol << "\tSHARE = " << port[i].amount << "\tPRICE = "
             << port[i].price << "\tCOMPANY = "  << port[i].company << "\tTOTAL = "  << port[i].total<< endl;
        totalbal += port[i].total;
    }
    cout << "\tTotal Portfolio Value " << account.m_cashBalance + totalbal << endl;
}

void StockAccount::displayTransactions(Account& account)
{
ifstream file("stock_transaction_history.txt");
string line;
cout << "Action\tSymbol\tShare\tPrice\t" << endl;
while (getline(file, line))
file.close();
}
