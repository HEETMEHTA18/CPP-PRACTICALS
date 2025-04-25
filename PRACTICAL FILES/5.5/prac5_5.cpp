#include <iostream>
#include <vector>
#include <memory>
using namespace std;
// This program demonstrates the use of polymorphism in C++ by defining a base class Shape
class Shape {
public:
    virtual double Area() const = 0;
    virtual ~Shape() {}
};

class Rectangle : public Shape {
    double length, width;
public:
    Rectangle(double l, double w) : length(l), width(w) {}
    double Area() const  { return length * width; }
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double Area() const  { return 3.14 * radius * radius; }
};

int main() {
    vector<unique_ptr<Shape>> shapes;
    shapes.emplace_back(make_unique<Rectangle>(3.0, 4.0));
    shapes.emplace_back(make_unique<Circle>(2.5));
    for (const auto &s : shapes)
        cout << "Area: " << s->Area() << endl;
    return 0;
}