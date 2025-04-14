/*A technology firm aimed to develop a flexible and reusable solution for managing collections of various
data types, including integers, floating-point numbers, and characters. The system was intended to
perform fundamental operations on these collections, such as finding the maximum value, reversing
the collection, and displaying all elements. To achieve versatility and avoid redundancy in code, the
solution was designed to use function templates, allowing the same logic to be applied seamlessly to
different data types.
The team recognized the importance of using dynamic arrays to store the collections, enabling
efficient management of varying collection sizes. The design emphasized scalability and flexibility,
ensuring that the system could handle different data types and their associated operations with
minimal changes to the core logic.
In practice, the system allowed for the creation of collections for various data types, such as integers,
floating-point numbers, and characters. The operations on these collections included determining the
maximum value, reversing the order of elements, and printing the collection contents.*/
#include <iostream>
#include <vector>
using namespace std;

// Template to display elements
template <typename T>
void displayCollection(const vector<T>& collection) {
    cout << "Collection: ";
    for (const T& item : collection) {
        cout << item << " ";
    }
    cout << endl;
}

// Template to find maximum
template <typename T>
T findMax(const vector<T>& collection) {
    T maxVal = collection[0];
    for (const T& item : collection) {
        if (item > maxVal) {
            maxVal = item;
        }
    }
    return maxVal;
}

// Template to reverse collection
template <typename T>
void reverseCollection(vector<T>& collection) {
    int n = collection.size();
    for (int i = 0; i < n / 2; ++i) {
        swap(collection[i], collection[n - 1 - i]);
    }
}

int main() {
    // Default collections
    vector<int> intCollection = {5, 3, 9, 1, 4};
    vector<float> floatCollection = {2.5f, 7.1f, 3.3f, 6.0f};
    vector<char> charCollection = {'g', 'e', 'n', 'i', 'u', 's'};

    // INT Collection
    cout << "\n--- Integer Collection ---\n";
    displayCollection(intCollection);
    cout << "Max: " << findMax(intCollection) << endl;
    reverseCollection(intCollection);
    cout << "Reversed: ";
    displayCollection(intCollection);

    // FLOAT Collection
    cout << "\n--- Float Collection ---\n";
    displayCollection(floatCollection);
    cout << "Max: " << findMax(floatCollection) << endl;
    reverseCollection(floatCollection);
    cout << "Reversed: ";
    displayCollection(floatCollection);

    // CHAR Collection
    cout << "\n--- Char Collection ---\n";
    displayCollection(charCollection);
    cout << "Max: " << findMax(charCollection) << endl;
    reverseCollection(charCollection);
    cout << "Reversed: ";
    displayCollection(charCollection);
    cout<<"Vaibhavi 24CE053";
    return 0;
}
