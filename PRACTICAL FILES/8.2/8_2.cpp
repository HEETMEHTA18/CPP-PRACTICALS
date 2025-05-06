#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main() {
    string line;
    getline(cin, line);
    map<string,int> freq;
    stringstream ss(line);
    string w;
    while (ss >> w) freq[w]++;
    for (auto &p : freq) cout << p.first << ": " << p.second << endl;
    return 0;
}
