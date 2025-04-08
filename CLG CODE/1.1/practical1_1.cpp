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
    string name;
    int accNumber;
    double balance;
public:
    BankAccount(string n, int accNo, double bal) {
        name = n;
        accNumber = accNo;
        balance = bal;
    }
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New balance: " << balance << endl;
        }
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        } else {
            cout << "Insufficient balance!" << endl;
        }
    }
    void displayBalance() {
        cout << "Account Holder: " << name << ", Account Number: " << accNumber
             << ", Balance: " << balance << endl;
    }
};

int main() {
    BankAccount acc("Heet", 101, 5000);
    acc.displayBalance();
    acc.deposit(1500);
    acc.withdraw(2000);
    acc.withdraw(6000);  // This should fail
    acc.displayBalance();
    return 0;
}
