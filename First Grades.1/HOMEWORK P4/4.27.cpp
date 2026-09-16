#include <iostream>
#include <string>
using namespace std;

int main() 
{
    string binaryNumber;
    cout << "请输入一个仅由0和1构成的整数：";
    cin >> binaryNumber;

    
    for (char digit : binaryNumber) 
    {
        if (digit != '0' && digit != '1') 
        {
            cout << "输入错误，请输入仅由0和1构成的整数。";
            return 1;
        }
    }

    int decimalNumber = 0;
    int base = 1;

    
    for (int i = binaryNumber.length() - 1; i >= 0; --i) 
    {
        if (binaryNumber[i] == '1') 
        {
            decimalNumber += base;
        }
        base *= 2; 
    }

    cout << "对应的十进制整数为：" << decimalNumber;

    return 0;
}