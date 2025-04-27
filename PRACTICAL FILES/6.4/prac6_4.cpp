#include <iostream>

class Base {
public:
    virtual ~Base() { std::cout << "Base destroyed\n"; }
};

class Derived : public Base {
    int *arr;
public:
    Derived() { arr = new int[5]; }
    ~Derived() { delete[] arr; std::cout << "Derived destroyed\n"; }
};

int main() {
    Base *p = new Derived();
    delete p;
    return 0;
}
