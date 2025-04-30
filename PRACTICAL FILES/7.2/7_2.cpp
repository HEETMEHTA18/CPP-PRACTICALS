#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) { cerr << "Usage: " << argv[0] << " <file>\n"; return 1; }
    ifstream file(argv[1]);
    if (!file) { cerr << "Error opening file\n"; return 1; }
    string line, word;
    int lines=0, words=0, chars=0;
    while (getline(file, line)) {
        ++lines;
        chars += line.size() + 1;
        stringstream ss(line);
        while (ss >> word) ++words;
    }
    cout << "Lines: " << lines << " Words: " << words << " Chars: " << chars << endl;
    return 0;
}
