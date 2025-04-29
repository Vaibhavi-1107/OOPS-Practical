/*A team of developers is tasked with building a temperature conversion system for a weather
application. To achieve this, the team creates two classes: Celsius and Fahrenheit. These classes
handle the conversion between temperature units, with the ability to convert from Celsius to
Fahrenheit and vice versa using type conversion. The team utilizes operator overloading to define the
conversion operators for both classes, enabling seamless conversions between the two units.
The system also requires the ability to compare two temperature objects to check if they are equal.
This is achieved by overloading the equality operator ==, which compares the values of the
temperatures in their respective units.
To ensure smooth processing of temperature conversions, the team needs to manage and store
multiple converted temperature objects. Two approaches are considered for handling this task. The
first approach involves using a dynamic data structure, a queue, to process the conversions in a firstin-first-out (FIFO) manner. Alternatively, a basic array is used to store the converted objects in a static
manner.*/
#include<iostream>
#include<queue>
using namespace std;
class Fahrenheit;  //Forward declaration

class Celsius
{
public:
    float celsius;

    Celsius(float c = 0) : celsius(c) {}

    // Convert Celsius to Fahrenheit
    operator Fahrenheit();

    // Equality comparison
    bool operator==(const Celsius& other) const {
        return celsius == other.celsius;
    }

    void display() const {
        cout << celsius << "C";
    }
};

class Fahrenheit {
public:
    float fahrenheit;

    Fahrenheit(float f = 0) : fahrenheit(f) {}

    // Convert Fahrenheit to Celsius
    operator Celsius() {
        return Celsius((fahrenheit - 32) * 5.0 / 9.0);
    }

    // Equality comparison
    bool operator==(const Fahrenheit& other) const {
        return fahrenheit == other.fahrenheit;
    }

    void display() const {
        cout << fahrenheit << "F";
    }
};

// Define Celsius to Fahrenheit conversion
Celsius::operator Fahrenheit() {
    return Fahrenheit((celsius * 9.0 / 5) + 32);
}

int main() {
    // Create sample temperature values
    Celsius c1(25), c2(30);
    Fahrenheit f1(77), f2(86);

    // Convert using overloaded type casting
    Fahrenheit fConverted = c1;  // Celsius to Fahrenheit
    Celsius cConverted = f1;     // Fahrenheit to Celsius

    cout << "Celsius to Fahrenheit: ";
    c1.display(); cout << " = ";
    fConverted.display(); cout << endl;

    cout << "Fahrenheit to Celsius: ";
    f1.display(); cout << " = ";
    cConverted.display(); cout << endl;

    // --- Using Queue (FIFO) ---
    queue<Celsius> celsiusQueue;
    queue<Fahrenheit> fahrenheitQueue;

    celsiusQueue.push(c1);
    celsiusQueue.push(Celsius(f1)); // Push converted value
    fahrenheitQueue.push(fConverted);
    fahrenheitQueue.push(f2);

    cout << "\n--- Processing Queue ---\n";
    while (!celsiusQueue.empty()) {
        Celsius temp = celsiusQueue.front();
        temp.display(); cout << " ";
        celsiusQueue.pop();
    }

    cout << endl;
    while (!fahrenheitQueue.empty()) {
        Fahrenheit temp = fahrenheitQueue.front();
        temp.display(); cout << " ";
        fahrenheitQueue.pop();
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}







