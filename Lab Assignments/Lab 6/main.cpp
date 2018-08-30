/*  Jonathan Tsai
    3/2/17
    Section 01
    Lab 6: Polling */


#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main ()
{
    string issues[]{"Education Reform ", "Wealth Inequality", "Social Inequality", "Public Health    ", "Renewable Energy "}; //this string array stores the issues
    int ans[5][10]; //this 2-dimensional array summarizes the survey responses
    char c = 'y'; //used for asking if the user wants to input another response

    //the following code initializes every element to zero
    for (int i=0;i<5;i++)
    {
        for (int j=0;j<10;j++)
        {
            ans[i][j]=0;
        }
    }

    while (c!='n') //if 'n', exit the while loop
    {
        system("cls"); //clear screen
        cout << "Please rate on a scale of 1-10 how you would rate these issues in importance.." << endl << endl;
        system("pause");
        int rating;
        char input[20]; //array used to store responses

        for (int i=0;i<5;i++)
            {   system("cls");
                cout << issues[i]<<": ";
                cin >> input;

                rating = atoi(input); //converts input to integer
                while (rating>10||rating<1)
                {cout << "Please enter a number between 1-10" << endl;
                cin >> rating;}

                ans[i][rating-1]++; //record result by incrementing
            }

                //the following is to display the tabular report
                system("cls");
                int responses = 0; //responses represents the number of users surveyed
                int sum = 0;
                int avg = 0;
                cout << "Ratings           1  2  3  4  5  6  7  8  9  10 responses" << endl;
                for (int i=0;i<5;i++)
                    {
                cout << issues[i];
                        for (int j=0;j<10;j++)
                        {
                            responses += ans[i][j];
                            cout << " " << ans[i][j] << " ";
                        }

                    cout << " " << responses << endl;
                    responses = 0;
                    }

cout<<"\n\nWould you like to go again? y/n: ";
cin>>c;

}

system("pause");
return 0;

}

/*
5 x 10 int array, each cell of that array shows the number of people who rate that specific column
in rating x,y you store a value of 5: meaning 5 people rated y for the issue x

In the end, you need to print a table (for example, using spaces or tabs) where each row corresponds with an issue,
and each value shows the number of people for each rating
*/
