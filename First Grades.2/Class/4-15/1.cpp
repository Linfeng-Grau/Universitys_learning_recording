//面向对象的编程：继承？  
//基类 和 派生类 
//public,protested（保护）,private三种成员
//public，protected，private三种继承。

//父类（基类）与子类（派生类）的演示：
#include <iostream>
using namespace std;

// 父类（基类）
class A
{
    public:
    void printA()
    {
        cout<<"A"<<endl;
    }
};

//子类（派生类）
class B:public A//<-----
{
    public:
    void printB()  //子类自己的独立函数
    {
        cout<<"B"<<endl;
    }
};

int main()
{
    B B;
    A A;
    B.printA();
    B.printB();

    
    A.printA();
}
