#include<iostream>
using namespace std;

class Calculator
{
public:
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
    float divi(int a, int b)
    {
        return (float)a/b;
    }
};

int main()
{
    Calculator c;
    int a, b, ch;
    cout<<"Enter two numbers: ";
    cin>>a>>b;

    cout<<"1.Add  2.Subtract  3.Multiply  4.Divide"<<endl;
    cout<<"Enter choice: ";
    cin>>ch;

    if(ch==1)
        cout<<"Result = "<<c.add(a,b);
    else if(ch==2)
        cout<<"Result = "<<c.sub(a,b);
    else if(ch==3)
        cout<<"Result = "<<c.mul(a,b);
    else if(ch==4)
        cout<<"Result = "<<c.divi(a,b);
    else
        cout<<"Invalid choice";

    return 0;
}
