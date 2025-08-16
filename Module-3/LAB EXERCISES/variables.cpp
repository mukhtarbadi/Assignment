#include<iostream>
using namespace std;

int main()
{
    const float pi = 3.14;

    int age = 20;
    float marks = 85.5;
    char grade = 'A';

    cout<<"Age = "<<age<<endl;
    cout<<"Marks = "<<marks<<endl;
    cout<<"Grade = "<<grade<<endl;
    cout<<"Value of pi = "<<pi<<endl;

    age = age + 5;
    cout<<"New Age = "<<age<<endl;

    float area = pi * 2 * 2;
    cout<<"Area of circle = "<<area<<endl;

    return 0;
}
