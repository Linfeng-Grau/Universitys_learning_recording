//重载（函数重载/运算符重载）
//下列是重载函数的示例

#include <iostream>
using namespace std;

// 函数重载示例1：参数数量不同
void print(int value) 
{
    cout << "The integer value is: " << value << endl;
}

void print(double value) 
{
    cout << "The double value is: " << value << endl;
}

void print(const char* value) 
{
    cout << "The string value is: " << value << endl;
}

// 函数重载示例2：参数类型不同
void display(int value) 
{
    cout << "Displaying integer: " << value << endl;
}

void display(double value) 
{
    cout << "Displaying double: " << value << endl;
}

// 函数重载示例3：参数顺序不同
void show(int a, double b) 
{
    cout << "show(int, double): a = " << a << ", b = " << b << endl;
}

void show(double a, int b) 
{
    cout << "show(double, int): a = " << a << ", b = " << b << endl;
}

int main() 
{
    print(42);          // 调用print(int)
    print(3.14);        // 调用print(double)
    print("Hello");     // 调用print(const char*)

    display(100);       // 调用display(int)
    display(3.14);      // 调用display(double)

    show(10, 20.5);     // 调用show(int, double)
    show(20.5, 10);     // 调用show(double, int)

    return 0;
}
//仅返回类型不同是不足以区分重载函数的。
//例如，int add(int, int)和double add(int, int)是无效的重载。

//默认参数不会影响函数的重载。
//例如，void func(int)和void func(int = 0)是相同的函数，不是重载