/*
Jonathan Tsai
March 3, 2017
Lecture Example 1: pointer as array
Example 2: sorting: take the pointer-based array from example 1, and sort all the elements in the array.
Please note you need to implement the following sort function:
void sort(int *arrayAddr, int arraySize);
Example 3: Take the sorted array in example 2. Please search whether the number 34 is in the array. You need to
implement the following search function:
void search (int *arrayAddr, int arraySize, int number);
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
   int *pa = new int[20];

    srand(static_cast <unsigned int> (time(0))); //Generates a random number

    for (int i = 0; i < 20; i++)
    {
    int number = rand() % 100 + 1; //Range from 1 to 100
    pa[i] = number;
    cout << pa[i] << " ";
    }

    delete pa;

    return 0;
}
