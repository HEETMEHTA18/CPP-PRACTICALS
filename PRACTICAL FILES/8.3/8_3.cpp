#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of transaction IDs: ";
    cin >> n;

    set<int> transactionIDs;
    cout << "Enter the transaction IDs: ";
    while (n--) {
        int id;
        cin >> id;
        transactionIDs.insert(id); // Automatically ensures uniqueness and sorted order
    }

    cout << "Unique transaction IDs in sorted order: ";
    for (int id : transactionIDs) {
        cout << id << " "; // Display unique IDs using iterators
    }
    cout << endl;

    return 0;
}
