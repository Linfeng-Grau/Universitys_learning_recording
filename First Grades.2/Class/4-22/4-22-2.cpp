#include <iostream>
using namespace std;

// 基类
class Base 
{
public:
    Base() 
    {
        cout << "Base constructor called." << endl;
    }

    virtual ~Base() 
    { // 虚析构函数
        cout << "Base destructor called." << endl;
    }
};

// 派生类
class Derived : public Base 
{
public:
    Derived() 
    {
        cout << "Derived constructor called." << endl;
    }

    ~Derived() 
    { // 派生类的析构函数
        cout << "Derived destructor called." << endl;
    }
};

int main() 
{
    Base* ptr = new Derived();
    delete ptr; // 通过基类指针删除派生类对象
    return 0;
}