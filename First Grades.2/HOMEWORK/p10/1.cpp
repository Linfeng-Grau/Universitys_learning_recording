#include <iostream>
using namespace std;

class Complex 
{
private:
    double real; 
    double imag; 

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

    friend istream& operator>>(istream& in, Complex& c) 
    {
        cout << "请输入实部: ";
        in >> c.real;
        cout << "请输入虚部: ";
        in >> c.imag;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Complex& c) 
    {
        out << "(" << c.real;
        if (c.imag >= 0)
            out << "+";
        out << c.imag << "i)";
        return out;
    }

    Complex operator*(const Complex& rhs) const 
    {
        return Complex(real * rhs.real - imag * rhs.imag, real * rhs.imag + imag * rhs.real);
    }

    bool operator==(const Complex& rhs) const 
    {
        return (real == rhs.real) && (imag == rhs.imag);
    }

    bool operator!=(const Complex& rhs) const 
    {
        return !(*this == rhs);
    }
};

int main() 
{
    Complex c1, c2, c3;

    cout << "请输入第一个复数:" << endl;
    cin >> c1;
    cout << "请输入第二个复数:" << endl;
    cin >> c2;

    cout << "第一个复数为: " << c1 << endl;
    cout << "第二个复数为: " << c2 << endl;

    c3 = c1 * c2;
    cout << "两个复数相乘的结果为: " << c3 << endl;

    if (c1 == c2)
    {
        cout << "两个复数相等" << endl;
    }   
    else
    {
        cout << "两个复数不相等" << endl;

    }
    return 0;
}