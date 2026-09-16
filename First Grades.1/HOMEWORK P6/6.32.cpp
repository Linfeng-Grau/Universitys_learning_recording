#include<iostream>
using namespace std;

enum class QP
{
    four,three,two,one
};

void qualityPoints(QP grade)
{
    switch(grade)
    {
        case QP::four:
            cout<<"绩点为4";
            break;
        case QP::three:
            cout<<"绩点为3";
            break;
        case QP::two:
            cout<<"绩点为2";
            break;
        case QP::one:
            cout<<"绩点为1";
            break;
    }
}

int main()
{
    double grade;
    cout<<"欢迎使用简易成绩查询器！\n请输入您的成绩(百分制):";
    
    while(1)
    {
    cin>>grade;
    if(grade>=90&&grade<=100)
    {
        qualityPoints(QP::four);
        break;
    }
    else if(grade>=80&&grade<90)
    {
        qualityPoints(QP::three);
        break;
    }
    else if(grade>=70&&grade<80)
    {
        qualityPoints(QP::two);
        break;
    }
    else if(grade>=60&&grade<70)
    {
        qualityPoints(QP::one);
        break;
    }
    else if(grade<60&&grade>=0)
    {
        cout<<"0";
        break;
    }
    else if(grade>100||grade<0)
    {
        cout<<"你输入的成绩是啥？？？给我重新输入!\n";
    }
    }
    cout<<"\n查询完毕\n按ENTER键退出...";
    cin.get();cin.get();
}
