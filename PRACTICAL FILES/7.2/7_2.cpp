#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class FileProcessor {
    string filename;
    int lines, words, chars;

public:
    // Constructor to initialize and process the file
    FileProcessor(const string& fname) : filename(fname), lines(0), words(0), chars(0) {
        processFile();
    }

    // Method to process the file
    void processFile() {
        ifstream file(filename);
        if (!file) {
            cerr << "Error opening file: " << filename << endl;
            return;
        }

        string line, word;
        while (getline(file, line)) {
            ++lines;
            chars += line.size() + 1; // Include newline character
            stringstream ss(line);
            while (ss >> word) ++words;
        }
    }

    // Method to display the statistics
    void displayStats() const {
        cout << "Lines: " << lines << " Words: " << words << " Chars: " << chars << endl;
    }
};

int main() {
    // File name is fixed as "demo.txt"
    FileProcessor processor("helloworld.txt");
    processor.displayStats();
    return 0;
}
