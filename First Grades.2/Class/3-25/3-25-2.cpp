//this语句 this就相当于一个指向类的由系统自主设定的默认指针
//1.区分同名变量

#include <iostream>
using namespace std;

class MyClass 
{
private:
    int value;
public:
    // 构造函数
    MyClass(int value) 
    {
        this->value = value; // 使用this指针区分同名变量,使此函数的局部value传入成员变量（即private中的）value,使show()能调用
    }

    void show() const 
    {
        cout << "The value is: " << value << endl;//这个value就是private中的value，等于this->value.
        cout << this->value;
    }
};
//相当于private中为value1，函数中为this->value1=value2，show()中的是value1和this->value1

int main() 
{
    MyClass obj(42);
    obj.show();
    return 0;
}