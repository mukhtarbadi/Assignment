#include<iostream>
using namespace std;

class Person
{
public:
    string name;
    int age;

    void setPerson(string n, int a)
    {
        name = n;
        age = a;
    }

    void showPerson()
    {
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

class Student : public Person
{
public:
    int marks;

    void setStudent(string n, int a, int m)
    {
        setPerson(n, a);
        marks = m;
    }

    void showStudent()
    {
        showPerson();
        cout<<"Marks: "<<marks<<endl;
    }
};

class Teacher : public Person
{
public:
    string subject;

    void setTeacher(string n, int a, string s)
    {
        setPerson(n, a);
        subject = s;
    }

    void showTeacher()
    {
        showPerson();
        cout<<"Subject: "<<subject<<endl;
    }
};

int main()
{
    Student s;
    s.setStudent("Mukhtar", 21, 90);
    cout<<"Student Details:"<<endl;
    s.showStudent();

    cout<<endl;

    Teacher t;
    t.setTeacher("Mr. Badi", 40, "Math");
    cout<<"Teacher Details:"<<endl;
    t.showTeacher();

    return 0;
}
