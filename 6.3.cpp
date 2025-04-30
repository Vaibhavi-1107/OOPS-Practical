/*A financial analytics company is working on a system that processes large volumes of sorted numerical
data from different sources. The challenge is to efficiently combine two independently sorted datasets
into a single, fully sorted dataset while ensuring optimal memory management. Since the size of the
datasets varies dynamically based on incoming data streams, the solution must be flexible and manage
memory efficiently without relying on built-in container libraries.
To achieve this, the development team needs to implement a mechanism that accepts two sorted
arrays of different sizes and merges them into a new dynamically allocated array while maintaining
the sorted order. The system should read input values specifying the sizes of both datasets, followed
by the elements of each array. After merging, the final sorted array should be displayed as output.
Efficient memory handling is crucial in this implementation, requiring the use of new and delete
operators for dynamic allocation and deallocation of memory. */
#include <iostream>

using namespace std;

// Merge two sorted arrays into a new sorted array
int* mergeSortedArrays(int* arr1, int size1, int* arr2, int size2) {
    int* merged = new int[size1 + size2];
    int i = 0, j = 0, k = 0;

    // Merge process
    while (i < size1 && j < size2) {
        if (arr1[i] <= arr2[j])
            merged[k++] = arr1[i++];
        else
            merged[k++] = arr2[j++];
    }

    // Copy remaining elements (if any)
    while (i < size1)
        merged[k++] = arr1[i++];
    while (j < size2)
        merged[k++] = arr2[j++];

    return merged;
}

int main() {
    int size1, size2;

    // Input sizes
    cout << "Enter size of first sorted array: ";
    cin >> size1;
    int* arr1 = new int[size1];
    cout << "Enter " << size1 << " elements (sorted): ";
    for (int i = 0; i < size1; ++i)
        cin >> arr1[i];

    cout << "Enter size of second sorted array: ";
    cin >> size2;
    int* arr2 = new int[size2];
    cout << "Enter " << size2 << " elements (sorted): ";
    for (int i = 0; i < size2; ++i)
        cin >> arr2[i];

    // Merge arrays
    int* merged = mergeSortedArrays(arr1, size1, arr2, size2);

    // Output result
    cout << "Merged sorted array: ";
    for (int i = 0; i < size1 + size2; ++i)
        cout << merged[i] << " ";
    cout << endl;

    // Clean up memory
    delete[] arr1;
    delete[] arr2;
    delete[] merged;
    cout<<"Vaibhavi 24CE053";
    return 0;
}
