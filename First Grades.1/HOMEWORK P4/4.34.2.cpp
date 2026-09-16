#include <iostream>
#include <iomanip>
using namespace std;

double FT(int n) 
{
    double result = 1;
    for (int i = 1; i <= n; ++i) 
    {
        result *= i;
    }
    return result;
}

double CE(int terms) 
{
    double e = 1.0;
    double term = 1.0;

    for (int i = 1; i < terms; ++i) 
    {
        term /= i;
        e += term;
    }

    return e;
}

int main() 
{
    int terms;
    cout << "请输入用于近似e的项数：";
    cin >> terms;

    if (terms <= 0) 
    {
        cout << "项数必须大于0。" << endl;
        return 1;
    }

    double e = CE(terms);
    cout << fixed << setprecision(10) << "e的近似值为：" << e << endl;

    return 0;
}
