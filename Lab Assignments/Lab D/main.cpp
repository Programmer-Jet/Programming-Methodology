
/*  Jonathan Tsai
    2/16/17
    Section 01
    Lab D: Guess-The-Number-Game */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL)); //Generates a random number
    int number = rand() % 1000 + 1; //Range from 1 to 1000

    cout << "I have a number between 1 and 1000." << endl << "Can you guess my number?" << endl << "Please type your first guess." << endl;
    int guess;
    do {
    cin >> guess;
    if (!cin) //If an error occurs then an error flag is set which will prevent future inputs
    {
        cout << "Please enter a number!" << endl;
        cin.clear(); //Clears the error flag
        cin.ignore(10000,'\n'); //Takes out 10000 characters from the buffer but stops if it encounters a newline
        cin >> guess;
    }

    if (guess < number)
        cout << "Too low. Try again." << endl;
    else if (guess > number)
        cout << "Too high. Guess again." << endl;
    else if (guess == number)
        cout << "Excellent! You guessed the number! Would you like to play again (y or n) ?" << endl;
    } while(guess != number);

    char repeat;
    cin >> repeat;

    if (repeat == 'y') {
        main();
    }

    return 0;
}
