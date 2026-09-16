
// 运算符重载类别：成员函数内重载 / 友元函数类外重载
// 运算符重载的应用方式场景：
//1.输入/输出运算流(必须使用友元函数)  2.复合赋值运算符(通常用成员函数)  3.比较运算符(推荐友元函数)  
//4.单目运算符  5.必须用成员函数的运算符 6. 类型转换运算符(必须成员函数)
 

#include <iostream>
using namespace std;//成员函数类内重载

class Complex 
{
private:
    double real, imag;
public:
    Complex(double r=0,double i=0):real(r),imag(i){}
    Complex operator + (const Complex& right)//有一元默认定义（在类内） 
    { // 成员函数重载+
        return Complex(real + right.real, imag + right.imag);
    }
    void point()
    {
        cout<<real<<","<<imag;
    }
};

int main()
{
    Complex a(1,2);
    Complex b(2,4);
    Complex c = a + b;  // 等价于 c = a.operator+(b)
    c.point();
}
