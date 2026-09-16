//初始化列表（Initialization List）是构造函数中用于初始化成员变量的一种机制。它位于构造函数参数列表之后、函数体之前，使用冒号（:）和一系列初始化表达式来初始化成员变量
//example:
#include <iostream>
using namespace std;

class MyClass 
{
private:
    const int value;
    int count;
    string name;
public:
    MyClass(int val, int cnt, const string& n): value(val), count(cnt), name(n)   // 初始化列表
    {
        cout << "构造函数:value = " << value << ", count = " << count << ", name = " << name << endl;
    }
};