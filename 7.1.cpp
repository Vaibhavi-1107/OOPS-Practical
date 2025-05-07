/*A media research team is developing a tool to analyze word frequency in large textual datasets, such
as news articles and research papers. The goal is to process a given paragraph, identify individual
words, and count their occurrences while ensuring case-insensitive matching. Since the tool is
intended for both constrained environments and high-performance systems, two different
approaches are considered—one utilizing dynamic memory management and another relying on
manually structured arrays.
The first challenge is reading an entire paragraph from the console as a single unformatted string.
Once acquired, the text must be split into individual words, ensuring that uppercase and lowercase
variations are treated as the same. To store and process words dynamically, the team designs a
mechanism using raw pointers and dynamic memory allocation, allowing the program to handle
variable input sizes effectively.
In one approach, a dynamically allocated array is used to store words, with additional logic to count
occurrences efficiently. The array expands as needed, ensuring that new words can be
accommodated. The frequency counting is implemented manually by searching for existing words in
the array and updating counts accordingly.*/
#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

// Convert a string to lowercase
void toLowerCase(char* str) {
    for (int i = 0; str[i]; ++i)
        str[i] = tolower(str[i]);
}

// Check if two C-style strings are equal
bool stringsEqual(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

// Check if a character is part of a word
bool isWordChar(char c) {
    return isalpha(c) || isdigit(c) || c == '\'';
}

int main() {
    const int INITIAL_CAPACITY = 10;
    const int MAX_PARAGRAPH_LENGTH = 1000;

    char paragraph[MAX_PARAGRAPH_LENGTH];

    cout << "Enter a paragraph:\n";
    cin.getline(paragraph, MAX_PARAGRAPH_LENGTH);

    // Convert the entire paragraph to lowercase
    toLowerCase(paragraph);

    // Allocate initial word array
    int capacity = INITIAL_CAPACITY;
    char** words = new char*[capacity];
    int* counts = new int[capacity];
    int wordCount = 0;

    int i = 0;
    while (paragraph[i] != '\0') {
        // Skip non-word characters
        while (paragraph[i] != '\0' && !isWordChar(paragraph[i])) ++i;

        // Extract a word
        char word[100];
        int j = 0;
        while (paragraph[i] != '\0' && isWordChar(paragraph[i])) {
            word[j++] = paragraph[i++];
        }
        word[j] = '\0';

        if (j == 0) continue; // skip if no word found

        // Check if the word already exists
        bool found = false;
        for (int k = 0; k < wordCount; ++k) {
            if (stringsEqual(words[k], word)) {
                ++counts[k];
                found = true;
                break;
            }
        }

        if (!found) {
            // Expand capacity if needed
            if (wordCount == capacity) {
                int newCapacity = capacity * 2;
                char** newWords = new char*[newCapacity];
                int* newCounts = new int[newCapacity];

                for (int k = 0; k < wordCount; ++k) {
                    newWords[k] = words[k];
                    newCounts[k] = counts[k];
                }

                delete[] words;
                delete[] counts;
                words = newWords;
                counts = newCounts;
                capacity = newCapacity;
            }

            // Store the new word
            words[wordCount] = new char[strlen(word) + 1];
            strcpy(words[wordCount], word);
            counts[wordCount] = 1;
            ++wordCount;
        }
    }

    // Display word counts
    cout << "\nWord Frequencies:\n";
    for (int i = 0; i < wordCount; ++i) {
        cout << words[i] << ": " << counts[i] << '\n';
        delete[] words[i]; // Clean up individual word
    }

    delete[] words;
    delete[] counts;
    cout<<"Vaibhavi 24CE053";
    return 0;
}
