//派生类的拷贝构造函数示例：

#include <iostream>
using namespace std;

class base
{
    protected:
    int base1;
    
    public:
    base(int bv):base1(bv)
    {
        cout<<"basevar called"<<endl;
    }
    base(const base& obj):base1(obj.base1)
    {
        cout<<"basevar(copy obj) called"<<endl;
    }
};


class deri:public base
{
    private:
    int deri1;

    public:
    deri(int bv,int dv):base(bv),deri1(dv)
    {
        cout<<"deri called"<<endl;
    }
    deri(const deri& obj2):base(obj2)
    {
        deri1=obj2.deri1;
        cout<<"deri(copy) called"<<endl;
    }

    void display() const
    {
        cout<<"Base var:"<<base1<<endl;
        cout<<"Deri var:"<<deri1<<endl;
    }
};

int main()
{
    deri d1(10,20);
    deri d2(d1);

    cout<<"d1:"<<endl;
    d1.display();
    cout<<"d2:"<<endl;
    d2.display();
}