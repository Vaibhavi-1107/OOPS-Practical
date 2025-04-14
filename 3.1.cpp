/*A growing organization sought to enhance its payroll process to improve accuracy and efficiency in
calculating employee salaries. The goal was to manage details such as the employee's name, basic
salary, and bonus amount. While most employees would receive a default bonus, there was a need
for flexibility to provide customized bonuses for exceptional performers or those in specialized roles.
To ensure real-time computation of each employee's total salary, the system would dynamically
calculate the total salary by adding the basic salary and the bonus. An inline function was chosen for
this task, allowing the system to compute the total salary instantly during processing. The system was
designed to initialize employee records using a constructor, where the bonus could either be set to a
default value or adjusted according to specific employee criteria.
As the organization expanded, managing employee records efficiently became a key consideration.
The solution involved storing employee details dynamically, ensuring the system could handle a
growing number of records while maintaining scalability and flexibility. Each employee record would
include their personal details, basic salary, and bonus information, with the system displaying a
breakdown of each employee’s details along with their total salary.*/
#include <iostream>
#include <vector>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    // Constructor with default bonus
    Employee(string n, double basic) {
        name = n;
        basicSalary = basic;
        bonus = 500.0; // default bonus
    }

    // Constructor with custom bonus
    Employee(string n, double basic, double b) {
        name = n;
        basicSalary = basic;
        bonus = b;
    }

    // Inline function to calculate total salary
    inline double getTotalSalary() const {
        return basicSalary + bonus;
    }

    // Display employee details
    void display() const {
        cout << "\nEmployee Name: " << name;
        cout << "\nBasic Salary: $" << basicSalary;
        cout << "\nBonus: $" << bonus;
        cout << "\nTotal Salary: $" << getTotalSalary() << "\n";
    }
};

int main() {
    vector<Employee> employees;
    int choice;

    do {
      //  cout << "\n--- Payroll Management System ---\n";
        cout << "1. Add Employee (Default Bonus)\n";
        cout << "2. Add Employee (Custom Bonus)\n";
        cout << "3. Display All Employees\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                double basic;
                cin.ignore();
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Basic Salary: ";
                cin >> basic;
                employees.emplace_back(name, basic);
                cout << "Employee added with default bonus.\n";
                break;
            }
            case 2: {
                string name;
                double basic, bonus;
                cin.ignore();
                cout << "Enter Employee Name: ";
                getline(cin, name);
                cout << "Enter Basic Salary: ";
                cin >> basic;
                cout << "Enter Bonus: ";
                cin >> bonus;
                employees.emplace_back(name, basic, bonus);
                cout << "Employee added with custom bonus.\n";
                break;
            }
            case 3: {
                if (employees.empty()) {
                    cout << "No employee records available.\n";
                } else {
                    for (size_t i = 0; i < employees.size(); ++i) {
                        cout << "\n--- Employee " << i + 1 << " ---";
                        employees[i].display();
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting payroll system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);
    cout<<"Vaibhavi 24CE053";
    return 0;
}

