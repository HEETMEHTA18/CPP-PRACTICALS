#include <iostream>
using namespace std;
class Base
{
public:
    Base () { cout << "Base created\n"; }
    // Virtual destructor
    virtual ~Base()
    {
        cout << "Base destroyed\n";
    }
};

class Derived : public Base
{
    int *arr;

public:

    Derived() { 
        arr = new int[5];
        cout << "Derived created\n";
    }
    ~Derived()
    {
        delete[] arr;
        cout << "Derived destroyed\n";
    }
};

int main()
{
    Base *p = new Derived();
    delete p;
    return 0;
}
