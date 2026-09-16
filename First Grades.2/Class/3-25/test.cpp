#include <iostream>
using namespace std;

class W
{
    private:
        double A;
        double B;
    
    public:
        W(double a=0.0,double b=0.0):A(a),B(b){};

        W operator * (const W& other)const
        {
            return W((A+other.A)/2,(B+other.B)/2);
        }
        
        void point()
        {
            cout<<"两点连线中点为("<<A<<","<<B<<")";
        }
};

int main()
{
    double x1,x2,y1,y2;

    cout<<"请输入第一个点的坐标:\n";
    cin>>x1>>y1;
    cout<<"请输入第二个点的坐标:\n";
    cin>>x2>>y2;

    if(x1==x2&&y1==y2)
    {
        cout<<"两点不能为同一点！";
        return 0;
    }

    W w1(x1,y1);
    W w2(x2,y2);
    W w3=w1*w2;

    w3.point();

    cout<<"\nCOMPLETE!";
    return 0;
}