#include <iostream>
using namespace std;

int main()
{
    int num,rnum,d;
    d=0;

    cout<<"请输入一个五位数：";
    cin>>num;

    if(num<10000||num>99999)
    {
        cout<<"输入非法";
        return 1;
    }

    for (int i = 0; i < 5; ++i)
    {
        d=num%10;
        rnum=rnum*10+d;
        num/=10;
    }

    if(num==rnum)
    {
        cout<<"是回文数";
    }
    else
    {
        cout<<"不是回文数";
    }

    return 0;
}