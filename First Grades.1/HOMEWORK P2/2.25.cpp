#include <iostream>
using namespace std;

int main()
{
    int a,b,c;

    cout<<"请输入被除数（以下均为整数！）\n"<<"a=";
    cin>>a;
    cout<<"请输入除数\n"<<"b=";
    cin>>b;

    c=a%b;

    if (c==0)
    {
        cout<<"a是b的倍数";
    }
    else
    {
        cout<<"a不是b的倍数";
    }

    return 0; 
}