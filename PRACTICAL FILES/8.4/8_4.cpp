#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<int,string>> v;
    for (int i=0;i<n;++i) { string name; int score; cin>>name>>score; v.emplace_back(score,name); }
    sort(v.rbegin(), v.rend());
    cout<<"-----------------------------------------------"<<endl;
    for (auto &p : v) cout << p.second << " " << p.first << endl;
    return 0;
}
