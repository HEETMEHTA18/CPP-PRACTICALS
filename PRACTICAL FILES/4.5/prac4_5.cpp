/*In an educational setting, an advanced grading system was conceptualized to accommodate the
diverse evaluation criteria for students at different academic levels. At the heart of the system is an
abstract base class that defines the grading framework. This class includes a protected member to
store marks and declares a pure virtual function for computing grades, ensuring that specific grading
logic is implemented by derived classes.
Two distinct derived classes were introduced to handle the unique grading needs of undergraduate
and postgraduate students. Each class defines its own implementation of the grade computation
method, reflecting the varying academic expectations for these groups. The system enables users to
input student data, compute grades based on the respective criteria, and manage a collection of
student records.*/

#include<iostream>
#include<string>
using namespace std;


class computegrades
{

    virtual void computegrade() = 0;

};
class undergraduate : public computegrades
{
    private:
    string name;
    int rollno;
    int marks[5];
    public:
    void getdata()
    {
        cout << "Enter name of student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks in 5 subjects: ";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }
    void computegrade()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        float avg = sum / 5.0;
        cout << "Average marks of undergraduate student " << name << " is: " << avg << endl;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};
class Postgraduate : public computegrades
{
    private:
    string name;
    int rollno;
    int marks[5];
    public:
    void getdata()
    {
        cout << "Enter name of student: ";
        cin >> name;
        cout << "Enter roll number: ";
        cin >> rollno;
        cout << "Enter marks in 5 subjects: ";
        for (int i = 0; i < 5; i++)
            cin >> marks[i];
    }
    void computegrade()
    {
        int sum = 0;
        for (int i = 0; i < 5; i++)
            sum += marks[i];
        float avg = sum / 5.0;
        cout << "Average marks of postgraduate student " << name << " is: " << avg << endl;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollno << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++)
            cout << marks[i] << " ";
        cout << endl;
    }
};
int main()
{
    undergraduate u;
    Postgraduate p;
    u.getdata();
    u.computegrade();
    u.display();
    p.getdata();
    p.computegrade();
    p.display();
    return 0;
}