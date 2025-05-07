/*An educational institution is developing a system to rank students based on their scores in an
examination. The goal is to efficiently store student names along with their respective scores, sort the
records in descending order based on scores, and display the ranked list. The system should be flexible
enough to handle varying numbers of students dynamically.
To achieve this, the system associates each student’s name with their score using a structured data
representation. A dynamically resizable sequence is chosen to store student records, allowing efficient
insertion and retrieval of entries. Each entry consists of a name-score pair, ensuring logical grouping
of related information.
Once the data is collected, a sorting operation is performed using a custom comparison function. By
leveraging an efficient sorting algorithm, the system ensures that students with the highest scores
appear at the top of the list. Iterators are then used to traverse and display the sorted data in a
structured format, highlighting rank-based ordering.*/
#include <iostream>
#include <vector>
#include <algorithm> // for sort
#include <string>
using namespace std;

// Define a struct to hold student name and score
struct Student {
    string name;
    int score;
};

// Custom comparison function for sorting by descending score
bool compareByScore(const Student& a, const Student& b) {
    return a.score > b.score;
}

int main() {
    vector<Student> students;
    int n;
    string name;
    int score;

    cout << "Enter number of students: ";
    cin >> n;

    cout << "Enter student name and score:\n";
    for (int i = 0; i < n; ++i) {
        cin >> name >> score;
        students.push_back({name, score}); // add student record
    }

    // Sort using custom comparator
    sort(students.begin(), students.end(), compareByScore);

    // Display sorted records using iterators
    cout << "\nRanked Student List:\n";
    int rank = 1;
    for (auto it = students.begin(); it != students.end(); ++it) {
        cout << rank << ". " << it->name << " - " << it->score << std::endl;
        ++rank;
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}
