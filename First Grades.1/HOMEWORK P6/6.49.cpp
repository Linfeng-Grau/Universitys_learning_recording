#include<iostream>
using namespace std;

int gcd(int x,int y)
{
    if(y==0)
    {
        return x;
    }
    else
    {
        return gcd(y,x%y);
    }
}

int main()
{
    int num1,num2;
    cout<<"请输入两个整数以求他们的最大公约数:";
    cin>>num1>>num2;
    cout<<"最大公约数为"<<gcd(num1,num2);
    return 0;
}    
    