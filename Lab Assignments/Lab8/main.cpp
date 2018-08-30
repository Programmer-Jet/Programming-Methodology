/*  Jonathan Tsai
    3/9/17
    Section 01
    Lab 8: Salary Classification using pointers */

    //Please use pointers instead of a static array.

#include <iostream>
using namespace std;

int main()
{
    int sales = 0;
    int salary = 0;

    int myArray[9] = {0};
     string values[9] = {"$200 to 299", "$300 to 399", "$400 to 499", "$500 to 599", "$600 to 699", "$700 to 799",
    "$800 to 899", "$900 to 999", "$1000 or more"};

    //using pointer/offset with the array's name as pointer:

    while(sales != -1){

    cout << "Please enter an employee's weekly sales (input -1 when you are done): " << endl;
    cin >> sales;

    salary = 200 + 0.09 * sales;

        if (salary >= 200 && salary <= 299)
            *(myArray) += 1;

        else if (salary >= 300 && salary <= 399)
            *(myArray + 1) += 1;

        else if (salary >= 400 && salary <= 499)
            *(myArray + 2) += 1;

        else if (salary >= 500 && salary <= 599)
            *(myArray + 3) += 1;

        else if (salary >= 600 && salary <= 699)
            *(myArray + 4) += 1;

        else if (salary >= 700 && salary <= 799)
            *(myArray + 5) += 1;

        else if (salary >= 800 && salary <= 899)
            *(myArray + 6) += 1;

        else if (salary >= 900 && salary <= 999)
            *(myArray + 7) += 1;

        else if (salary >= 1000)
            *(myArray + 8) += 1;
    }

    cout << "Employees in salary ranges: " << endl;

    for (int counter = 0; counter < 9; counter++){
        cout << values[counter] << "            " << *(myArray + counter) << endl;
    }

    return 0;
}
