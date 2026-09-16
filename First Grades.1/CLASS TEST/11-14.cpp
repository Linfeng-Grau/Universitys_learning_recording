#include <iostream>
using namespace std;

int fibonacci(int n) 
{
    if (n <= 1)  // 递归终止条件
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);  // 递归调用
}

int main() 
{
    int position;
    cin>>position;
    cout << "Fibonacci of " << position << " is " << fibonacci(position) << endl;
    return 0;
}