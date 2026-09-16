#include <iostream>
#include <cmath>
using namespace std;

double jia(double a,double b);
double jian(double a,double b);
double cheng(double a,double b);
double chu(double a,double b);
double juedui(int a,int b);
double pingfanggen(int a,int b);
double ezhishu(int a);
double zhishu(int a,int b);
void tuichu();

double jia(double a, double b) 
{
    return a+b;
}

double jian(double a, double b) 
{
    return a-b;
}

double cheng(double a, double b) 
{
    return a*b;
}

double chu(double a, double b) 
{
    if (b!=0)
    {
        return a/b;
    } 
    else 
    {
        cout<<"除数不能为0";
        return 0;
    }
}

double juedui(int a) 
{
    return abs(a);
}

double pingfanggen(int a) 
{
    if (a>=0) 
    {
        return sqrt(a);
    } 
    else 
    {
        cout<<"负数没有实数平方根";
        return 0;
    }
}

double ezhishu(int a) 
{
    return exp(a);
}

double zhishu(int x, int y) 
{
    return pow(x, y);
}

void tuichu() 
{
    cout<<"感谢使用简易计算器，再见！";
    exit(0);
}

int main()
{   
    int confirm;
    double n1,n2;
    int N1,N2;

    while(1)
    {
        cout<<"\n欢迎使用简易计算器！\n"<<"1.加法\n"<<"2.减法\n"<<"3.乘法\n"<<"4.除法\n"<<"5.绝对值\n"<<"6.平方根\n"<<"7.e^x\n"<<"8.x^y\n"<<"9.退出\n";
        cout<<"请选择(1~9):";
        cin>>confirm;

        switch (confirm)
        {
            case 1:
                cout<<"请输入依次两个浮点数:";
                cin>>n1>>n2;
                cout<<"结果是"<<jia(n1,n2);
                break;
            case 2:
                cout<<"请输入依次两个浮点数:";
                cin>>n1>>n2;
                cout<<"结果是"<<jian(n1,n2);
                break;
            case 3:
                cout<<"请输入依次两个浮点数:";
                cin>>n1>>n2;
                cout<<"结果是"<<cheng(n1,n2);
                break;
            case 4:
                cout<<"请输入依次两个浮点数:";
                cin>>n1>>n2;
                cout<<"结果是"<<chu(n1,n2);
                break;
            case 5:
                cout<<"请输入一个整数:";
                cin>>N1;
                cout<<"结果是"<<juedui(N1);
                break;
            case 6:
                cout<<"请输入一个整数:";
                cin>>N1;
                cout<<"结果是"<<pingfanggen(N1);
                break;
            case 7:
                cout<<"请输入一个整数:";
                cin>>N1;
                cout<<"结果是"<<ezhishu(N1);
                break;
            case 8:
                cout<<"请输入两个整数:";
                cin>>N1>>N2;
                cout<<"结果是"<<zhishu(N1,N2);
                break;
            case 9:
                tuichu();
                break;
            default:
                cout<<"输入无效，请重新输入";
                break;
            }
    }
    return 0;
}

