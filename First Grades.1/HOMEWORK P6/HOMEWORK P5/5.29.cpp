#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    const double principal = 24; 
    const int years = 387;
    double interestRate = 0.05;
    double amount = principal;

    for (int rate = 5; rate <= 10; rate += 5) 
    {
        interestRate = rate / 100.0;
        for (int year = 0; year < years; year++) 
        {
            amount += amount * interestRate;
        }
        cout << "利率为 " << rate << "% 时，" << years << " 年后的金额为: $" << fixed << setprecision(2) << amount;
        amount = principal;
    }
    return 0;
}