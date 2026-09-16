#include <iostream>
#include <vector>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double initialBalance) {
        if (initialBalance < 0) {
            cout << "Invalid initial balance. Setting balance to 0." << endl;
            balance = 0;
        } else {
            balance = initialBalance;
        }
    }

    //存钱
    virtual void credit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid credit amount." << endl;
        }
    }

    //取钱
    virtual bool debit(double amount) {
        if (amount > balance) {
            cout << "Debit amount exceeded account balance." << endl;
            return false;
        } else {
            balance -= amount;
            return true;
        }
    }

    //余额
    double getBalance() const {
        return balance;
    }
};

//派生类SavingsAccount
class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(double initialBalance, double rate)
        : Account(initialBalance), interestRate(rate) {}

    //利息
    double calculateInterest() {
        return balance * (interestRate / 100);
    }
};

//派生类CheckingAccount
class CheckingAccount : public Account {
protected:
    double transactionFee;

public:
    CheckingAccount(double initialBalance, double fee)
        : Account(initialBalance), transactionFee(fee) {}

    void credit(double amount) override {
        if (amount > 0) {
            Account::credit(amount);
            Account::debit(transactionFee);
        } else {
            cout << "Invalid credit amount." << endl;
        }
    }

    bool debit(double amount) override {
        if (amount > 0 && Account::debit(amount)) {
            Account::debit(transactionFee);
        } else {
            cout << "Invalid debit amount or insufficient balance." << endl;
        }
    }
};


int main() 
{
    vector<Account*> accounts;

    accounts.push_back(new SavingsAccount(500, 5));
    accounts.push_back(new CheckingAccount(1000, 5));


    for (Account* account : accounts) {
        cout << "Processing account with balance $" << account->getBalance() << endl;
        double creditAmount, debitAmount;
        cout << "Enter amount to credit: ";
        cin >> creditAmount;
        account->credit(creditAmount);

        cout << "Enter amount to debit: ";
        cin >> debitAmount;
        account->debit(debitAmount);

        SavingsAccount* savings = dynamic_cast<SavingsAccount*>(account);
        if (savings) {
            double interest = savings->calculateInterest();
            cout << "Interest earned: $" << interest << endl;
            account->credit(interest);
        }

        cout << "Updated balance: $" << account->getBalance() << endl << endl;
    }

    for (Account* account : accounts) {
        delete account;
    }

    return 0;
}