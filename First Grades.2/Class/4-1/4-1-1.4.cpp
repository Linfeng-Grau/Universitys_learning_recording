#include <iostream>//复合赋值运算符(通常用成员函数)
using namespace std;

class v2D
{
    private:
    double x,y;
    
    public:
    v2D(double x=0,double y=0):x(x),y(y){}

    v2D& operator += (const v2D& other)
    {
        x+=other.x;
        y+=other.y;
        return *this;
    }

    void point()
    {
        cout<<x<<","<<y<<endl;
    }
};

int main()
{
    v2D a(1,2);
    v2D b(2,4);
    a+=b;
    a.point();
    b.point();
}