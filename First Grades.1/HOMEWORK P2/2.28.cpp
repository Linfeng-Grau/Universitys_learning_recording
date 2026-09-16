#include <iostream>
using namespace std;

int main()
{
    int num;
    cout<<"请输入一个五位数：";
    cin>>num;

    if (num<10000||num>99999)
    {
        cout<<"输入的不是五位数！";
        return 0;
    }
    
    int a=num/10000;
    int b=(num%10000)/1000;
    int c=(num%1000)/100;
    int d=(num%100)/10;
    int e=(num%10);

    cout<<a<<"   "<<b<<"   "<<c<<"   "<<d<<"   "<<e;

    return 0;
}