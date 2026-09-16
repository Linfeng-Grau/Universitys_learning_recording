#include <iostream>
using namespace std;

int main()
{
    double KG,M,BMI;

    cout<<"请输入您的体重(KG):";
    cin>>KG;
    cout<<"请输入您的身高(M):";
    cin>>M;

    BMI=KG/(M*M);
    cout<<"您的BMI="<<BMI;
    
    cin.get();
    cout<<"\n点击Enter键查询BMI值具体情况";
    cin.get();
    
    cout<<"BMI情况为";
    if (BMI<18.5)
    {
        cout<<"偏瘦";
    }
    else
    {
        if (18.5<BMI<24.9)
        {
            cout<<"正常";
        }
        else
        {
            if (25<BMI<29.9)
            {
            cout<<"偏重";   
            }
            else
            {
                if (30<BMI)
                cout<<"超重";
            }
        }
    }
    
    return 0;
}

