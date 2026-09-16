#include <iostream>
using namespace std;

class Account 
{
protected:
    double balance;

public:
    Account(double initialBalance) 
    {
        if (initialBalance < 0) 
        {
            cout << "Invalid initial balance. Setting balance to 0." << endl;
            balance = 0;
        } 
        else 
        {
            balance = initialBalance;
        }
    }

     void credit(double amount) 
    {
        if (amount > 0) 
        {
            balance += amount;
        } 
        else 
        {
            cout << "Invalid credit amount." << endl;
        }
    }

    bool debit(double amount) 
    {
        if (amount > balance) 
        {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        } 
        else 
        {
            balance -= amount;
            return true;
        }
    }

    double getBalance() const 
    {
        return balance;
    }
};

class SavingsAccount : public Account 
{
protected:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}

    double calculateInterest() 
    {
        return balance * (interestRate / 100);
    }
};

class CheckingAccount : public Account 
{
protected:
    double transactionFee;

public:
    CheckingAccount(double initialBalance, double fee)
        : Account(initialBalance), transactionFee(fee) {}

    void credit(double amount)
    {
        if (amount > 0) 
        {
            Account::credit(amount);
            Account::debit(transactionFee);
        } 
        else 
        {
            cout << "Invalid credit amount." << endl;
        }
    }

    void debit(double amount)
    {
        if (amount > 0 && Account::debit(amount)) 
        { 
            Account::debit(transactionFee);
        } 
        else 
        {
            cout << "Invalid debit amount or insufficient balance." << endl;
        }
    }
};

int main() 
{
    Account account(1000);
    //测试
    cout << "Account balance: $" << account.getBalance() << endl;
    account.credit(500);
    cout << "After credit: $" << account.getBalance() << endl;
    account.debit(200);
    cout << "After debit: $" << account.getBalance() << endl;
    account.debit(2000); 
    cout << "Final Account balance: $" << account.getBalance() << endl;

    SavingsAccount savings(500, 5);
    cout << "\nSavings Account balance: $" << savings.getBalance() << endl;
    double interest = savings.calculateInterest();
    cout << "Interest earned: $" << interest << endl;
    savings.credit(interest);
    cout << "After adding interest: $" << savings.getBalance() << endl;

    CheckingAccount checking(1000, 5);
    cout << "\nChecking Account balance: $" << checking.getBalance() << endl;
    checking.credit(200);
    cout << "After credit: $" << checking.getBalance() << endl;
    checking.debit(100);
    cout << "After debit: $" << checking.getBalance() << endl;
    checking.debit(1500);
    cout << "Final Checking Account balance: $" << checking.getBalance() << endl;

    return 0;
}