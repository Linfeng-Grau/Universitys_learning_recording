#include <iostream>
using namespace std;

int main()
{
    double x,y;
    cout<<"请输入x的值:";
    cin>>x;

    if (x>=0)
    {
        y=x;
    }
    else
    {
        y=-x;
    }
    cout<<"Y="<<y<<endl;
    cout<<"计算完毕";
    return 0;
}     