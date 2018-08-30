#include <iostream>

using namespace std;
/* Create a class HugeInteger that uses a 40-element array of digits to store integers as large as 40 digits each.
Overload the equality (==) operator
Overload the add (+) operator
Overload the multiply (*) operator (extra bonus)
Overload the output (<<) operator
*/

class HugeInteger
{
const int SIZE = 40;
HugeInteger[SIZE];

HugeInteger operator==
ostream& operator << (ostream& output, const HugeInteger& hi)
{

}

};
int main()
{
    HugeInteger hi1, hi2;
    if (hi1==hi2)
        cout << "Equal" << endl;
    hi1 = hi1+hi2;
    cout << hi1;

    return 0;
}
