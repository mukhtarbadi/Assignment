#include<iostream>
using namespace std;

int x = 10;  

void show()
{
    int x = 20;   
    cout<<"Local x = "<<x<<endl;
    cout<<"Global x = "<<::x<<endl;  
}

int main()
{
    cout<<"Global x in main = "<<x<<endl;
    show();
    return 0;
}
