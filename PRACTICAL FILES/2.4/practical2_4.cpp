/*A mid-sized retail store faced challenges in efficiently managing its inventory of items. The store's
management sought to build a system that could keep track of individual items, including details like
a unique item ID, item name, price, and the quantity available in stock. The need for a streamlined
process arose due to frequent stock discrepancies, which led to issues with customer satisfaction and
operational efficiency.
To address this, the store hired a team of developers to create a digital inventory management system.
The envisioned solution would allow for the initialization of item details, either with default values or
specific attributes like ID, name, price, and starting quantity. This system needed to handle operations
like increasing stock levels when new shipments arrived and decreasing stock when items were sold,
ensuring sufficient inventory was available for each transaction. Additionally, the system would
provide clear, detailed summaries of each item's status, aiding in decision-making and reporting.
The developers faced real-world scenarios where they had to manage multiple inventory items
simultaneously. They planned to design an array of inventory items and simulate common tasks such
as adding stock, processing sales transactions, and displaying the current inventory details. Handling
edge cases, such as attempting to sell more items than available in stock, became a critical part of the
implementation to ensure reliability.*/
#include <iostream>
#include <vector>
using namespace std;

class Item {
    int id;
    string name;
    int quantity;
    double price;
public:
    Item(int i, string n, int q, double p): id(i), name(n), quantity(q), price(p) {}
    void addStock(int q) { quantity += q; }
    bool sell(int q) {
        if(q > quantity) {
            cout << "Not enough stock for " << name << endl;
            return false;
        }
        quantity -= q;
        return true;
    }
    void display() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << ", Price: " << price << endl;
    }
    double value() { return quantity * price; }
};

int main(){
    vector<Item> items;
    items.push_back(Item(1, "Shirt", 30, 15.50));
    items.push_back(Item(2, "Pants", 20, 25.0));
    items[0].sell(5);
    items[1].addStock(10);
    for(auto &item: items) {
        item.display();
    }
    double totalValue = 0;
    for(auto &item: items) {
        totalValue += item.value();
    }
    cout << "Total inventory value: " << totalValue << endl;
    return 0;
}
