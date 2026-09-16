#include <iostream>
using namespace std;

int main()
{
    double jb,jx,yb,gj,sb,yf,sds,A;           //赋值
    jb=5660,jx=1800,yb=-300,gj=-700,sb=-200;

    yf=jb+jx+yb+gj+sb;                        //计算程序组
    sds=yf*0.1;                                         
    A=yf-sds;

    cout<<"工号：5201"<<"\n姓名：吉祥"<<"\n基本工资："<<jb<<"\n绩效工资："<<jx<<"\n医保扣除:"<<yb<<"\n公积金扣除"<<gj<<"\n社保扣除："<<sb;
    cout<<"\n应发工资:"<<yf<<"\n个人所得税:"<<sds;    //信息表示
    
    cout<<"\n点击Enter键计算实发工资";
    cin.get();                                //给出实发工资
    cout<<"计算得实发工资："<<A;
    
    return 0;
} 