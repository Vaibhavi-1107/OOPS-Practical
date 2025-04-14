/*A community bank sought to enhance its account management system with a digital solution to
improve efficiency and provide better customer service. The system was required to manage the
essential details of each account, including the account number, account holder’s name, and balance.
Additionally, the bank wanted to provide a secure mechanism for transferring money between
accounts, allowing customers to easily manage their funds.
The bank also needed a way to track the total number of accounts created, which would be important
for generating reports and understanding the growth of their customer base. This feature was aimed
at helping the bank maintain an overview of their account portfolio and analyze trends over time.
To ensure smooth and reliable operations, the system was designed to store account information in a
way that would allow easy access and updates. When new accounts were created, they would be
added to the system dynamically. The management team planned for future scalability and
performance improvements by considering more efficient storage and retrieval methods after the
initial system was built, ensuring that the bank could easily accommodate more accounts and
transactions as the customer base grew.*/
#include <iostream>
#include <vector>
using namespace std;

class Account {
private:
    static int totalAccounts;
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    Account(int accNum, string name, double bal) {
        accountNumber = accNum;
        holderName = name;
        balance = bal;
        totalAccounts++;
    }

    // Accessors
    int getAccountNumber() const { return accountNumber; }
    string getHolderName() const { return holderName; }
    double getBalance() const { return balance; }

    // Deposit
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        }
    }

    // Withdraw
    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        return false;
    }

    // Transfer funds
    bool transferTo(Account &receiver, double amount) {
        if (withdraw(amount)) {
            receiver.deposit(amount);
            return true;
        }
        return false;
    }

    // Display account info
    void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: $" << balance << endl;
    }

    // Static method to get total accounts
    static int getTotalAccounts() {
        return totalAccounts;
    }
};

// Initialize static variable
int Account::totalAccounts = 0;

// Function to find an account by account number
Account* findAccount(vector<Account>& accounts, int accNum) {
    for (auto& acc : accounts) {
        if (acc.getAccountNumber() == accNum)
            return &acc;
    }
    return nullptr;
}

int main() {
    vector<Account> accounts;
    int choice;

    do {
        cout << "\n--- Community Bank System ---\n";
        cout << "1. Create New Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Transfer Funds\n";
        cout << "4. Show Total Accounts\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int accNum;
                string name;
                double balance;
                cout << "Enter Account Number: ";
                cin >> accNum;
                cin.ignore();
                cout << "Enter Account Holder Name: ";
                getline(cin, name);
                cout << "Enter Initial Balance: ";
                cin >> balance;
                accounts.emplace_back(accNum, name, balance);
                cout << "Account created successfully!\n";
                break;
            }

            case 2: {
                if (accounts.empty()) {
                    cout << "No accounts to display.\n";
                } else {
                    for (const auto& acc : accounts) {
                        cout << "\n--- Account Details ---\n";
                        acc.display();
                    }
                }
                break;
            }

            case 3: {
                int fromAcc, toAcc;
                double amount;
                cout << "Enter Sender Account Number: ";
                cin >> fromAcc;
                cout << "Enter Receiver Account Number: ";
                cin >> toAcc;
                cout << "Enter Amount to Transfer: ";
                cin >> amount;

                Account* sender = findAccount(accounts, fromAcc);
                Account* receiver = findAccount(accounts, toAcc);

                if (sender && receiver) {
                    if (sender->transferTo(*receiver, amount)) {
                        cout << "Transfer successful!\n";
                    } else {
                        cout << "Transfer failed: Insufficient balance.\n";
                    }
                } else {
                    cout << "One or both account numbers not found.\n";
                }
                break;
            }

            case 4: {
                cout << "Total Accounts Created: " << Account::getTotalAccounts() << endl;
                break;
            }

            case 5:
                cout << "Exiting system...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);
    cout<<"Vaibhavi 24CE053";
    return 0;
}

