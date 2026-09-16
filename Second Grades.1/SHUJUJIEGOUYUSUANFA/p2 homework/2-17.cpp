#include <iostream>
#include <string>
#include <stack>
using namespace std;

string convert(int num, int k) 
{
    //处理不合法
    if (k <= 1 || k > 36) 
    {
        return "";
    }
    
    if (num == 0) 
    {
        return "0";
    }
    
    //负数
    bool isNegative = false;
    if (num < 0) {
        isNegative = true;
        num = -num;
    }
    
    stack<char> s;
    
    //进制转换
    while (num > 0) 
    {
        int remainder = num % k;
        char digit;
        
        if (remainder < 10) 
        {
            digit = '0' + remainder;
        } 
        else 
        {
            digit = 'A' + (remainder - 10);
        }
        
        s.push(digit);
        num = num / k;
    }
    
    string result = "";
    if (isNegative) 
    {
        result += "-";
    }
    
    while (!s.empty()) 
    {
        result += s.top();
        s.pop();
    }
    
    return result;
}

int main() 
{
    //例
    int testNum1 = 10, base1 = 2;
    int testNum2 = 255, base2 = 16;
    int testNum3 = 100, base3 = 8;
    int testNum4 = 0, base4 = 2;
    int testNum5 = -10, base5 = 2;
    int testNum6 = 123, base6 = 36;
    
    cout << "测试进制转换函数:" << endl;
    cout << "十进制 " << testNum1 << " 转换为 " << base1 << " 进制: " << convert(testNum1, base1) << endl;
    cout << "十进制 " << testNum2 << " 转换为 " << base2 << " 进制: " << convert(testNum2, base2) << endl;
    cout << "十进制 " << testNum3 << " 转换为 " << base3 << " 进制: " << convert(testNum3, base3) << endl;
    cout << "十进制 " << testNum4 << " 转换为 " << base4 << " 进制: " << convert(testNum4, base4) << endl;
    cout << "十进制 " << testNum5 << " 转换为 " << base5 << " 进制: " << convert(testNum5, base5) << endl;
    cout << "十进制 " << testNum6 << " 转换为 " << base6 << " 进制: " << convert(testNum6, base6) << endl;
    
    //输入测试
    cout << "\n请输入一个十进制数和目标进制:";
    int InputNum, InputBase;
    cin >> InputNum >> InputBase;
    cout << "十进制 " << InputNum << " 转换为 " << InputBase << " 进制 "
    << "\n答案是:" << convert(InputNum, InputBase) << endl;
    
    return 0;
}
