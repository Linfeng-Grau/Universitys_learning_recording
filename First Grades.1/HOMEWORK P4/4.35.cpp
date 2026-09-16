#include <iostream>
#include <string>
using namespace std;


class Account 
{
public:
    unsigned int accountNumber;
    string firstName;
    string lastName;
    double balance;


    Account(unsigned int accNum, string first, string last, double bal)
        : accountNumber(accNum), firstName(first), lastName(last), balance(bal) {}
};

int main() 
{

    unsigned int studentCounter = 0;

    double initialBalance = 1000.0;

    Account myAccount = {123456, "John", "Doe", 1000.0};

    cout << "Account Number: " << myAccount.accountNumber;
    cout << "\nFirst Name: " << myAccount.firstName;
    cout << "\nLast Name: " << myAccount.lastName;
    cout << "\nBalance: " << myAccount.balance;
    cout << "\n初始化成功！";
    return 0;
}