/*A financial analytics firm is designing a data processing system to filter out duplicate transaction IDs
from large datasets. The system must take an input list of integers, efficiently remove duplicates, and
display the unique values in an ordered manner. Given the need for high performance in handling
large datasets, the implementation must leverage efficient data structures that automatically
eliminate redundancy.
To achieve this, the system employs an associative container that inherently ensures uniqueness while
maintaining a sorted order. As integers are added, duplicate entries are automatically discarded,
eliminating the need for explicit duplicate-checking logic. Once the unique values are identified, they
are either displayed directly using iterators or converted back into a dynamically managed sequence
for further processing.
By utilizing iterators, the system efficiently traverses the filtered dataset, ensuring that unique
elements are accessed and displayed without additional computational overhead.*/

#include <iostream>
#include <set>
#include <iterator>
#include <vector>
using namespace std;
int main() {
    set<int> uniqueTransactions;  // Automatically stores unique and sorted values
    int n, id;

    cout << "Enter number of transaction IDs: ";
    cin >> n;

    cout << "Enter the transaction IDs:\n";
    for (int i = 0; i < n; ++i) {
        cin >> id;
        uniqueTransactions.insert(id); // Duplicates are automatically discarded
    }

    cout << "Unique sorted transaction IDs:\n";
    for (auto it = uniqueTransactions.begin(); it != uniqueTransactions.end(); ++it) {
        cout << *it << " ";
    }
    cout << std::endl;
    cout<<"Vaibhavi 24CE053";
    return 0;
}
