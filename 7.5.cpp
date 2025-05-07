/*A university administration is developing a system to display student marks in a structured and visually
appealing format. The goal is to ensure clarity in academic reports by properly aligning names and
scores while also demonstrating the use of currency formatting for tuition fees or other financial data.
To achieve this, built-in stream manipulators such as endl, setw, setfill, and setprecision must be used
to create a neatly formatted output.
The system first reads student names and their corresponding marks, ensuring that the data is aligned
in tabular form. Proper spacing between columns enhances readability, preventing misalignment
issues caused by varying name lengths or mark values. Additionally, numerical values must be
displayed with controlled decimal precision for consistency.
Beyond academic scores, the university also wants to format financial figures, such as tuition fees, in
a standardized manner. To achieve this, the system includes a user-defined manipulator, currency(),
which prepends a specified currency symbol (₹, $, etc.) before displaying monetary values. This custom
formatting ensures that financial data is both readable and professionally presented.*/
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

// Struct to hold student info
struct Student {
    string name;
    float marks;
    float tuition;
};

// User-defined manipulator to display currency symbol
ostream& currency(ostream& os) {
    os << "₹"; // You can change to "$" or any symbol
    return os;
}

int main() {
    vector<Student> students = {
        {"Alice Johnson", 87.5, 50000.0},
        {"Bob Smith", 92.25, 52000.5},
        {"Clara Daniels", 78.0, 48000.75},
        {"Daniel Lee", 88.8, 51000.0}
    };

    // Header
    cout << left << setw(20) << "Name"
         << right << setw(10) << "Marks"
         << right << setw(20) << "Tuition Fee" << endl;
    cout << setfill('-') << setw(50) << "-" << setfill(' ') << endl;

    // Print each student record
    for (const auto& s : students) {
        cout << left << setw(20) << s.name
             << right << setw(10) << fixed << setprecision(2) << s.marks
             << right << setw(10) << currency << fixed << setprecision(2) << s.tuition
             << endl;
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}
