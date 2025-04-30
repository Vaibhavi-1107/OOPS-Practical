/*In a rapidly growing software development firm, a team of engineers is tasked with building a
lightweight, custom memory management system for handling dynamic datasets. The existing
framework lacks flexibility in managing arrays, often leading to inefficient memory usage and
performance bottlenecks. To address this, the engineers need to develop a solution that allows
seamless insertion and deletion of elements while ensuring efficient memory utilization.
The primary challenge is to design a structure that supports adding new data points dynamically at
the end of the dataset and removing specific elements based on their position. Since the system
operates in a resource-constrained environment, using standard template libraries is not an option,
and direct dynamic memory management must be implemented using pointers. The solution should
ensure that memory is allocated and deallocated appropriately to prevent leaks and unnecessary
overhead.
The development team must carefully decide on the structure of their implementation, defining how
data will be stored, accessed, and modified efficiently. They need to outline the appropriate class
design, determine essential data members, and define necessary member functions to handle the
operations effectively */
#include <iostream>

class DynamicArray {
private:
    int* data;
    int size;
    int capacity;

    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray(int initialCapacity = 4)
        : size(0), capacity(initialCapacity) {
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void push_back(int value) {
        if (size == capacity) {
            resize(capacity * 2);
        }
        data[size++] = value;
    }

    void remove_at(int index) {
        if (index < 0 || index >= size) return;
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;

        if (size > 0 && size <= capacity / 4) {
            resize(capacity / 2);
        }
    }

    void print() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }
};
int main() {
    DynamicArray arr;
    arr.push_back(10);
    arr.push_back(20);
    arr.push_back(30);
    arr.print();

    arr.remove_at(1);
    arr.print();

    arr.push_back(40);
    arr.push_back(50);
    arr.print();
    std::cout<<"Vaibhavi 24CE053";
    return 0;
}
