//虚析构函数

#include <iostream>
using namespace std;

class base
{
    public:
    virtual ~base()
    {
        cout<<"destory base"<<endl;
    }
};

class derived1:public base  //未覆盖虚析构函数
{
    public:
};

class derived2:public base  //覆盖虚析构函数
{
    public:
    ~derived2 () override //override可自由添减  
    {
        cout<<"destory derived2"<<endl;
    }
};

int main()
{
    base* ptr1=new derived1();
    base* ptr2=new derived2();
    
    delete ptr1;
    cout<<"-------------"<<endl;
    delete ptr2;   //先调用derived2的析构函数再调用base的析构函数,所有析构函数均会调用

    return 0;
}