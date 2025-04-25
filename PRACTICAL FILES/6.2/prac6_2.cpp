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
    Point(int xx, int yy) : x(xx), y(yy) {}
    Point& shift(int dx, int dy) {
        x += dx; y += dy;
        return *this;
    }
    void print() const { std::cout << "(" << x << "," << y << ")\n"; }
};

int main() {
    Point p(0,0);
    p.shift(2,3).shift(-1,4);
    p.print();
    return 0;
}
