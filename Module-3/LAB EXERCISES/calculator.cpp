#include<iostream>
using namespace std;

int add(int a, int b)
{
    return a+b;
}

int sub(int a, int b)
{
    return a-b;
}

int mul(int a, int b)
{
    return a*b;
}

float divide(int a, int b)
{
    return (float)a/b;
}

int main()
{
    int a, b, choice;
    cout<<"Enter two numbers: ";
    cin>>a>>b;

    cout<<"1.Add  2.Subtract  3.Multiply  4.Divide"<<endl;
    cout<<"Enter choice: ";
    cin>>choice;

    if(choice==1)
        cout<<"Result = "<<add(a,b);
    else if(choice==2)
        cout<<"Result = "<<sub(a,b);
    else if(choice==3)
        cout<<"Result = "<<mul(a,b);
    else if(choice==4)
        cout<<"Result = "<<divide(a,b);
    else
        cout<<"Invalid choice";

    return 0;
}
