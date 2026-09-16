//重载 的 运算符重载？
//运算符重载就是在一个类中重新定义一个符号的运算规则，使其更容易计算。而定义的运算符只能对那个类使用。

#include <iostream>
using namespace std;

class Complex 
{
private:
    double real;
    double imag;

public:
    // 构造函数
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    // 重载+运算符
    Complex operator + (const Complex& other) const 
    {
        return Complex(real + other.real, imag + other.imag);
    }

    // 打印复数
    void print() const 
    {
        cout << "(" << real << ", " << imag << "i)" << endl;
    }
};

int main() {
    Complex c1(3.0, 4.0);
    Complex c2(1.0, 2.0);
    Complex c3 = c1 + c2; // 使用重载的+运算符

    c1.print(); // 输出 (3, 4i)
    c2.print(); // 输出 (1, 2i)
    c3.print(); // 输出 (4, 6i)

    return 0;
}

//运算符重载函数也可以使用friend语句在类外定义。
//重载运算符不会改变其优先级和结合性。
//不能重载所有运算符，有些运算符（如  .  ::  .*   ?:和sizeof等）不能被重载。
//必须至少有一个操作数是用户定义的类型：
//运算符重载必须涉及至少一个用户定义的类型（如类或结构体）。