//this语句
//3.传递当前对象的地址

#include <iostream>
using namespace std;

class MyClass 
{
private:
    int value; // 私有成员变量

public:
    // 构造函数
    MyClass(int value):value(value) {}

    // 定义一个非成员函数，用于打印对象的值
    friend void printValue(const MyClass& obj);

    // 定义一个成员函数，用于传递当前对象的地址
    void passToFunction() 
    {
        printValue(*this); // 传递当前对象的引用
    }

    // 显示成员变量的值
    void show() const 
    {
        cout << "The value is: " << value << endl;
    }
};

// 非成员函数，用于打印对象的值
void printValue(const MyClass& obj) 
{
    cout << "The value from printValue(函数) is: " <<obj.value<< endl;
}

int main() 
{
    MyClass obj(42); // 创建对象，传入参数42
    obj.passToFunction(); // 调用成员函数，传递当前对象的地址
    obj.show();// 调用show函数，输出成员变量的值
    return 0;
}