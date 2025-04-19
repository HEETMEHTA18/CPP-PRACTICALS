#include<iostream>
#include<stack>
using namespace std;

class Cordinate {
private:
    int Cord_x, Cord_y;
public:
    // Constructor to initialize coordinates
    Cordinate(int x = 0, int y = 0) : Cord_x(x), Cord_y(y) {}

    // Show coordinates
    void show() const {
        cout << "X coordinate: " << Cord_x << ", Y coordinate: " << Cord_y << endl;
    }

    // Operator overloading for + operator
    Cordinate operator+ (const Cordinate& obj) {
        return Cordinate(this->Cord_x + obj.Cord_x, this->Cord_y + obj.Cord_y);
    }

    // Operator overloading for unary - operator
    Cordinate operator- () {
        return Cordinate(-Cord_x, -Cord_y);
    }

    // Operator overloading for == operator
    bool operator== (const Cordinate& obj) {
        return (this->Cord_x == obj.Cord_x && this->Cord_y == obj.Cord_y);
    }
};

int main() {
    // Stack of Cordinate objects
    stack<Cordinate> cordStack;

    // Creating some coordinates
    Cordinate C1(2, 3), C2(2, 3), C3(4, 5), C4, C5;

    // Push coordinates to the stack
    cordStack.push(C1);
    cordStack.push(C2);
    cordStack.push(C3);

    cout << "Top of the stack (most recent Cordinate pushed):" << endl;
    cordStack.top().show();

    // Pop top and show new top
    cordStack.pop();
    cout << "\nAfter popping one Cordinate, top is now:" << endl;
    cordStack.top().show();

    // Demonstrate operator overloading
    C4 = C1 + C2;
    cout << "\nSum of C1 and C2:" << endl;
    C4.show();

    C5 = -C1;
    cout << "\nNegation of C1:" << endl;
    C5.show();

    // Equality checks
    cout << "\nChecking Equality:" << endl;
    if (C1 == C2) {
        cout << "C1 and C2 are equal" << endl;
    } else {
        cout << "C1 and C2 are not equal" << endl;
    }

    if (C1 == C3) {
        cout << "C1 and C3 are equal" << endl;
    } else {
        cout << "C1 and C3 are not equal" << endl;
    }

    return 0;
}
