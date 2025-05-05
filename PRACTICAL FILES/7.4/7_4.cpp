#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream fin("students.txt");
    struct Rec { string name; int marks; string grade; };
    vector<Rec> v;
    string n; int m; string g;
    while (fin >> n >> m >> g)
        v.push_back({n,m,g});
    cout << left << setw(15) << "Name" << setw(7) << "Marks" << setw(7) << "Grade" << endl;
    cout<<"-----------------------------------" << endl;
    for (auto &r : v)
    {
       
        cout << setw(15) << r.name << setw(7) << r.marks << setw(7) << r.grade << endl;
    }
        return 0;
}
