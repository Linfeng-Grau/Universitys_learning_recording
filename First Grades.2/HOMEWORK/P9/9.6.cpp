#include <iostream>
using namespace std;

//计算最大公约数
int gcd(int a, int b) 
{
    while (b != 0) 
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//简化分数的函数
void sm(int& N, int& D) 
{
    int cd = gcd(N, D);
    N /= cd;
    D /= cd;
}

class rat
{
    private:
       int N;
       int D;
    public:
       rat(int N=0,int D=1):N(N),D(D){}
       rat operator +(const rat& other)
       {
           return rat(N*other.D+other.N*D,D*other.D);
       }
       rat operator -(const rat& other)
       {
           return rat(N*other.D-other.N*D,D*other.D);
       }
       rat operator *(const rat& other)
       {
           return rat(N*other.N,D*other.D);
       }
       rat operator /(const rat& other)
       {
           return rat(N*other.D,D*other.N);
       }
    
    void point()
    {
        sm(N,D);
        cout<<N<<"/"<<D<<endl;
    }
};

int main() 
{
    int N1,D1,N2,D2;
    cout<<"请输入第一个分数: ";
    cin>>N1>>D1;
    cout<<"请输入第二个分数: ";
    cin>>N2>>D2;
    if (D1==0||D2==0) 
    {
        cout<<"错误: 分母不能为零."<< endl;
        return 1;
    }

    rat a(N1,D1);
    rat b(N2,D2);
    rat x=a+b;
    rat y=a-b;
    rat z=a*b;
    rat k=a/b;

    cout<<"加:"<<endl;
    x.point();
    cout<<"减:"<<endl;
    y.point();
    cout<<"乘:"<<endl;
    z.point();
    cout<<"除:"<<endl;
    k.point();
    
    return 0;
}