//友元函数?

#include <iostream>
using namespace std;

// 声明类
class MyClass 
{
private:
    int secret; // 私有成员变量

public:
    // 构造函数
    MyClass(int value):secret(value) {}

    // 声明有一个友元函数
    friend void displaySecret(const MyClass& obj);
};

// 定义友元函数
void displaySecret(const MyClass& obj) 
{
    cout << "类的私密成员值为"<<obj.secret<<endl;
}

int main()
{
    int n;
    cin>>n;

    // 创建类对象
    MyClass obj(n);

    // 调用友元函数
    displaySecret(obj);
}