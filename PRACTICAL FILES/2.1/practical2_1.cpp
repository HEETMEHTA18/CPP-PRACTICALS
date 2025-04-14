/*A local construction company frequently deals with rectangular plots and structures of varying
dimensions. To streamline their planning and estimation processes, the company requires a simple
system to manage and analyze rectangular shapes efficiently.
The system must be able to handle multiple rectangles, each with distinct dimensions. For each
rectangle, the length and width need to be defined and stored securely. Additionally, the company
needs the ability to calculate two key metrics for any given rectangle:
The area, to estimate usable space or material coverage. The perimeter, to estimate boundary lengths
or material requirements for edges. To make this system functional, there should be a way to define
or update the dimensions of any rectangle as required. The system should be capable of creating and
managing multiple rectangle records, performing calculations for each, and displaying the results
clearly for analysis and planning purposes.*/
#include <iostream>
using namespace std;

class Rectangle {
    double length, width;
public:
    Rectangle(double l = 0, double w = 0): length(l), width(w) {}
    double area() { return length * width; }
    double perimeter() { return 2 * (length + width); }
    void display() {
        cout << "Length: " << length << ", Width: " << width
             << ", Area: " << area() << ", Perimeter: " << perimeter() << endl;
    }
};

int main(){
    Rectangle r1(5, 3), r2(10, 4);
    r1.display();
    r2.display();
    return 0;
}
