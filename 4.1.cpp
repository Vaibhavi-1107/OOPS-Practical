/*A team of engineers was tasked with developing a program to calculate and manage the areas of
multiple circles for a design project. To achieve this, they devised a solution using a structured, objectoriented approach. At the foundation of their solution was a base class that represented a generic
shape, responsible for storing and managing the radius of the circle. Building upon this, a specialized
class for circles was created to extend functionality by introducing a method for calculating the area
of a circle based on its radius. Using this framework, the team designed a system to handle multiple
circles, ensuring that the process of storing, calculating, and displaying the areas was efficient and
adaptable. They explored two different approaches for managing the collection of circles—one
focusing on flexibility and dynamic handling, while the other used a more static structure. By
implementing and comparing these methods, the engineers gained insights into the benefits of using
efficient techniques for organizing and processing geometric data, enhancing their problem-solving
capabilities.*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// Base class
class Shape {
protected:
    double radius;
public:
    Shape(double r = 0.0) : radius(r) {}
    void setRadius(double r) {
        radius = r;
    }
    double getRadius() const {
        return radius;
    }
};

// Derived class
class Circle : public Shape {
public:
    Circle(double r = 0.0) : Shape(r) {}

    double calculateArea() const {
        return M_PI * radius * radius;
    }

    void display() const {
        cout << "Radius: " << radius << ", Area: " << calculateArea() << endl;
    }
};

// Approach 1: Static collection (fixed size)
void staticApproach() {
    cout << "\n[Static Approach]\n";
    const int SIZE = 3;
    Circle circles[SIZE] = { Circle(2.0), Circle(3.5), Circle(4.1) };

    for (int i = 0; i < SIZE; ++i) {
        cout << "Circle " << i + 1 << ": ";
        circles[i].display();
    }
}

// Approach 2: Dynamic collection using vector
void dynamicApproach() {
    cout << "\n[Dynamic Approach]\n";
    vector<Circle> circles;
    circles.push_back(Circle(1.2));
    circles.push_back(Circle(5.8));
    circles.push_back(Circle(2.7));

    for (size_t i = 0; i < circles.size(); ++i) {
        cout << "Circle " << i + 1 << ": ";
        circles[i].display();
    }
}

int main() {
    staticApproach();
    dynamicApproach();
    cout<<"Vaibhavi 24CE053";
    return 0;
}

