/*In a digital mapping application, a team of developers is working on a feature that allows objects to
be repositioned dynamically on a coordinate plane. The application requires precise control over the
movement of individual points representing user-defined markers. To achieve this, the team needs to
design a system that allows a point’s coordinates to be adjusted efficiently while maintaining a fluid
and chainable update mechanism.
To ensure seamless movement, the developers must implement a structure that allows each point to
shift by specified offsets in the x and y directions. Additionally, the solution should be designed in a
way that supports method chaining, enabling multiple transformations to be applied in a single
statement. This requires careful handling of object references, utilizing this pointer to return the
updated object.
Furthermore, the implementation must be optimized for direct memory management, ensuring that
objects are updated through pass-by-reference using pointers.*/
#include <iostream>
using namespace std;

class Point {
    int x, y;
public:
    // Constructor to initialize the point
    Point(int xx, int yy) : x(xx), y(yy) {}

    // Shift method using pass-by-reference for dx and dy
    Point& shift(int &dx, int &dy) {
        x += dx; // Update x-coordinate
        y += dy; // Update y-coordinate
        return *this; // Return the current object for method chaining
    }

    // Print method to display the point
    void print() const { 
        std::cout << "(" << x << "," << y << ")\n"; 
    }
};

int main() {
    Point p(0, 0); // Create a Point object at (0, 0)

    // Shift the point using method chaining
    int dx1 = 1, dy1 = 33;
    int dx2 = 1, dy2 = -14;
    int dx3 = 1, dy3 = 0;
    // int dx4 = 0, dy4 = 1;
    p.shift(dx1, dy1).shift(dx2, dy2); // Apply shifts
    p.shift(dx1, dy1).shift(dx2, dy2).shift(dx1, dy1);
     // Apply shifts

    // Print the final coordinates
    p.print();
    return 0;
}