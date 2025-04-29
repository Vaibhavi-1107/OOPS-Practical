/*A software development team aimed to design a versatile utility that could perform basic arithmetic
operations while demonstrating the concept of function overloading. This effort resulted in a classbased calculator system capable of handling various combinations of input types, such as integers and
floating-point numbers. The system includes multiple overloaded add functions, each tailored to
accept distinct input types and perform addition operations accordingly. This approach ensures the
calculator is adaptable and provides consistent functionality regardless of the input types.
The case revolves around testing and validating the versatility of this calculator. Participants are
expected to create instances of the calculator, invoke the appropriate overloaded functions for various
input scenarios, and store the resulting values for further analysis. To organize and display these
results, the system incorporates methods to sequentially process and present the outcomes. */
#include <iostream>
#include <vector>
using namespace std;

class Calculator {
public:
    // Overloaded add functions for different input types
    int add(int a, int b) {
        return a + b;
    }

    float add(float a, float b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }

    double add(int a, double b) {
        return a + b;
    }

    double add(double a, int b) {
        return a + b;
    }

    // Method to display results
    void displayResults(const vector<string>& descriptions, const vector<double>& results) {
        for (size_t i = 0; i < results.size(); ++i) {
            cout << descriptions[i] << " = " << results[i] << endl;
        }
    }
};

int main() {
    Calculator calc;
    vector<string> descriptions;
    vector<double> results;

    // Performing different add operations
    results.push_back(calc.add(10, 5));
    descriptions.push_back("add(int, int)");

    results.push_back(calc.add(3.5f, 2.5f));
    descriptions.push_back("add(float, float)");

    results.push_back(calc.add(4.2, 5.8));
    descriptions.push_back("add(double, double)");

    results.push_back(calc.add(7, 4.6));
    descriptions.push_back("add(int, double)");

    results.push_back(calc.add(3.3, 2));
    descriptions.push_back("add(double, int)");

    // Display all results
    calc.displayResults(descriptions, results);
    cout<<"Vaibhavi 24CE053";
    return 0;
}
