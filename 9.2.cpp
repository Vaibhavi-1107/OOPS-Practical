/*Imagine you are tasked with developing a simple banking system for a local financial institution. The
bank has observed an increase in customer complaints regarding unclear transaction records and
unhandled errors during operations. They want a robust software module to manage bank accounts
efficiently while maintaining a log of transactions.
As a software developer, your job is to create a banking system with the following features:
1. A way to represent individual bank accounts, including the ability to manage their balances.
2. Secure methods to deposit and withdraw funds.
3. An error-handling mechanism to address invalid operations, such as attempting to withdraw more
than the account's current balance.
4. A feature that logs every function call when an error occurs to provide insights into the issue.
The bank also insists on maintaining a history of transactions using basic data structures without
relying on advanced libraries or containers. Design and implement a banking system that fulfills the
above requirements. */
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

const int MAX_TRANSACTIONS = 100; // Limit to 100 transactions

class BankAccount {
private:
    string accountHolder;
    double balance;
    string transactionHistory[MAX_TRANSACTIONS];
    int transactionCount;

    // Logs an error with function name
    void logError(const string& functionName, const string& errorMsg) {
        cerr << "[Error] In function: " << functionName << " - " << errorMsg << endl;
    }

    // Logs successful transaction
    void logTransaction(const string& message) {
        if (transactionCount < MAX_TRANSACTIONS) {
            transactionHistory[transactionCount++] = message;
        }
    }

public:
    BankAccount(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
        transactionCount = 0;
        logTransaction("Account created with balance: " + to_string(balance));
    }

    void deposit(double amount) {
        try {
            if (amount <= 0) throw invalid_argument("Deposit amount must be positive.");
            balance += amount;
            logTransaction("Deposited: " + to_string(amount));
        } catch (const exception& e) {
            logError("deposit", e.what());
        }
    }

    void withdraw(double amount) {
        try {
            if (amount <= 0) throw invalid_argument("Withdrawal amount must be positive.");
            if (amount > balance) throw runtime_error("Insufficient funds.");
            balance -= amount;
            logTransaction("Withdrew: " + to_string(amount));
        } catch (const exception& e) {
            logError("withdraw", e.what());
        }
    }

    void showBalance() const {
        cout << "Current balance: " << balance << endl;
    }

    void showTransactionHistory() const {
        cout << "Transaction History for " << accountHolder << ":\n";
        for (int i = 0; i < transactionCount; ++i) {
            cout << i + 1 << ". " << transactionHistory[i] << endl;
        }
    }
};

int main() {
    BankAccount account("Vaibhavi Kariya", 10000.0);

    account.deposit(5000.0);
    account.withdraw(2500.0);
    account.withdraw(2000.0); // Error: Insufficient funds
    account.deposit(-50.0);   // Error: Invalid deposit
    account.showBalance();
    account.showTransactionHistory();
    cout<<"Vaibhavi 24CE053";
    return 0;
}
