#include <iostream>
using namespace std;
 
class complex
{
    private:
       double r;
       double i;
    public:
       complex(double r=0,double i=0):r(r),i(i){}
       complex operator + (const complex& other)
       {
            return complex(r+other.r,i+other.i);
       }
       complex operator - (const complex& other)
       {
            return complex(r-other.r,i-other.i);
       }

       void point() const
       {
            cout<<"("<<r<<","<<i<<"i)"<<endl;
       }
};

int main()
{
    double r1,i1,r2,i2;
    cin>>r1>>i1;
    cout<<endl;
    cin>>r2>>i2;
    complex a(r1,i1);
    complex b(r2,i2);
    complex c=a+b;
    complex d=a-b; 
    cout<<"相加:"<<endl;
    c.point();
    cout<<"相减:"<<endl;
    d.point();
    return 0;
}