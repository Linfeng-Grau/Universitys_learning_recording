//this语句
//2.返回当前对象的引用

#include <iostream>
using namespace std;

class MyClass 
{
private:
    int value;
    
public:
    // 构造函数
    MyClass(int value) : value(value) {}

    // 返回当前对象的引用
    MyClass& increment()// 对当前类的引用更改函数 
    { 
        ++value;      // 更改内容
        return *this; // 返回当前对象的引用,即返回当前对象的引用后更改的内容
    }

    void show() const 
    {
        cout << "The value is: " << value << endl;
    }
};

int main() 
{
    MyClass obj(3);
    obj.increment().increment().increment(); // 链式调用+(1x3)
    obj.show(); // 输出了The value is: 6
    return 0;
}