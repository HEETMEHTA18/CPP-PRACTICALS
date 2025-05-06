#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    map<string, vector<string>> dir;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "mkdir") {
            string f; cin >> f;
            dir[f];
        } else if (cmd == "add") {
            string f, file; cin >> f >> file;
            dir[f].push_back(file);
        } else if (cmd == "ls") {
            for (auto &kv : dir) {
                cout << kv.first << ": ";
                sort(kv.second.begin(), kv.second.end());
                for (auto &file : kv.second) cout << file << " ";
                cout << endl;
            }
        } else break;
    }
    return 0;
}
