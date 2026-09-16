#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

class point
{
    private:
        double x;
        double y;
    public:
        point(double x,double y):x(x),y(y){}
        double distance(const point& p)const
        {
            return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));
        }
};

class sjx
{
    private:
        double s1,s2,s3;
        point p1,p2,p3;
    public:
        sjx(double x1,double x2,double x3,double y1,double y2,double y3)
        :p1(x1,y1),p2(x2,y2),p3(x3,y3)
        {
            s1=p1.distance(p2);
            s2=p2.distance(p3);
            s3=p3.distance(p1);
        }

        double longs() const
        {
            return s1+s2+s3;
        }

        double areas() const
        {
            double s=longs()/2;
            return sqrt(s*(s-s1)*(s-s2)*(s-s3));
        }
};

int main()
{
    double x1,x2,x3,y1,y2,y3;
    cout<<"请依次输入(x1,y1),(x2,y2),(x3,y3):";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    sjx sjx(x1,x2,x3,y1,y2,y3);

    cout<<"面积是"<<sjx.areas();
    cout<<"周长是"<<sjx.longs();

    return 0;
}
