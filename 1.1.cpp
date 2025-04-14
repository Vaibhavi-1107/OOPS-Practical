/*A bank wants to create a simple system to manage customer bank accounts. The system should
allow customers to perform basic banking operations such as depositing money, withdrawing
money, and checking their account balance.
Each bank account will need to have an account holder's name, a unique account number, and
a balance. Deposits should increase the account balance, while withdrawals should only be
allowed if there are sufficient funds in the account. If an attempt is made to withdraw more
money than is available, an error message should be displayed. Customers should also have the
ability to view their account balance whenever required.
The system must be designed using Object-Oriented Programming principles, focusing on
creating a simple and efficient solution to manage the accounts effectively. The system should
ensure that all account details are secure and accessible only through authorized methods.*/
#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

public:
    // Constructor
    BankAccount(string name, int accNum, double initialBalance) {
        accountHolder = name;
        accountNumber = accNum;
        balance = initialBalance;
    }

    // Deposit method
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " to account #" << accountNumber << endl;
        } else {
            cout << "Deposit amount must be positive." << endl;
        }
    }

    // Withdraw method
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Error: Insufficient funds." << endl;
        } else if (amount <= 0) {
            cout << "Withdrawal amount must be positive." << endl;
        } else {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account #" << accountNumber << endl;
        }
    }

    // Method to display account balance
    void displayBalance() const {
        cout << "Account #" << accountNumber << " balance: $" << balance << endl;
    }

    // Display account information
    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    // Creating an account
    BankAccount account1("Alice", 1001, 500.0);

    // Performing operations
    account1.deposit(200);
    account1.withdraw(100);
    account1.withdraw(1000); // Will show error
    account1.displayBalance();
    account1.displayAccountInfo();
    cout<<"Vaibhavi 24CE053";

    return 0;
}
