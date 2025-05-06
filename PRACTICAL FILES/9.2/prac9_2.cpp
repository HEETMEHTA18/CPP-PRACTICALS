#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Class to represent a bank account
class BankAccount {
private:
    string accountHolderName;
    double balance;
    vector<string> transactionHistory; // To maintain a history of transactions

    // Function to log transactions
    void logTransaction(const string& transaction) {
        transactionHistory.push_back(transaction);
    }

public:
    // Constructor to initialize account details
    BankAccount(const string& name, double initialBalance) : accountHolderName(name), balance(initialBalance) {
        if (initialBalance < 0) {
            logTransaction("Error: Initial balance cannot be negative.");
            balance = 0;
        }
        logTransaction("Account created with balance: " + to_string(balance));
    }

    // Method to deposit funds
    void deposit(double amount) {
        if (amount <= 0) {
            logTransaction("Error: Attempted to deposit a non-positive amount: " + to_string(amount));
            cout << "Invalid deposit amount. Please enter a positive value.\n";
            return;
        }
        balance += amount;
        logTransaction("Deposited: " + to_string(amount) + ", New Balance: " + to_string(balance));
    }

    // Method to withdraw funds
    void withdraw(double amount) {
        if (amount <= 0) {
            logTransaction("Error: Attempted to withdraw a non-positive amount: " + to_string(amount));
            cout << "Invalid withdrawal amount. Please enter a positive value.\n";
            return;
        }
        if (amount > balance) {
            logTransaction("Error: Insufficient funds for withdrawal of: " + to_string(amount));
            cout << "Insufficient funds. Withdrawal denied.\n";
            return;
        }
        balance -= amount;
        logTransaction("Withdrew: " + to_string(amount) + ", New Balance: " + to_string(balance));
    }

    // Method to display account details
    void displayAccountDetails() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Current Balance: " << balance << endl;
    }

    // Method to display transaction history
    void displayTransactionHistory() const {
        cout << "Transaction History:\n";
        for (const string& transaction : transactionHistory) {
            cout << transaction << endl;
        }
    }
};

int main() {
    cout << "Welcome to the Banking System!\n";

    // Create a bank account
    string name;
    double initialBalance;
    cout << "Enter account holder's name: ";
    getline(cin, name);
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, initialBalance);

    // Menu-driven interface
    int choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Deposit Funds\n";
        cout << "2. Withdraw Funds\n";
        cout << "3. Display Account Details\n";
        cout << "4. Display Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                double amount;
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            }
            case 3:
                account.displayAccountDetails();
                break;
            case 4:
                account.displayTransactionHistory();
                break;
            case 5:
                cout << "Thank you for using the Banking System. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}