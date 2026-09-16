#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class point
{
    private:
        double x,y;
    public:
        point(double A,double B):x(A),y(B){}
        double distance(const point& p) const
        {
            return sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y));  
        }
};

class sjx
{
    private:
        point p1,p2,p3;
        double s1,s2,s3;
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

        double area() const
        {
            double s=longs()/2;
            return sqrt(s*(s-s1)*(s-s2)*(s-s3));
        }
};

int main()
{
    double x1,x2,x3,y1,y2,y3;
    cout<<"输入三角形的三个顶点的坐标(X1,,Y1,X2,Y2,X3,Y3):";
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    
    sjx sjx(x1,x2,x3,y1,y2,y3);
    
    cout<<"周长:"<<sjx.longs();
    cout<<"面积:"<<sjx.area();

    return 0;
}