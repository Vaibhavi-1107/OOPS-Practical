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
objects are updated through pass-by-reference using pointers. */
#include <iostream>
using namespace std;
class Point {
private:
    float x, y;

public:
    // Constructor
    Point(float x = 0.0, float y = 0.0) : x(x), y(y) {}

    // Method to shift the point
    Point* move(float dx, float dy) {
        x += dx;
        y += dy;
        return this; // Enables method chaining
    }

    // Display current coordinates
    void print() const {
        cout << "Point(x: " << x << ", y: " << y << ")\n";
    }
};

int main() {
    // Create point dynamically
    Point* p = new Point(10.0, 20.0);

    // Chain movements
    p->move(5.0, -3.0)->move(-2.0, 4.0)->print();

    // Clean up
    delete p;
    cout<<"Vaibhavi 24CE053";
    return 0;
}
