#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int arr[100], sum=0;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter element "<<i+1<<": ";
        
        cin>>arr[i];
        
        sum = sum + arr[i];
    }

    float avg = (float)sum / n;

    cout<<"Sum = "<<sum<<endl;
    cout<<"Average = "<<avg<<endl;

    return 0;
}
