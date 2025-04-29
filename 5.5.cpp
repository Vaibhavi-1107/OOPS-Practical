/*A software development team is tasked with designing a system that can handle various geometric
shapes and compute their areas in a flexible way. The challenge is to create a system that can easily
extend to accommodate new types of shapes without altering the core functionality for each shape.
To accomplish this, the system is designed with a base class called Shape, which includes a virtual
function Area(). This function is meant to be overridden by each specific shape class to provide the
correct formula for calculating the area.
The derived classes, Rectangle and Circle, each implement the Area() function with their own
formulas: the Rectangle calculates the area using its length and width, while the Circle uses its radius.
This structure allows the system to treat all shapes uniformly through a common interface, enabling
easy extensibility. The goal is to use a single reference to the base class (Shape*) to calculate the area
of any shape, regardless of its type. This approach makes the system more adaptable, as new shapes
can be added later without disrupting existing code.
In managing a collection of shapes, there are two primary approaches: one method involves
dynamically managing a collection of shapes, allowing for easy addition and removal of shapes, while
the other relies on a static method that requires manually managing the size of the collection. Both
approaches aim to store and manage the shapes effectively, with one allowing automatic resizing as
needed while the other requires more manual handling.
Through this case study, the team will implement the base class Shape and the derived classes
Rectangle and Circle, each with their own Area() function. The students will gain a deeper
understanding of polymorphism, inheritance, and memory management while working with different
methods to store and manage the collection of shapes. */
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
public:
    virtual double Area() const = 0;  // Pure virtual function
    virtual void display() const = 0; // Optional: for showing shape info
    virtual ~Shape() {}
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double length, width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double Area() const override {
        return length * width;
    }

    void display() const override {
        cout << "Rectangle (" << length << " x " << width << ")";
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double Area() const override {
        return 3.14159 * radius * radius;
    }

    void display() const override {
        cout << "Circle (radius = " << radius << ")";
    }
};

int main() {
    // --- Dynamic Collection using vector ---
    vector<Shape*> shapes;

    // Add shapes dynamically
    shapes.push_back(new Rectangle(5.0, 3.0));
    shapes.push_back(new Circle(2.5));
    shapes.push_back(new Rectangle(4.0, 2.0));

    cout << "Dynamic Shape Collection:\n";
    for (Shape* shape : shapes) {
        shape->display();
        cout << " => Area: " << shape->Area() << endl;
    }

    // Clean up dynamic memory
    for (Shape* shape : shapes) {
        delete shape;
    }
    shapes.clear();

    // --- Static Collection (manual array) ---
    cout << "\nStatic Shape Collection:\n";
    const int SIZE = 2;
    Shape* staticShapes[SIZE];
    staticShapes[0] = new Circle(3.0);
    staticShapes[1] = new Rectangle(6.0, 2.5);

    for (int i = 0; i < SIZE; ++i) {
        staticShapes[i]->display();
        cout << " => Area: " << staticShapes[i]->Area() << endl;
    }

    // Clean up
    for (int i = 0; i < SIZE; ++i) {
        delete staticShapes[i];
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}
