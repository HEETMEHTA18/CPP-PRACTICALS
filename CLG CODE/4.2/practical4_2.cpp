/*A growing organization wanted to develop a system to manage its hierarchy and represent its
structure in a programmatic way. To achieve this, a multilevel approach was designed, reflecting the
natural progression of roles within the organization. At the foundation, a class was created to
represent a person, capturing the basic details such as name and age. Building on this, an intermediate
level was introduced to represent employees, adding a unique identifier for each. Finally, at the
topmost level, a class for managers was created, which included additional details such as the
department they oversee.
The system needed to handle the initialization of all these attributes through constructors at each
level, ensuring the proper propagation of information across the hierarchy. Additionally, the
functionality to display details at every level was included to provide clear insights into the
organization's structure. Two approaches were explored for managing multiple managers: one relied
on an efficient method for retrieval and organization based on employee identifiers, while the other
used a straightforward and static method for storage.*/
#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a): name(n), age(a) {}
    virtual void display() {
        cout << "Name: " << name << ", Age: " << age;
    }
};

class Employee : public Person {
protected:
    int empID;
public:
    Employee(string n, int a, int id): Person(n, a), empID(id) {}
    void display() override {
        Person::display();
        cout << ", Employee ID: " << empID;
    }
};

class Manager : public Employee {
    string department;
public:
    Manager(string n, int a, int id, string dept): Employee(n, a, id), department(dept) {}
    void display() override {
        Employee::display();
        cout << ", Department: " << department << endl;
    }
};

int main(){
    Manager m("MANAGER", 35, 1001, "Sales");
    m.display();
    return 0;
}
