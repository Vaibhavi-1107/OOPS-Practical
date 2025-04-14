/*A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability. */
#include <iostream>
#include <vector>
using namespace std;

class Item {
private:
    int itemID;
    string itemName;
    double price;
    int quantity;

public:
    // Default constructor
    Item() {
        itemID = 0;
        itemName = "Unnamed Item";
        price = 0.0;
        quantity = 0;
    }

    // Parameterized constructor
    Item(int id, string name, double p, int q) {
        itemID = id;
        itemName = name;
        price = p;
        quantity = q;
    }

    // Add stock
    void addStock(int amount) {
        if (amount > 0) {
            quantity += amount;
            cout << "Stock updated.\n";
        } else {
            cout << "Invalid stock amount.\n";
        }
    }

    // Sell item
    void sellItem(int amount) {
        if (amount > 0 && amount <= quantity) {
            quantity -= amount;
            cout << "Sale successful.\n";
        } else {
            cout << "Insufficient stock or invalid amount.\n";
        }
    }

    // Display item details
    void display() const {
        cout << "\nItem ID: " << itemID << endl;
        cout << "Item Name: " << itemName << endl;
        cout << "Price: $" << price << endl;
        cout << "Available Quantity: " << quantity << endl;
    }
};

int main() {
    vector<Item> inventory;
    int choice;

    do {
        //cout << "\n--- Inventory Management System ---\n";
        cout << "1. Add Item (Default Values)\n";
        cout << "2. Add Item (Custom Details)\n";
        cout << "3. Add Stock\n";
        cout << "4. Process Sale\n";
        cout << "5. Display All Items\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                inventory.emplace_back();
                cout << "Default item added.\n";
                break;
            }
            case 2: {
                int id, qty;
                string name;
                double price;
                cout << "Enter Item ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Item Name: ";
                getline(cin, name);
                cout << "Enter Price: ";
                cin >> price;
                cout << "Enter Starting Quantity: ";
                cin >> qty;
                inventory.emplace_back(id, name, price, qty);
                cout << "Item added successfully.\n";
                break;
            }
            case 3: {
                int index, amount;
                cout << "Enter item index (0 to " << inventory.size() - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < inventory.size()) {
                    cout << "Enter quantity to add: ";
                    cin >> amount;
                    inventory[index].addStock(amount);
                } else {
                    cout << "Invalid item index.\n";
                }
                break;
            }
            case 4: {
                int index, amount;
                cout << "Enter item index (0 to " << inventory.size() - 1 << "): ";
                cin >> index;
                if (index >= 0 && index < inventory.size()) {
                    cout << "Enter quantity to sell: ";
                    cin >> amount;
                    inventory[index].sellItem(amount);
                } else {
                    cout << "Invalid item index.\n";
                }
                break;
            }
            case 5: {
                if (inventory.empty()) {
                    cout << "No items in inventory.\n";
                } else {
                    for (size_t i = 0; i < inventory.size(); ++i) {
                        cout << "\n--- Item " << i + 1 << " ---";
                        inventory[i].display();
                    }
                }
                break;
            }
            case 6:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);
    cout<<"Vaibhavi 24CE053";
    return 0;
}
