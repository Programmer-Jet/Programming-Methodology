/*
    Jonathan Tsai
    2/23/17
    Section 01
    Lab 5: Towers of Hanoi
*/

#include <iostream>
#include "towers_header.h"

using namespace std;

int main()
{
    int n;
    cout << "Input the number of disks: " << endl;
    cin >> n;

    cout << "The instructions for moving the disks from the starting peg to the destination peg are: " << endl;
    f(n, 1, 3, 2);
    return 0;
}
