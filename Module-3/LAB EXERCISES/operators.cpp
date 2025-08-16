#include<iostream>
using namespace std;

int main()
{
    int a = 10, b = 5;

    cout<<"Arithmetic Operators:"<<endl;
    cout<<a+b<<endl;
    cout<<a-b<<endl;
    cout<<a*b<<endl;
    cout<<a/b<<endl;
    cout<<a%b<<endl;

    cout<<"Relational Operators:"<<endl;
    cout<<(a>b)<<endl;
    cout<<(a<b)<<endl;
    cout<<(a==b)<<endl;
    cout<<(a!=b)<<endl;

    cout<<"Logical Operators:"<<endl;
    cout<<((a>0) && (b>0))<<endl;
    cout<<((a>0) || (b<0))<<endl;
    cout<<!(a>b)<<endl;

    cout<<"Bitwise Operators:"<<endl;
    cout<<(a & b)<<endl;
    cout<<(a | b)<<endl;
    cout<<(a ^ b)<<endl;
    cout<<(a << 1)<<endl;
    cout<<(a >> 1)<<endl;

    return 0;
}
