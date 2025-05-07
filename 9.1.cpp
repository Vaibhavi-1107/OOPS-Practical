/*Imagine you're developing a financial calculator for a bank's system that allows users to calculate the
ratio of two monetary values they input. This tool must be reliable, as it's part of a crucial decisionmaking process for loan eligibility.
A bank customer is required to enter two values directly into the system:
1. The first value represents the total loan amount they wish to apply for.
2. The second value represents their annual income.
The system will compute and display the ratio of the loan amount to the income, which helps the bank
assess the customer's loan-to-income ratio.
Major challenges that developer will face while developing the system would be, if the customer
mistakenly enters non-numerical characters (e.g., "abc"), the system should handle the situation
gracefully and prompt the user to correct their input. If the customer enters 0 as their annual income,
the system must identify this issue and avoid performing a division that would lead to an invalid result.*/
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

// Function to get valid double input from user
double getValidInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if input is valid
        if (cin.fail()) {
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a numeric value.\n";
        } else {
            return value;
        }
    }
}

int main() {
    try {
        double loanAmount = getValidInput("Enter the total loan amount: ");
        double annualIncome = getValidInput("Enter your annual income: ");

        if (annualIncome == 0) {
            throw runtime_error("Annual income cannot be zero. Division by zero is not allowed.");
        }

        double ratio = loanAmount / annualIncome;
        cout << "Loan-to-Income Ratio: " << ratio << endl;

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout<<"Vaibhavi 24CE053";
    return 0;
}
