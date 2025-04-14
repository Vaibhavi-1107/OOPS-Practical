/*A small retail store is facing challenges in managing its inventory effectively. The store sells a
variety of products, each identified by a unique product ID, a name, the available quantity in
stock, and the price per unit. To streamline their operations, the store needs a basic system to
manage this inventory efficiently.
The system must provide the ability to add new products to the inventory, ensuring that each
product has its ID, name, quantity, and price properly recorded. Additionally, the system should
allow the store staff to update the quantity of any existing product, such as when new stock
arrives or when items are sold.
Another essential feature of the system is the calculation of the total value of all products in
the inventory, which is determined by multiplying the quantity of each product by its price and
summing these values for all products.The store management is exploring two approaches for this system: a procedural approach and
an object-oriented approach. The goal is to evaluate these approaches by comparing their ease
of implementation, code reusability, and overall complexity.
The system's design and implementation should consider these requirements and provide an
effective solution (either procedural approach or an object-oriented approach) to the store's
inventory management problems.*/
#include <iostream>
#include <vector>
using namespace std;

class Product {
private:
    int id;
    string name;
    int quantity;
    float price;

public:
    Product(int id, string name, int quantity, float price)
        : id(id), name(name), quantity(quantity), price(price) {}

    int getId() const { return id; }

    void updateQuantity(int qty) {
        quantity += qty;
    }

    float getValue() const {
        return quantity * price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Qty: " << quantity << ", Price: $" << price << endl;
    }
};

class Inventory {
private:
    vector<Product> products;

public:
    void addProduct(int id, string name, int quantity, float price) {
        products.emplace_back(id, name, quantity, price);
        cout << "Product added.\n";
    }

    void updateProductQuantity(int id, int qty) {
        for (auto &product : products) {
            if (product.getId() == id) {
                product.updateQuantity(qty);
                cout << "Quantity updated.\n";
                return;
            }
        }
        cout << "Product not found.\n";
    }

    float getTotalValue() const {
        float total = 0;
        for (const auto &product : products) {
            total += product.getValue();
        }
        return total;
    }

    void showInventory() const {
        for (const auto &product : products) {
            product.display();
        }
    }
};

int main() {
    Inventory store;
    int choice;

    do {
        cout << "\n--- Inventory Menu ---\n";
        cout << "1. Add Product\n2. Update Quantity\n3. Total Inventory Value\n4. Show Inventory\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, qty;
            float price;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Quantity: ";
            cin >> qty;
            cout << "Enter Price: ";
            cin >> price;
            store.addProduct(id, name, qty, price);
        } else if (choice == 2) {
            int id, qty;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter quantity to add/subtract: ";
            cin >> qty;
            store.updateProductQuantity(id, qty);
        } else if (choice == 3) {
            cout << "Total Inventory Value: $" << store.getTotalValue() << endl;
        } else if (choice == 4) {
            store.showInventory();
        } else if (choice != 5) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);
    cout<<"Vaibhavi 24CE053";

    return 0;
}
