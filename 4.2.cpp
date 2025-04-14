/*A growing organization wanted to develop a system to manage its hierarchy and represent its
structure in a programmatic way. To achieve this, a multilevel approach was designed, reflecting the
natural progression of roles within the organization. At the foundation, a class was created to
represent a person, capturing the basic details such as name and age. Building on this, an intermediate
level was introduced to represent employees, adding a unique identifier for each. Finally, at the
topmost level, a class for managers was created, which included additional details such as the
department they oversee.
The system needed to handle the initialization of all these attributes through constructors at each
level, ensuring the proper propagation of information across the hierarchy. Additionally, the
functionality to display details at every level was included to provide clear insights into the
organization's structure. Two approaches were explored for managing multiple managers: one relied
on an efficient method for retrieval and organization based on employee identifiers, while the other
used a straightforward and static method for storage.*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    virtual void displayDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

// Intermediate class
class Employee : public Person {
protected:
    int employeeID;
public:
    Employee(string n, int a, int employeeid)
        : Person(n,a), employeeID(employeeid) {}
    void displayDetails() const override {
        Person::displayDetails();
        cout << "Employee ID: " << employeeID << endl;
    }
    int getEmployeeID() const {
        return employeeID;
    }
};

// Top-level class
class Manager : public Employee {
private:
    string department;
public:
    Manager():Employee("",0,0),department("") {}    //Default constructor
    Manager(string n, int a, int employeeid,string dept)
        : Employee(n, a, employeeid), department(dept) {}
    void displayDetails() const override {
        Employee::displayDetails();
        cout << "Department: " << department << endl;
    }
    string getDepartment() const {
        return department;
    }
};

// --- Approach 1: Efficient retrieval using map ---
class ManagerDirectoryMap {
private:
    map<int, Manager> managerMap;
public:
    void addManager(const Manager& manager) {
        managerMap[manager.getEmployeeID()] = manager;
    }

    void displayManager(int employeeID) const {
        auto it = managerMap.find(employeeID);
        if (it != managerMap.end()) {
            cout << "\nManager (from map):" << endl;
            it->second.displayDetails();
        } else {
            cout << "Manager with ID " << employeeID << " not found." << endl;
        }
    }
};

// --- Approach 2: Simple static storage using vector ---
class ManagerDirectoryVector {
private:
    vector<Manager> managerList;
public:
    void addManager(const Manager& manager) {
        managerList.push_back(manager);
    }

    void displayAllManagers() const {
        cout << "\nAll Managers (from vector):" << endl;
        for (const auto& manager : managerList) {
            manager.displayDetails();
            cout << "------------------------" << endl;
        }
    }
};

// --- Demo ---
int main() {
    map<int,Manager>managers;
    managers[101] = Manager("Alice", 40, 1001, "Sales");
    managers[102] = Manager("Bob", 45, 1002, "Engineering");
    int searchId;
    cout<<"Enter Employee Id to search:";
    cin>>searchId;
    if(managers.find(searchId)!= managers.end())
    {
        cout<<"\nManager Details:\n";
        managers[searchId].displaymanager();
    }
    else{
        cout<<"Manager with ID "<<searchId<<"not found.\n";
    }

    cout<<"Vaibhavi 24CE053";
    return 0;
}
