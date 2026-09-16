//继承方式：public，protected，private

#include <iostream>
using namespace std;

// 基类
class Base 
{
public:
    int public1; // 公有成员

protected:
    int protect; // 保护成员

private:
    int private1; // 私有成员

public:
    Base() : public1(10), protect(20), private1(30) {}

    void displayPrivate() 
    {
        cout << "Private: " << private1 << endl;
    }
};

// 公有继承
class PublicDerived : public Base 
{
public:
    void display() 
    {
        cout << "Public: " << public1 << endl; // 可以访问
        cout << "Protected: " << protect << endl; // 可以访问
        // cout << privateVar << endl; // 错误：私有成员不可访问
    }
};

// 保护继承
class ProtectedDerived : protected Base 
{
public:
    void display() {
        cout << "Public: " << public1 << endl; // 可以访问
        cout << "Protected: " << protect << endl; // 可以访问
        // cout << privateVar << endl; // 错误：私有成员不可访问
    }
};

// 私有继承
class PrivateDerived : private Base 
{
public:
    void display() 
    {
        cout << "Public: " << public1 << endl; // 可以访问
        cout << "Protected: " << protect << endl; // 可以访问
        // cout << privateVar << endl; // 错误：私有成员不可访问
    }
};

int main() 
{
    PublicDerived pub;
    ProtectedDerived prot;
    PrivateDerived priv;

    cout << "PublicDerived:" << endl;
    pub.display(); // 可以访问公有和保护成员
    cout << "Public: " << pub.public1 << endl; // 可以直接访问

    cout << "\nProtectedDerived:" << endl;
    prot.display(); // 可以访问公有和保护成员
    // cout << "Public: " << prot.publicVar << endl; // 错误：保护继承后基类的公有成员变为保护成员

    cout << "\nPrivateDerived:" << endl;
    priv.display(); // 可以访问公有和保护成员
    // cout << "Public: " << priv.publicVar << endl; // 错误：私有继承后变为私有成员

    return 0;
}