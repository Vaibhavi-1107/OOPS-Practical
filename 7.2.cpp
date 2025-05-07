/*A data analysis firm is developing a tool to process large text files and extract key statistics, such as
the total number of characters, words, and lines. This tool is essential for tasks like document indexing,
text summarization, and data validation. Given the varying sizes of input files, the system must handle
large datasets efficiently while ensuring error detection when files are missing or inaccessible.
To begin, the program needs to open a specified text file and process its contents line by line. If the
file cannot be found or opened due to permission issues, the system should notify the user with an
appropriate error message and safely terminate execution. Once the file is successfully accessed, the
program will analyze its contents to count the total number of lines, extract words while handling
different delimiters, and compute the total number of characters, including spaces and punctuation.
For handling this data, the team explores two approaches. One approach dynamically stores the lines
in a manually managed array, processing the information without relying on built-in containers. This
requires careful memory allocation and deallocation to avoid leaks. The alternative approach uses a
dynamic structure to hold the lines in memory, allowing for efficient access and further analysis, such
as searching or editing*/
#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
    ifstream file("data.txt");

    if(!file)
    {
        cerr<<"Error: File could not be opened!"<<endl;
        return 1;
    }
    string line;
    vector<string>lines;
    int linecount=0,wordcount=0,charcount=0;

    while(getline(file,line))
    {
        lines.push_back(line);
        linecount++;

        //Count Characters (excluding newline)
        charcount+=line.length();
        stringstream s(line);
        string word;
        while (s >> word) {
            wordcount++;
        }
    }

    file.close();
    cout << "Total Lines     : " << linecount << "\n";
    cout << "Total Words     : " << wordcount << "\n";
    cout << "Total Characters: " << charcount << "\n";
    cout<<"24CE053_Vaibhavi"<<endl;
    return 0;
}

