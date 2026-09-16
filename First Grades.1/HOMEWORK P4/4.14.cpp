#include <iostream>
#include <string>
using namespace std;

int main() 
{
    int accountNumber;
    double initialDebt, totalPurchases, totalDeposits, creditLimit, newDebt;

    cout << "\nEnter account information (-1 to exit)\n";

    while (1) 
    {
        cout << "Enter account number: ";
        cin >> accountNumber;
        if(accountNumber== -1)
        {
            break;
        }

        cout << "Enter initial debt: ";
        cin >> initialDebt;

        cout << "Enter total purchases for the month: ";
        cin >> totalPurchases;

        cout << "Enter total deposits for the month: ";
        cin >> totalDeposits;

        cout << "Enter credit limit: ";
        cin >> creditLimit;

        newDebt = initialDebt + totalPurchases - totalDeposits;

        if (newDebt > creditLimit) 
        {
            cout<< "Account: " << accountNumber
                << "\nCredit Limit: " << creditLimit
                << "\nNew Debt: " << newDebt
                << "\nCredit Limit Exceeded." << endl;
        } 
        else 
        {
            cout<< "Account: " << accountNumber
                << "\nCredit Limit: " << creditLimit
                << "\nNew Debt: " << newDebt
                << "\nCredit is within limits." << endl;
        }
       
    }

    return 0;
}