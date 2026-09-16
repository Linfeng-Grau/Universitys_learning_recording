#include <iostream>
#include <string>
using namespace std;

class CAT
{
private:
    string color;
    int age;
    double weight;

public:
    void setcatcolor(const string& newcolor)
    {
        color=newcolor;
    }
    void setcatweight(double newweight)
    {
        if(newweight>0)
        {
            weight=newweight;
        }
        else
        {
            cout<<"ERROR!";
        }
    }
    void setcatage(int newage)
    {
        if(newage>0)
        {
            age=newage;
        }
        else
        {
            cout<<"ERROR!";
        }
    }

    void display() const
    {
        cout<<"猫的信息:\n"<<"颜色:"<<color<<"\n体重:"<<weight<<"千克\n年龄:"<<age<<"岁";
    }    
};

int main()
{
    double weight;
    int age;
    string color;

    CAT mycat;
    cout<<"请输入猫的相关信息\n";
    cout<<"猫的颜色:";
    cin>>color;
    cout<<"猫的体重(保留一位小数):";
    cin>>weight;
    cout<<"猫的年龄:";
    cin>>age;

    mycat.setcatcolor(color);
    mycat.setcatweight(weight);
    mycat.setcatage(age);

    mycat.display();

    return 0;
}