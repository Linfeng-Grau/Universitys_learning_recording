#include <iostream>
using namespace std ;


int main()
{
    int confirm;
    double YSR,YNSE,ZXKC,NS,YSHSR,YF;
    YSR=YNSE=ZXKC=NS=YSHSR=YF=0;

    while(1)
    {
        cout<<"\n----------------\n"<<"1  预扣纳税方案\n"<<"2  累计预扣方案\n按其他任意键退出\n"<<"----------------\n";
        cin>>confirm;

        if(confirm!=1&&confirm!=2)
        {
        cout<<"系统已退出";
        break;   
        }
        else
        {
            if (confirm==1)
            {
                #include "YUKOU.cpp"

                cout<<"本月收入总额:"<<YSR<<"元\n专项扣除费用总额:"<<ZXKC;
                cout<<"元\n您本月缴纳个人所得税:"<<NS<<"元\n您的扣除和税后收入:"<<YSHSR<<"元\n\n感谢依法纳税,谢谢使用!";
            }
            else
            {
                #include "LEIKOU.cpp"
            }
        }
    }

    return 0;
}
