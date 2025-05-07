/*A small retail business is looking for a simple yet effective inventory managementsystem to keep track
of its products. The system needs to support essential operations such as adding new items, viewing
the complete inventory, and searching for specific products. Since the inventory data should persist
across sessions, all operations must be performed using file storage. The business also requires an
efficient way to retrieve item details without unnecessary file reads.
To manage inventory, the system must allow employees to add new products by recording details
such as the item name, quantity, and price. These records should be appended to a file, ensuring that
previously stored data remains intact. When viewing inventory, the system should read the file
sequentially and display all stored items. Additionally, employees should be able to search for a
product by name, retrieving its details without manually scanning the entire file.
For implementation, two approaches are considered. One method processes file operations directly,
reading and searching line by line to retrieve item information efficiently. This minimizes memory
usage but requires re-reading the file for each search operation. An alternative approach loads
inventory data into a dynamically managed array, enabling faster searches and future enhancements
such as sorting and filtering without repeated file access.*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

struct Product {
    string name;
    int quantity;
    float price;
};

// Load inventory from file into a vector
vector<Product> loadInventory(const string& filename) {
    vector<Product> inventory;
    ifstream file(filename);
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string name, qtyStr, priceStr;

        getline(ss, name, ',');
        getline(ss, qtyStr, ',');
        getline(ss, priceStr, ',');

        if (!name.empty() && !qtyStr.empty() && !priceStr.empty()) {
            Product p;
            p.name = name;
            p.quantity = stoi(qtyStr);
            p.price = stof(priceStr);
            inventory.push_back(p);
        }
    }

    return inventory;
}

// Save a product to the file
void saveProduct(const string& filename, const Product& p) {
    ofstream file(filename, ios::app);
    if (file) {
        file << p.name << "," << p.quantity << "," << p.price << "\n";
    } else {
        cerr << "Error writing to file.\n";
    }
}

// Add a new product
void addProduct(const string& filename) {
    Product p;
    cout << "Enter product name: ";
    getline(cin, p.name);
    cout << "Enter quantity: ";
    cin >> p.quantity;
    cout << "Enter price: ";
    cin >> p.price;
    cin.ignore(); // flush newline

    saveProduct(filename, p);
    cout << "Product added successfully.\n";
}

// View the inventory
void viewInventory(const string& filename) {
    vector<Product> inventory = loadInventory(filename);

    cout << "\n--- Inventory ---\n";
    cout << left << setw(20) << "Name"
         << setw(10) << "Quantity"
         << setw(10) << "Price" << "\n";

    for (const auto& p : inventory) {
        cout << left << setw(20) << p.name
             << setw(10) << p.quantity
             << fixed << setprecision(2)
             << "$" << p.price << "\n";
    }
}

// Search for a product by name
void searchProduct(const string& filename) {
    string query;
    cout << "Enter product name to search: ";
    getline(cin, query);

    vector<Product> inventory = loadInventory(filename);
    bool found = false;

    for (const auto& p : inventory) {
        if (p.name == query) {
            cout << "Product found:\n";
            cout << "Name: " << p.name << "\n";
            cout << "Quantity: " << p.quantity << "\n";
            cout << "Price: $" << fixed << setprecision(2) << p.price << "\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Product not found.\n";
    }
}

// Main menu
int main() {
    const string filename = "inventory.txt";
    int choice;

    do {
        cout << "\nInventory Management\n";
        cout << "1. Add Product\n";
        cout << "2. View Inventory\n";
        cout << "3. Search Product\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        switch (choice) {
            case 1:
                addProduct(filename);
                break;
            case 2:
                viewInventory(filename);
                break;
            case 3:
                searchProduct(filename);
                break;
            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 4);
    cout<<"Vaibhavi 24CE053";
    return 0;
}
