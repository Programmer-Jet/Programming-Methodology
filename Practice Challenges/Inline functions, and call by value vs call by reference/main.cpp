#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>

using namespace std;

//Generate a random radius value between 10 and 20. Call an inline function float circle_area(float) to calculate the area

int main()
{
    float x = (float rand() / float RAND_MAX)*10 +10;
    cout << x << endl;
}
