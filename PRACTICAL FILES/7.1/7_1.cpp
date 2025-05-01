#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <cctype>
using namespace std;


int main() {
    string line;
    getline(cin, line);
    map<string,int> freq;
    stringstream ss(line);
    string word;
    while (ss >> word) {
        for (auto &c : word) c = tolower(c);
        freq[word]++;
    }
    for (auto &p : freq)
        cout << p.first << ": " << p.second << endl;
    return 0;
}
