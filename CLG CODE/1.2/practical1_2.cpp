/*A small retail store is facing challenges in managing its inventory effectively. The store sells a
variety of products, each identified by a unique product ID, a name, the available quantity in
stock, and the price per unit. To streamline their operations, the store needs a basic system to
manage this inventory efficiently.
The system must provide the ability to add new products to the inventory, ensuring that each
product has its ID, name, quantity, and price properly recorded. Additionally, the system should
allow the store staff to update the quantity of any existing product, such as when new stock
arrives or when items are sold.
Another essential feature of the system is the calculation of the total value of all products in
the inventory, which is determined by multiplying the quantity of each product by its price and
summing these values for all products.*/
#include <iostream>
#include <vector>
using namespace std;

struct Product {
    int id;
    string name;
    int quantity;
    float price;
};

class Inventory {
    vector<Product> products;
public:
    void addProduct(int id, string name, int qty, float price) {
        products.push_back({id, name, qty, price});
    }
    void updateQuantity(int id, int qtyChange) {
        for (auto &p : products) {
            if (p.id == id) {
                p.quantity += qtyChange;
                return;
            }
        }
    }
    float totalValue() {
        float total = 0;
        for (auto &p : products) {
            total += p.quantity * p.price;
        }
        return total;
    }
    void displayInventory() {
        for (auto &p : products) {
            cout << "ID: " << p.id << ", Name: " << p.name
                 << ", Qty: " << p.quantity << ", Price: " << p.price << endl;
        }
        cout << "Total inventory value: " << totalValue() << endl;
    }
};

int main() {
    Inventory store;
    store.addProduct(1, "Pen", 100, 5);
    store.addProduct(2, "Notebook", 50, 20);
    store.updateQuantity(1, -10);
    store.displayInventory();
    return 0;
}
