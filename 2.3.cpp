/*In a growing city, a newly established bank sought to streamline its operations by implementing a
digital system to manage customer accounts. The management envisioned a system where each
account would store details about the account holder, their unique account number, and the current
balance. To ensure flexibility and accuracy, they required functionalities for creating accounts with
varying initial balances, depositing money, withdrawing funds (with checks for sufficient balance), and
generating detailed account summaries.
The bank's IT team faced the challenge of developing a robust solution. They began by sketching out
the essential features of the system. The team highlighted that new accounts could be created in two
ways: one with no initial balance, and another with specified account details and a starting amount.
Additionally, they recognized the need for reliable mechanisms to handle deposits and withdrawals,
ensuring proper validation to prevent overdrafts. Displaying account details in a clear format was also
prioritized for customer communication.
To ensure scalability, the team decided to simulate the system by creating multiple accounts using the
proposed methods. They tested various scenarios, such as depositing and withdrawing different
amounts, handling edge cases like insufficient funds, and verifying that the account summaries were
accurate. This iterative approach helped them refine the system and ensure its readiness for
deployment.*/
#include<iostream>
#include<string>
using namespace std;
class BankAccount
{
    private:
        string acc_num;
        string acc_holder;
        double balance;
    public:
        BankAccount(string acc_no,string acc_hold,double initial_bal=0)
        {
            acc_num=acc_no;
            acc_holder=acc_hold;
            balance=initial_bal;
        }
    void deposit(double amount){
        if(amount>0)
        {
            balance+=amount;
            cout<<"Deposited $"<<amount<<"New balance:$"<<balance<<endl;
        }
        else{
            cout<<"Deposit amount must be positive."<<endl;
        }
    }
    void withdraw(double amount){
        if(amount>0)
        {
            if(amount<=balance)
            {
                balance-=amount;
                cout<<"Withdraw$"<<amount<<"Remaining balance:$"<<balance<<endl;
            }
            else
            {
                cout<<"Insufficient funds."<<endl;
            }
        }
        else
        {
            cout<<"Withdrawal amount must be positive."<<endl;
        }
    }
    void get_acc_summary() const{
        cout<<"Account Holder:"<<acc_holder<<"\n";
        cout<<"Account Number:"<<acc_num<<"\n";
        cout<<"Balance:$"<<balance<<"\n";
    }
};
int main()
{
    BankAccount account1("13578265","Vaibhavi");
    BankAccount account2("54327894","Pal",600.0);

    account1.deposit(200);
    account1.withdraw(400);
    account1.get_acc_summary();

    account2.deposit(400);
    account2.withdraw(45);
    account2.get_acc_summary();
    cout<<"Vaibhavi 24CE053";
    return 0;
}

