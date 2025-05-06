#include <iostream>
#include <limits>
using namespace std;

// Function to safely get a positive double input from the user
double getPositiveInput(const string& prompt) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        // Check if the input is valid
        if (cin.fail() || value <= 0) {
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a positive numerical value.\n";
        } else {
            return value; // Valid input
        }
    }
}

int main() {
    cout << "Welcome to the Loan-to-Income Ratio Calculator!\n";

    // Get the loan amount from the user
    double loanAmount = getPositiveInput("Enter the total loan amount: ");

    // Get the annual income from the user
    double annualIncome = getPositiveInput("Enter your annual income: ");

    // Calculate the loan-to-income ratio
    double ratio = loanAmount / annualIncome;

    // Display the result
    cout << "The loan-to-income ratio is: " << ratio << endl;

    return 0;
}