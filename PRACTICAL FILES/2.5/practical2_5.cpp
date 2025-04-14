/*A regional banking institution sought to improve its loan management process by developing a system
that could efficiently handle loan details for applicants. The system was expected to streamline the
calculation of monthly EMIs (Equated Monthly Instalments) and provide detailed loan summaries for
customers. This initiative aimed to enhance customer experience by offering accurate and transparent
information about their loans.

To meet these requirements, the bank's technology team was tasked with designing a solution. They
envisioned a system where each loan would be uniquely identified by a loan ID, and additional details
such as the applicant's name, total loan amount, annual interest rate, and loan tenure in months
would be stored. The team also emphasized the importance of accurately calculating the EMI using a
standard formula based on the loan amount, interest rate, and tenure. The formula incorporated
compound interest principles to determine the fixed monthly payment for the loan term.*/
#include <iostream>
#include <cmath>
using namespace std;

class Loan {
    int loanID;
    string applicant;
    double principal;
    double annualRate;
    int tenureMonths;
public:
    Loan(int id, string name, double p, double rate, int tenure):
         loanID(id), applicant(name), principal(p), annualRate(rate), tenureMonths(tenure) {}

    double calculateEMI() {
        double r = annualRate / 1200.0; // monthly interest rate (convert percentage)
        return (principal * r * pow(1 + r, tenureMonths)) / (pow(1 + r, tenureMonths) - 1);
    }
    void display() {
        cout << "Loan ID: " << loanID << ", Applicant: " << applicant 
             << ", Principal: " << principal << ", EMI: " << calculateEMI() << endl;
    }
};

int main(){
    Loan l1(101, "Om ", 50000, 12, 24);
    l1.display();
    return 0;
}
