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
#include <iostream>
using namespace std;

class Account {
    string name;
    int accountNumber;
    double balance;
public:
    // Default constructor with initial values
    Account() : name("Default"), accountNumber(0), balance(0.0) {}
    // Parameterized constructor
    Account(string n, int acc, double bal) : name(n), accountNumber(acc), balance(bal) {}

    void deposit(double amount) {
        if(amount > 0) balance += amount;
    }
    void withdraw(double amount) {
        if(amount <= balance) balance -= amount;
        else cout << "Withdrwal attempt rejected.\n";
    }
    void display() {
        cout << "Name: " << name << ", Acc:: " << accountNumber << ", Balance: " << balance << endl;
    }
};

int main(){
    Account a1; 
    Account a2("King", 202, 1000);
    a1.deposit(500);
    a2.withdraw(200);
    a1.display();
    a2.display();
    return 0;
}
