#include<iostream>
using namespace std;

int main()
{
    int number = 45;
    int guess;

    while(true)
    {
        cout<<"Guess a number between 1 and 100: ";
        cin>>guess;

        if(guess == number)
        {
            cout<<"Correct! You guessed it.";
            break;
        }
        else if(guess > number)
        {
            cout<<"Too high, try again."<<endl;
        }
        else
        {
            cout<<"Too low, try again."<<endl;
        }
    }

    return 0;
}
