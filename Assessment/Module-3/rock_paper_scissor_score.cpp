#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Game
{
public:
    void play()
    {
        string name;
        int rounds;
        cout<<"Enter your name: ";
        cin>>name;
        cout<<"How many rounds do you want to play? ";
        cin>>rounds;

        int userScore=0, compScore=0;
        int userChoice, compChoice;

        srand(time(0));

        for(int i=1; i<=rounds; i++)
        {
            cout<<"\nRound "<<i<<endl;
            cout<<"1. Rock  2. Paper  3. Scissor\n";
            cout<<"Enter your choice: ";
            cin>>userChoice;

            compChoice = (rand()%3)+1;

            cout<<"Computer chose: ";
            if(compChoice==1) cout<<"Rock"<<endl;
            else if(compChoice==2) cout<<"Paper"<<endl;
            else cout<<"Scissor"<<endl;

            cout<<"You chose: ";
            if(userChoice==1) cout<<"Rock"<<endl;
            else if(userChoice==2) cout<<"Paper"<<endl;
            else if(userChoice==3) cout<<"Scissor"<<endl;

            if(userChoice == compChoice)
                cout<<"It's a Tie!"<<endl;
            else if((userChoice==1 && compChoice==3) ||
                    (userChoice==2 && compChoice==1) ||
                    (userChoice==3 && compChoice==2))
            {
                cout<<name<<" Wins this round!"<<endl;
                userScore++;
            }
            else
            {
                cout<<"Computer Wins this round!"<<endl;
                compScore++;
            }
        }

        cout<<"\n--- Game Over ---\n";
        cout<<name<<"'s Score: "<<userScore<<endl;
        cout<<"Computer's Score: "<<compScore<<endl;

        if(userScore > compScore)
            cout<<name<<" Wins the Game!"<<endl;
        else if(userScore < compScore)
            cout<<"Computer Wins the Game!"<<endl;
        else
            cout<<"The Game is a Tie!"<<endl;
    }
};

int main()
{
    Game g;
    g.play();
    return 0;
}
