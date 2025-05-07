/*A software development team requires a lightweight directory management system to efficiently
organize project files. The system should allow users to create folders, add files to specific folders, and
display the directory structure in an organized manner.
Each folder serves as a unique entry, mapping to a list of associated files, ensuring structured storage
and easy retrieval. A hierarchical mapping approach is used, where folder names act as keys, and
dynamically resizable sequences store the corresponding filenames.
The system provides essential functionalities, including adding new folders, appending files to existing
folders, and displaying the complete directory structure. To enhance accessibility, folder names are
sorted alphabetically, allowing users to quickly locate specific folders and their contents. Iterators are
used for efficient traversal and structured display of data. This approach ensures optimized
performance, even for large datasets, while maintaining a logical and organized hierarchy.*/
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// Type alias for the directory: folder name -> list of files
using Directory = map<string, vector<string>>;

// Function to add a new folder
void addFolder(Directory& dir, const string& folderName) {
    dir[folderName]; // creates folder if it doesn't exist
}

// Function to add a file to a folder
void addFileToFolder(Directory& dir, const string& folderName, const string& fileName) {
    dir[folderName].push_back(fileName); // folder created if not exists, then file added
}

// Function to display the entire directory structure
void displayDirectory(const Directory& dir) {
    cout << "\nDirectory Structure:\n";
    for (auto it = dir.begin(); it != dir.end(); ++it) {
        cout << "Folder: " << it->first << endl;
        for (const auto& file : it->second) {
            cout << "  - " << file << std::endl;
        }
    }
}

int main() {
    Directory directory;
    int choice;
    string folder, file;

    while (true) {
        cout << "\n1. Add Folder\n2. Add File to Folder\n3. Display Directory\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                cin >> folder;
                addFolder(directory, folder);
                cout << "Folder added.\n";
                break;

            case 2:
                cout << "Enter folder name: ";
                cin >> folder;
                cout << "Enter file name: ";
                cin >> file;
                addFileToFolder(directory, folder, file);
                cout << "File added.\n";
                break;

            case 3:
                displayDirectory(directory);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
    cout<<"Vaibhavi 24CE053";
}
