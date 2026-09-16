#include <iostream>
using namespace std;
#define LOG(x) cout<<x

void Increment(int& x)
{
    x++;
}

int main()
{
    //引用
    int a=5;
    int& ref=a;//ref和a是同一个变量，ref的值改变，a的值也改变。但注意：ref实际不是一个新的变量，ref只是a的一个别名。 
    ref=6;
    LOG(a)<<" ref\n";

    //引用作为函数参数
    a=7;
    Increment(a);
    LOG(a)<<" Increment\n";
    
    //两个引用指向同一个变量时
    a=9;
    int b=6;
    int& reff= a;
    reff=b;//此时是将b赋值给a，而不是将b赋值给reff。
    LOG(reff)<<" reff\n";

    //正确做法
    a=9;
    b=6;
    int* refff=&a; //用指针来实现a和b的值的改变。
    *refff=8;
    refff=&b;
    *refff=5;
    LOG(a)<<" a\n";
    LOG(b)<<" b\n";

    return 0;
}

//引用