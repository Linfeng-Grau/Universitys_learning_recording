#include <iostream>
using namespace std;

int main() 
{
    int num;
    cout << "请输入一个非负整数：";
    cin >> num;

    if (num < 0) 
    {
        cout << "输入错误，请输入一个非负整数。" << endl;
        return 1;
    }

    unsigned long long A = 1;
    int i = num;

    while (i > 0) 
    {
        A *= i;
        --i;
    }

    cout << num << "的阶乘是：" << A << endl;

    return 0;
}