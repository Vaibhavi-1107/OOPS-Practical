/*A data analytics company was tasked with developing a unique digital signature system based on the
concept of "super digits." The system required finding a single-digit representation of a given number
through recursive digit summation. The algorithm was defined as follows:
If the number has only one digit, it is its super digit. Otherwise, the super digit is the super digit of the
sum of its digits, repeated recursively until a single digit is obtained.
The challenge involved an additional complexity—constructing the number by concatenating a given
string representation of an integer multiple times. For example, if the number n was represented as a
string and concatenated k times, the super digit of the resulting number needed to be calculated.
For instance:
Given n = 9875 and k = 4, the number is represented as 9875987598759875.
The sum of digits in this number is calculated recursively until a single digit remains:
9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 + 9 + 8 + 7 + 5 = 116
1 + 1 + 6 = 8
The super digit is 8.
The system was required to handle large numbers efficiently by leveraging mathematical insights
rather than explicitly constructing large concatenated strings. This case study called for implementing
a recursive solution to calculate the super digit, supported by a mathematical approach to optimize
the handling of repeated sums.*/
#include <iostream>
#include <string>
using namespace std;

// Recursive function to compute super digit
int superDigit(long long n) {
    if (n < 10) return n;

    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return superDigit(sum);
}

// Overload for string + repetition count
int computeSuperDigit(string n, int k) {
    long long initialSum = 0;
    for (char digit : n) {
        initialSum += digit - '0';
    }

    long long multipliedSum = initialSum * k;
    return superDigit(multipliedSum);
}

int main() {
    string n = "9875";
    int k = 4;

    int result = computeSuperDigit(n, k);
    cout << "Super Digit: " << result << endl;
    cout<<"Vaibhavi 24CE053";
    return 0;
}

