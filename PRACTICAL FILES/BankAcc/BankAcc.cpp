#include <iostream>
#include <string>
using namespace std;
class BankAccount {
private:
    string accountHolderName;
    string abort;
    int accountNumber;
    double balance;

public:


    BankAccount(const string& name, int accNumber, double initialBalance)
        : accountHolderName(name), accountNumber(accNumber), balance(initialBalance) {
    }


    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited $" << amount << " into account " << accountNumber << ".\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }



    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << " from account " << accountNumber << ".\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }


    void displayBalance() const {
        cout << "Account " << accountNumber << " (" << accountHolderName << ") has a balance of $" << balance << ".\n";
    }
};

int main() {
    string abort;
  cout<<"Do you want to create BankAccount(y/n): ";
  cin>>abort;
  if(abort!="n")
  {  // Create mul
    BankAccount account1("Alice", 1001, 500.0);
    BankAccount account2("Bob", 1002, 1000.0);

  
    account1.displayBalance();
    account1.deposit(200.0);
    account1.withdraw(150.0);
    account1.displayBalance();

    account2.displayBalance();
    account2.withdraw(1200.0); 
    account2.deposit(500.0);
    account2.displayBalance();
  }
  else cout<< "BankAccount is aborted";
    return 0;
}
