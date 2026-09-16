//子类对象/指针 及 基类对象/指针 四者的关系

#include <iostream>
using namespace std;

class Base 
{
public:
    void show() 
    {
        cout << "Base::show()" << endl;
    }
    virtual void display()  //虚函数待覆盖        ***用虚函数使 基类的指针 能调用 子类的函数
    {
        cout << "Base::display()" << endl;
    }
};

class Derived : public Base 
{
public:
    void show() 
    {
        cout << "Derived::show()" << endl;
    }
    void display() override //<--用于覆盖（取代）掉基类的虚函数disploy（）的字符   覆盖的函数必须要求函数名类型及其可能有的const完全一致
    {
        cout << "Derived::display()" << endl;
    }
};

int main() 
{
    Base baseObj;
    Derived derivedObj;

    Base* basePtr = &baseObj; // 基类指针指向基类对象
    basePtr->show();          // 调用 Base::show()
    basePtr->display();       // 调用 Base::display()

    basePtr = &derivedObj;    // 基类指针指向子类对象
    basePtr->show();          // 调用 Base::show()而非Derived
    basePtr->display();       // 调用 Derived::display()      （多态）

    Derived* derivedPtr = &derivedObj; // 子类指针指向子类对象
    derivedPtr->show();                // 调用 Derived::show()
    derivedPtr->display();             // 调用 Derived::display()

    return 0;
}

//额外：Base baseobj;Base* baseptr=&baseobj; 与 Base* baseptr=new baseobj() 的关系?