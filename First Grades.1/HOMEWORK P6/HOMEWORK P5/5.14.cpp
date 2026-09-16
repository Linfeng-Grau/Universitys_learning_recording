#include <iostream>
using namespace std;

void log(double a,int b)
{
    cout<<"零售额为"<<a*b;
}

int main()
{   
    double dollar;
    int type,num;

    cout<<"请输入产品编号:";
    cin>>type;
    cout<<"请输入销售量:";
    cin>>num;

    switch (type)
    {
        case 1:
        {
            dollar=2.98;
            log(dollar,num);
            break;
        }
        case 2:
        {
            dollar=4.50;
            log(dollar,num);
            break;
        }
        case 3:
        {
            dollar=9.98;
            log(dollar,num);
            break;
        }
        case 4:
        {
            dollar=4.49;
            log(dollar,num);
            break;
        }
        case 5:
        {
            dollar=6.87;
            log(dollar,num);
            break;
        }
    default:
        break;
    }
}