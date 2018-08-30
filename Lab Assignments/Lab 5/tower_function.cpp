#include "towers_header.h"
#include <iostream>

void f(int n, int frompeg, int topeg, int temppeg)
{
    if (n == 1)
    {
    cout << "Move disk 1 from peg " << frompeg << " to peg " << topeg << endl;
    return;
    }

    f(n-1, frompeg, temppeg, topeg);
    cout << "Move disk " << n << " from peg " << frompeg << " to peg " << topeg << endl;
    f(n-1, temppeg, topeg, frompeg);
}
