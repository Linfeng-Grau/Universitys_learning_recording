//友元类

#include <iostream>
using namespace std;

// 声明类A
class A 
{
private:
    int secret; // 私有成员变量

public:
    // 构造函数
    A(int value) : secret(value) {}

    //声明友元类B
    friend class B;
};

//定义友元类B
class B 
{
public:
    void displaySecret(const A& obj) 
    {
        cout << "A类中的私有的值为" << obj.secret << endl;
    }
};

int main() 
{ 
    // 创建类A的对象
    A objA(88);

    // 创建类B的对象
    B objB;

    // 通过类B的对象访问类A的私有成员
    objB.displaySecret(objA);

    return 0;
}