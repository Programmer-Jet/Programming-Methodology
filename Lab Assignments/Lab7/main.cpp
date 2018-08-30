/*  Jonathan Tsai
    3/9/17
    Section 01
    Lab 7: Salary Classification */

#include <iostream>

using namespace std;

//We are using data type int because the lab asks us to assume integer amount

int main()
{
    int sales = 0;
    int salary = 0;
    /* We want to output a table of the number of employees that fall under each of the 9 salary ranges. We are asked to use
    an array of counters, and so we need to create an array that can hold 9 integers. */
    int ranges[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    string values[9] = {"$200 to 299", "$300 to 399", "$400 to 499", "$500 to 599", "$600 to 699", "$700 to 799",
    "$800 to 899", "$900 to 999", "$1000 or more"};

    while(sales != -1){

    cout << "Please enter an employee's weekly sales (input -1 when you are done): " << endl;
    cin >> sales;

    salary = 200 + 0.09 * sales;

        if (salary >= 200 && salary <= 299)
            ranges[0]++;

        else if (salary >= 300 && salary <= 399)
            ranges[1]++;

        else if (salary >= 400 && salary <= 499)
            ranges[2]++;

        else if (salary >= 500 && salary <= 599)
            ranges[3]++;

        else if (salary >= 600 && salary <= 699)
            ranges[4]++;

        else if (salary >= 700 && salary <= 799)
            ranges[5]++;

        else if (salary >= 800 && salary <= 899)
            ranges[6]++;

        else if (salary >= 900 && salary <= 999)
            ranges[7]++;

        else if (salary >= 1000)
            ranges[8]++;
    }

    cout << "Employees in salary ranges: " << endl;

    for (int i = 0; i < 9; i++)
        cout << values[i] << "            " << ranges[i] << endl;

    return 0;

}
