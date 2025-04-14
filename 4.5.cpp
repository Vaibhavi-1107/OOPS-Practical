/*In an educational setting, an advanced grading system was conceptualized to accommodate the
diverse evaluation criteria for students at different academic levels. At the heart of the system is an
abstract base class that defines the grading framework. This class includes a protected member to
store marks and declares a pure virtual function for computing grades, ensuring that specific grading
logic is implemented by derived classes.
Two distinct derived classes were introduced to handle the unique grading needs of undergraduate
and postgraduate students. Each class defines its own implementation of the grade computation
method, reflecting the varying academic expectations for these groups. The system enables users to
input student data, compute grades based on the respective criteria, and manage a collection of
student records.*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Abstract Base Class
class Student {
protected:
    string name;
    int marks;
public:
    Student(const string& name, int marks) : name(name), marks(marks) {}
    virtual ~Student() {}

    virtual string computeGrade() const = 0; // pure virtual
    virtual void display() const {
        cout << "Name: " << name << ", Marks: " << marks
             << ", Grade: " << computeGrade() << endl;
    }
};

// Derived Class: UndergraduateStudent
class UndergraduateStudent : public Student {
public:
    UndergraduateStudent(const string& name, int marks)
        : Student(name, marks) {}

    string computeGrade() const override {
        if (marks >= 85) return "A";
        else if (marks >= 70) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }
};

// Derived Class: PostgraduateStudent
class PostgraduateStudent : public Student {
public:
    PostgraduateStudent(const string& name, int marks)
        : Student(name, marks) {}

    string computeGrade() const override {
        if (marks >= 80) return "A";
        else if (marks >= 65) return "B";
        else if (marks >= 50) return "C";
        else return "F";
    }
};

// --- Demo System ---
int main() {
    vector<Student*> students;
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string name, level;
        int marks;
        cout << "\nEnter student name: ";
        cin >> name;
        cout << "Enter academic level (UG/PG): ";
        cin >> level;
        cout << "Enter marks: ";
        cin >> marks;

        if (level == "UG" || level == "ug") {
            students.push_back(new UndergraduateStudent(name, marks));
        } else if (level == "PG" || level == "pg") {
            students.push_back(new PostgraduateStudent(name, marks));
        } else {
            cout << "Invalid level! Skipping student.\n";
        }
    }

    cout << "\n--- Student Grades ---\n";
    for (const auto& student : students) {
        student->display();
    }

    // Cleanup
    for (auto student : students) {
        delete student;
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}
