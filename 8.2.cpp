/*A digital publishing company is developing a tool to analyze text content for word frequency
distribution. This tool aims to help writers and editors understand the prominence of specific words
in an article, enabling them to refine their content for clarity and impact. The system should process
an input sentence, count occurrences of each unique word, and display the results in an organized
manner.
To achieve this, the system utilizes an associative container that maps words to their corresponding
frequencies. As the text is processed, each word is extracted and stored as a key, while its occurrence
count is maintained as the associated value. By leveraging iterators, the system efficiently traverses
the data structure, displaying each word along with its computed frequency.
The use of a dynamic mapping approach ensures that words are stored in an ordered manner, allowing
for fast retrieval and structured output.*/
#include <iostream>
#include <sstream>
#include <map>
#include <string>
using namespace std;

// Function to count word frequencies
void countWordFrequencies(const string& text) {
    map<string, int> wordCount;  // associative container: word -> frequency
    istringstream stream(text);
    string word;

    // Extract words from the input sentence
    while (stream >> word) {
        ++wordCount[word];  // increase count for the word
    }

    // Display results using iterators
    cout << "Word Frequency:\n";
    for (auto it = wordCount.begin(); it != wordCount.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }
}

int main() {
    string input;

    cout << "Enter a sentence:\n";
    getline(cin, input);

    countWordFrequencies(input);
    cout<<"Vaibhavi 24CE053";
    return 0;
}
