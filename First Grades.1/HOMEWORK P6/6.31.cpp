#include <iostream>
using namespace std;

int gcd(int a, int b) 
{
    while (b!=0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() 
{
    int num1, num2;
    cout << "请输入两个数以求他们的最大公约数:";
    cin >> num1 >> num2;

    int result = gcd(num1, num2);
    cout << "他们的最大公约数为"<<result;
    return 0;
}