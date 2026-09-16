#include <iostream>
using namespace std;//友元函数符号重载 

class Complex1 
{
private:
    double real;
    double imag;

public:
    Complex1(double r=0,double i=0):real(r),imag(i){}
    friend Complex1 operator + (const Complex1& left, const Complex1& right);//每一个元都需定义
    
    void point()
    {
        cout<<real<<","<<imag;
    }
};

Complex1 operator+(const Complex1& left, const Complex1& right) 
{
    return Complex1(left.real + right.real, left.imag + right.imag);
}

int main()
{
    Complex1 a(1,2);
    Complex1 b(3,6);
    Complex1 c=a+b;
    c.point();
}
