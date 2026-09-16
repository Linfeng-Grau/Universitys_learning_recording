//虚函数例子

#include <iostream>
using namespace std;

class base
{
    public:
    virtual void disploy()
    {
        cout<<"base disploy"<<endl;
    }
};

class drived1:public base  //未对基类虚函数进行更改，则派生类将自动继承
{
    public:
};

class drived2:public drived1   //drived1继承了基类的虚函数，则可以通过drived1覆盖虚函数
{
    public:
    void disploy() override   //override只是一个显式标记，可以省去
    {
        cout<<"NOT base disploy,but drived2 disploy."<<endl;
    }
};

int main()
{
    base baseobj;
    drived1 drived1obj;
    drived2 drived2obj;

    base* baseptr = &baseobj;
    baseptr->disploy();

    baseptr =&drived1obj;  //输出base disploy
    baseptr->disploy();

    baseptr =&drived2obj;  //覆盖后不再输出base disploy
    baseptr->disploy();    
}