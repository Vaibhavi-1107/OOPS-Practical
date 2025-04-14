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
#include <vector>
using namespace std;

// Rectangle class definition
class Rectangle {
private:
    double length;
    double width;

public:
    // Constructor
    Rectangle(double l = 0.0, double w = 0.0) {
        length = l;
        width = w;
    }

    // Setters
    void setDimensions(double l, double w) {
        length = l;
        width = w;
    }

    // Getters
    double getLength() const { return length; }
    double getWidth() const { return width; }

    // Calculate area
    double getArea() const {
        return length * width;
    }

    // Calculate perimeter
    double getPerimeter() const {
        return 2 * (length + width);
    }

    // Display rectangle details
    void display() const {
        cout << "Length: " << length << ", Width: " << width << endl;
        cout << "Area: " << getArea() << ", Perimeter: " << getPerimeter() << endl;
    }
};

// Main function
int main() {
    vector<Rectangle> rectangles;
    int choice;

    do {
        cout << "\n--- Rectangle Management System ---\n";
        cout << "1. Add New Rectangle\n";
        cout << "2. Update Rectangle Dimensions\n";
        cout << "3. Display All Rectangles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                double length, width;
                cout << "Enter length: ";
                cin >> length;
                cout << "Enter width: ";
                cin >> width;
                rectangles.emplace_back(length, width);
                cout << "Rectangle added successfully!\n";
                break;
            }
            case 2: {
                int index;
                double length, width;
                cout << "Enter rectangle index to update (0 to " << rectangles.size()-1 << "): ";
                cin >> index;
                if(index >= 0 && index < rectangles.size()) {
                    cout << "Enter new length: ";
                    cin >> length;
                    cout << "Enter new width: ";
                    cin >> width;
                    rectangles[index].setDimensions(length, width);
                    cout << "Rectangle updated successfully!\n";
                } else {
                    cout << "Invalid index.\n";
                }
                break;
            }
            case 3: {
                for(size_t i = 0; i < rectangles.size(); ++i) {
                    cout << "\nRectangle " << i << ":\n";
                    rectangles[i].display();
                }
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while(choice != 4);
    cout<<"Vaibhavi 24CE053";

    return 0;
}
