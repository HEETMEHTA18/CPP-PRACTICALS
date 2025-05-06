#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

// Main function to implement the directory management system
int main() {
    // Map to store folder names as keys and their associated files as values
    map<string, vector<string>> directory;

    string command; // Variable to store user commands

    // Loop to process user commands
    while (cin >> command) {
        if (command == "mkdir") {
            // Create a new folder
            string folderName;
            cin >> folderName;
            directory[folderName]; // Initialize an empty folder
        } 
        else if (command == "add") {
            // Add a file to an existing folder
            string folderName, fileName;
            cin >> folderName >> fileName;
            directory[folderName].push_back(fileName); // Append file to the folder
        } 
        else if (command == "ls") {
            // Display the directory structure
            vector<string> folderNames;

            // Collect all folder names
            for (auto &entry : directory) {
                folderNames.push_back(entry.first);
            }

            // Sort folder names alphabetically
            sort(folderNames.begin(), folderNames.end());

            // Display each folder and its files
            for (auto &folder : folderNames) {
                cout << folder << ": ";

                // Sort files within the folder alphabetically
                sort(directory[folder].begin(), directory[folder].end());

                // Display files
                for (auto &file : directory[folder]) {
                    cout << file << " ";
                }
                cout << endl;
            }
        } 
        else {
            // Exit the program for any other command
            break;
        }
    }

    return 0;
}
