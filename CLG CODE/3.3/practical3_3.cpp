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
    string name;
    int accNumber;
    double balance;
    static int count;
public:
    Account(string n, int acc, double bal): name(n), accNumber(acc), balance(bal) {
        count++;
    }
    static int getCount() { return count; }
    void deposit(double amt) { balance += amt; }
    bool withdraw(double amt) {
        if(amt > balance) return false;
        balance -= amt;
        return true;
    }
    bool transfer(Account &to, double amt) {
        if(withdraw(amt)) {
            to.deposit(amt);
            return true;
        }
        return false;
    }
    void display() {
        cout << "Name: " << name << ", Acc:: " << accNumber << ", Balance: " << balance << endl;
    }
};

int Account::count = 0;

int main(){
    Account a1("Heet", 101, 5000);
    Account a2("om", 102, 3000);
    a1.transfer(a2, 1500);
    a1.display();
    a2.display();
    cout << "Total accounts created: " << Account::getCount() << endl;
    return 0;
}
