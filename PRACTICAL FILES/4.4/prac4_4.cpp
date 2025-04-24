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
#include <vector>
#include <string>
using namespace std;

// Base class
class BankAccount {
protected:
    string accountNumber;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount(string accNo, double initialBalance)
        : accountNumber(accNo), balance(initialBalance) {
        cout << "BankAccount created for " << accountNumber << endl;
    }

    virtual ~BankAccount() {
        cout << "BankAccount for " << accountNumber << " is closed." << endl;
    }

    virtual void deposit(double amount) {
        balance += amount;
        transactionHistory.push_back("Deposit: +" + to_string(amount));
    }

    virtual void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionHistory.push_back("Withdraw: -" + to_string(amount));
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }

    void undoLastTransaction() {
        if (transactionHistory.empty()) {
            cout << "No transaction to undo." << endl;
            return;
        }

        string last = transactionHistory.back();
        transactionHistory.pop_back();

        if (last.find("Deposit") != string::npos) {
            double amt = stod(last.substr(last.find("+") + 1));
            balance -= amt;
            cout << "Undid deposit of " << amt << endl;
        } else if (last.find("Withdraw") != string::npos) {
            double amt = stod(last.substr(last.find("-") + 1));
            balance += amt;
            cout << "Undid withdrawal of " << amt << endl;
        }
    }

    virtual void display() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

// Derived class: Savings Account
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNo, double initialBalance, double rate)
        : BankAccount(accNo, initialBalance), interestRate(rate) {}

    void applyInterest() {
        double interest = balance * interestRate / 100;
        balance += interest;
        transactionHistory.push_back("Interest: +" + to_string(interest));
    }

    void display() override {
        BankAccount::display();
        cout << "Account Type: Savings, Interest Rate: " << interestRate << "%" << endl;
    }
};

// Derived class: Current Account
class CurrentAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CurrentAccount(string accNo, double initialBalance, double limit)
        : BankAccount(accNo, initialBalance), overdraftLimit(limit) {}

    void withdraw(double amount) override {
        if (balance + overdraftLimit >= amount) {
            balance -= amount;
            transactionHistory.push_back("Withdraw: -" + to_string(amount));
        } else {
            cout << "Overdraft limit exceeded!" << endl;
        }
    }

    void display() override {
        BankAccount::display();
        cout << "Account Type: Current, Overdraft Limit: " << overdraftLimit << endl;
    }
};

// Example usage
int main() {
    SavingsAccount sa("HELLO", 5000, 5.0);
    sa.deposit(1000);
    sa.applyInterest();
    sa.withdraw(2000);
    sa.display();
    sa.undoLastTransaction();
    sa.display();

    cout << "-----------------------------" << endl;

    CurrentAccount ca("WORLD", 3000, 1000);
    ca.deposit(500);
    ca.withdraw(3500);  // within overdraft
    ca.withdraw(200);   // exceeds overdraft
    ca.display();
    ca.undoLastTransaction();
    ca.display();

    return 0;
}
