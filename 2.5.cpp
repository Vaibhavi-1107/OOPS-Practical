/*A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.
To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.As part of the implementation, the developers planned to initialize loans either with default values for
testing purposes or with actual customer data provided at the time of application. The system needed
to include a feature to display comprehensive loan details, including the calculated EMI, in a customerfriendly format. This functionality was intended to aid both customers and bank staff in managing
loan-related queries effectively.*/
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class Loan {
private:
    int loanID;
    string applicantName;
    double loanAmount;
    double annualInterestRate;
    int tenureMonths;

public:
    // Default constructor
    Loan() {
        loanID = 0;
        applicantName = "Default Applicant";
        loanAmount = 0.0;
        annualInterestRate = 0.0;
        tenureMonths = 0;
    }

    // Parameterized constructor
    Loan(int id, string name, double amount, double rate, int tenure) {
        loanID = id;
        applicantName = name;
        loanAmount = amount;
        annualInterestRate = rate;
        tenureMonths = tenure;
    }

    // Calculate EMI
    double calculateEMI() const {
        if (loanAmount <= 0 || annualInterestRate <= 0 || tenureMonths <= 0) {
            return 0.0;
        }

        double monthlyRate = annualInterestRate / (12 * 100); // Convert annual rate to monthly
        double emi = (loanAmount * monthlyRate * pow(1 + monthlyRate, tenureMonths)) /
                     (pow(1 + monthlyRate, tenureMonths) - 1);
        return emi;
    }

    // Display loan details
    void display() const {
        cout << "\nLoan ID: " << loanID << endl;
        cout << "Applicant Name: " << applicantName << endl;
        cout << "Loan Amount: $" << loanAmount << endl;
        cout << "Annual Interest Rate: " << annualInterestRate << "%" << endl;
        cout << "Tenure: " << tenureMonths << " months" << endl;
        cout << "Monthly EMI: $" << calculateEMI() << endl;
    }
};

int main() {
    vector<Loan> loans;
    int choice;

    do {
        cout << "\n--- Loan Management System ---\n";
        cout << "1. Add Loan (Default Values)\n";
        cout << "2. Add Loan (With Customer Data)\n";
        cout << "3. Display All Loans\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                loans.emplace_back(); // Add default loan
                cout << "Default loan added.\n";
                break;
            }
            case 2: {
                int id, tenure;
                double amount, rate;
                string name;
                cout << "Enter Loan ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Applicant Name: ";
                getline(cin, name);
                cout << "Enter Loan Amount: ";
                cin >> amount;
                cout << "Enter Annual Interest Rate (%): ";
                cin >> rate;
                cout << "Enter Tenure (in months): ";
                cin >> tenure;
                loans.emplace_back(id, name, amount, rate, tenure);
                cout << "Loan record added.\n";
                break;
            }
            case 3: {
                if (loans.empty()) {
                    cout << "No loans to display.\n";
                } else {
                    for (size_t i = 0; i < loans.size(); ++i) {
                        cout << "\n--- Loan " << i + 1 << " ---";
                        loans[i].display();
                    }
                }
                break;
            }
            case 4:
                cout << "Exiting system.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);
    cout<<"Vaibhavi 24CE053";
    return 0;
}

