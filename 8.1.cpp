/*A data analytics firm is developing a tool to process numerical sequences efficiently. One of the key
requirements is to reverse a given sequence of integers while ensuring optimized performance using
modern C++ techniques. The system should allow users to input a sequence of numbers, process the
reversal using iterators, and display the transformed output.
To accomplish this, two approaches are explored. The first method leverages the built-in std::reverse()
function, which efficiently reverses elements within a dynamically managed sequence. The second
approach involves manually implementing the reversal using iterators, providing deeper insight into
how iterators navigate and modify data structures.
The system uses a dynamic storage mechanism to handle sequences of varying sizes efficiently.
Iterators facilitate traversal and modification, ensuring that elements are manipulated without direct
indexing.*/
#include <iostream>
#include <vector>
#include <iterator> // for std::iter_swap
using namespace std;

// Function to manually reverse the sequence using iterators
void manualReverse(vector<int>& sequence) {
    auto left = sequence.begin();
    auto right = sequence.end();

    if (!sequence.empty()) {
        --right; // Set right to point to the last element
    }

    while (left < right) {
        iter_swap(left, right);
        ++left;
        --right;
    }
}

// Function to display the sequence
void display(const vector<int>& sequence) {
    for (int num : sequence) {
        cout << num << " ";
    }
    cout <<endl;
}

int main() {
    vector<int> sequence;
    int n, value;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the sequence:\n";
    for (int i = 0; i < n; ++i) {
        cin >> value;
        sequence.push_back(value);
    }

    manualReverse(sequence);

    cout << "Reversed sequence using iterators: ";
    display(sequence);
    cout<<"Vaibhavi 24CE053";
    return 0;
}
