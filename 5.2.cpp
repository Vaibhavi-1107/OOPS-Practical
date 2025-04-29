/*A mathematical research group aimed to create a software model for handling and performing
operations on complex numbers efficiently. To achieve this, they designed a Complex class that
encapsulates the real and imaginary parts of a complex number. The class supports essential operator
overloading to enhance usability, including the addition and subtraction of complex numbers and
custom input and output functionality through the << and >> operators. These overloaded operators
ensure seamless arithmetic and user interaction with the system.
The task involves implementing this system and exploring its capabilities by performing various
operations on complex numbers. Participants are expected to overload the specified operators and
use them to add and subtract complex numbers, as well as to facilitate user-friendly input and output.
Additionally, the solution encourages experimenting with managing collections of complex numbers
to perform batch operations.*/
#include<iostream>
#include <vector>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Default constructor
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // Overload + operator
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Overload - operator
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Overload >> operator for input
    friend istream& operator>>(istream& in, Complex& c) {
        cout << "Enter real part: ";
        in >> c.real;
        cout << "Enter imaginary part: ";
        in >> c.imag;
        return in;
    }

    // Overload << operator for output
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;
        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1, c2;

    // Input complex numbers
    cout << "Input first complex number:\n";
    cin >> c1;

    cout << "Input second complex number:\n";
    cin >> c2;

    // Perform addition and subtraction
    Complex sum = c1 + c2;
    Complex diff = c1 - c2;

    // Output results
    cout << "\nFirst Complex Number: " << c1 << endl;
    cout << "Second Complex Number: " << c2 << endl;
    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    // Batch operation with collection of complex numbers
    vector<Complex> complexList = {c1, c2, sum, diff};

    cout << "\nBatch Output of Complex Numbers:\n";
    for (const auto& c : complexList) {
        cout << c << endl;
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}
