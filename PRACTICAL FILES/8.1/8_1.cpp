#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to reverse manually using iterators
void reverseUsingIterators(vector<int>& v) {
    auto start = v.begin();
    auto end = v.end() - 1;
    while (start < end) {
        iter_swap(start, end); // Swap elements pointed by iterators
        ++start;
        --end;
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> v(n);
    cout << "Enter the elements: ";
    for (int &x : v) cin >> x;

    // Reverse using std::reverse()
    vector<int> v1 = v; // Copy original vector
    reverse(v1.begin(), v1.end());
    cout << "Reversed using std::reverse(): ";
    for (int x : v1) cout << x << " ";
    cout << endl;

    // Reverse manually using iterators
    vector<int> v2 = v; // Copy original vector
    reverseUsingIterators(v2);
    cout << "Reversed using iterators: ";
    for (int x : v2) cout << x << " ";
    cout << endl;

    return 0;
}
