//派生类的protected（保护）和private（私有）成员之间区别

#include <iostream>
using namespace std;

// 基类
class Base 
{
protected:
    int protect; // 保护成员

private:
    int private1;  // 私有成员

public:
    Base(int a=10,int b=20) : protect(a), private1(b) {}

    void displayProtected() 
    {
        cout << "Protected variable: " << protect << endl;
    }

    void displayPrivate() 
    {
        cout << "Private variable: " << private1 << endl;
    }
};

// 派生类
class Derived : public Base 
{
public:
    void displayProtected() 
    {
        cout << "Protected variable (from Derived): " << protect << endl; // 可以访问保护成员
    }

    // 不能直接访问私有成员,所以有错误示范 
    // void displayPrivate() 
    // {
    //     cout << "Private variable (from Derived): " << private1 << endl;   // 错误：私有成员不可访问
    // }
};

int main() 
{
    Base base;
    Derived derived;

    base.displayProtected(); // 输出：Protected 10
    base.displayPrivate();   // 输出：Private1 20

    derived.displayProtected(); // 输出：Protected 10

    // 以下代码会报错，因为保护成员和私有成员不能被类外部直接访问
    // cout << base.protectedVar << endl; // 错误：保护成员不可直接访问
    // cout << base.privateVar << endl;   // 错误：私有成员不可直接访问

    return 0;
}