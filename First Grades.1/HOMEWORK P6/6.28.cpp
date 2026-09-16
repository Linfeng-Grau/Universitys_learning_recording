#include <iostream>
#include <vector>
using namespace std;


vector<int> findFactors(int number) 
{
    vector<int> factors;
    for (int i = 1; i <= number / 2; ++i) 
    { 
        if (number % i == 0) 
        {
            factors.push_back(i);
        }
    }
    return factors;
}

bool isPerfectNumber(int number) 
{
    vector<int> factors = findFactors(number);
    int sum = 0;
    for (int factor : factors) 
    {
        sum += factor;
    }
    return sum == number;
}

int main() 
{
    cout << "1到1000的完数:\n" ;
    for (int i = 1; i <= 1000; ++i) 
    {
        if (isPerfectNumber(i)) 
        {
            cout << i << "是完数，因子为";
            vector<int> factors = findFactors(i);
            for (size_t j = 0; j < factors.size(); ++j) 
            {
                cout << factors[j];
                if (j < factors.size() - 1) 
                {
                    cout << ",";
                }
                
            }
            cout << "\n";
        }
    }
    return 0;
}