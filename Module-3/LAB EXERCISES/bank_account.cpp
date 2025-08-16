#include<iostream>
using namespace std;

class BankAccount
{
private:
    float balance;

public:
    void setBalance(float b)
    {
        balance = b;
    }

    void deposit(float amount)
    {
        balance = balance + amount;
    }

    void withdraw(float amount)
    {
        if(amount <= balance)
            balance = balance - amount;
        else
            cout<<"Insufficient balance"<<endl;
    }

    void showBalance()
    {
        cout<<"Balance = "<<balance<<endl;
    }
};

int main()
{
    BankAccount acc;
    acc.setBalance(1000);

    cout<<"After depositing 500:"<<endl;
    acc.deposit(500);
    acc.showBalance();

    cout<<"After withdrawing 300:"<<endl;
    acc.withdraw(300);
    acc.showBalance();

    cout<<"Trying to withdraw 1500:"<<endl;
    acc.withdraw(1500);
    acc.showBalance();

    return 0;
}
