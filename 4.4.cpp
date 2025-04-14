/*In a bid to design an efficient and user-friendly banking system, a structure was proposed that mirrors
the real-world operations of various account types. The foundation of the system is a base class
representing a generic bank account, encapsulating essential details such as account number and
balance. Building on this foundation, two specialized account types were created: a savings account,
which includes an interest rate as an additional feature, and a current account, which allows an
overdraft limit to accommodate specific customer needs.
To ensure proper initialization and cleanup of account objects, constructors and destructors were
implemented. Essential banking operations such as deposits and withdrawals were made available for
both account types, allowing users to perform and manage their transactions effectively. The system
also accounted for the need to track and manage transaction history, enabling operations such as
undoing the last transaction. This was achieved by simulating a mechanism to store a sequence of
transactions for each account type, providing insight into different ways of managing and organizing
data.*/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

// Transaction structure
struct Transaction {
    string type;
    double amount;
};

// Base class
class BankAccount {
protected:
    string accountNumber;
    double balance;
    stack<Transaction> transactionHistory;

public:
    BankAccount(const string& accNum, double bal)
        : accountNumber(accNum), balance(bal) {
        cout << "BankAccount created for " << accountNumber << endl;
    }

    virtual ~BankAccount() {
        cout << "BankAccount for " << accountNumber << " closed.\n";
    }

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push({"deposit", amount});
            cout << "Deposited: $" << amount << endl;
        }
    }

    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            transactionHistory.push({"withdraw", amount});
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    virtual void undoLastTransaction() {
        if (transactionHistory.empty()) {
            cout << "No transaction to undo.\n";
            return;
        }

        Transaction last = transactionHistory.top();
        transactionHistory.pop();

        if (last.type == "deposit") {
            balance -= last.amount;
            cout << "Undid deposit of $" << last.amount << endl;
        } else if (last.type == "withdraw") {
            balance += last.amount;
            cout << "Undid withdrawal of $" << last.amount << endl;
        }
    }

    virtual void display() const {
        cout << "Account Number: " << accountNumber
             << ", Balance: $" << balance << endl;
    }
};

// Derived class: SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(const string& accNum, double bal, double rate)
        : BankAccount(accNum, bal), interestRate(rate) {
        cout << "SavingsAccount created.\n";
    }

    ~SavingsAccount() {
        cout << "SavingsAccount destroyed.\n";
    }

    void applyInterest() {
        double interest = balance * interestRate / 100.0;
        deposit(interest);  // reusing deposit to record interest
        cout << "Interest applied: $" << interest << endl;
    }

    void display() const override {
        BankAccount::display();
        cout << "Interest Rate: " << interestRate << "%\n";
    }
};

// Derived class: CurrentAccount
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(const string& accNum, double bal, double limit)
        : BankAccount(accNum, bal), overdraftLimit(limit) {
        cout << "CurrentAccount created.\n";
    }

    ~CurrentAccount() {
        cout << "CurrentAccount destroyed.\n";
    }

    void withdraw(double amount) override {
        if (amount > 0 && amount <= (balance + overdraftLimit)) {
            balance -= amount;
            transactionHistory.push({"withdraw", amount});
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Exceeds overdraft limit!" << endl;
        }
    }

    void display() const override {
        BankAccount::display();
        cout << "Overdraft Limit: $" << overdraftLimit << endl;
    }
};

// --- Demo ---
int main() {
    SavingsAccount sa("SA123", 1000, 3.5);
    sa.display();
    sa.deposit(500);
    sa.withdraw(200);
    sa.applyInterest();
    sa.undoLastTransaction();  // undo interest
    sa.display();

    cout << "\n-----------------------------\n";

    CurrentAccount ca("CA456", 500, 300);
    ca.display();
    ca.withdraw(700);  // allowed due to overdraft
    ca.withdraw(200);  // exceeds limit
    ca.undoLastTransaction();  // undo last withdrawal
    ca.display();
    cout<<"Vaibhavi 24CE053";
    return 0;
}
