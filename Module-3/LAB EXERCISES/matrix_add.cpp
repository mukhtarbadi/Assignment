#include<iostream>
using namespace std;

int main()
{
    int a[2][2], b[2][2], c[2][2];

    cout<<"Enter 4 elements of first matrix: ";
    cin>>a[0][0]>>a[0][1]>>a[1][0]>>a[1][1];

    cout<<"Enter 4 elements of second matrix: ";
    cin>>b[0][0]>>b[0][1]>>b[1][0]>>b[1][1];

    c[0][0] = a[0][0] + b[0][0];
    c[0][1] = a[0][1] + b[0][1];
    c[1][0] = a[1][0] + b[1][0];
    c[1][1] = a[1][1] + b[1][1];

    cout<<"Resultant Matrix:"<<endl;
    cout<<c[0][0]<<" "<<c[0][1]<<endl;
    cout<<c[1][0]<<" "<<c[1][1]<<endl;

    return 0;
}
