#include<iostream>
#include<cmath>
using namespace std;

double hypotenuse(double a,double b)
{
    double c;
    c=sqrt(a*a+b*b);
    return c;
}

int main()
{
    cout<<"点击Enter键依次查看斜边的长度。\n";
    cout<<"三角形\t边1\t边2\t斜边";
    cin.get();
    cout<<"1\t3.0\t4.0\t"<<hypotenuse(3.0,4.0);
    cin.get();
    cout<<"2\t5.0\t12.0\t"<<hypotenuse(5.0,12.0);
    cin.get();
    cout<<"3\t8.0\t15.0\t"<<hypotenuse(8.0,15.0);
    
    return 0;
}
