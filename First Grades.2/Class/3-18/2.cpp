#include <iostream>
#include <cmath>
using namespace std;

class point
{
    private:
        double x,y;
    public:
        point(double x,double y):x(x),y(y){}
    double getX() const
    {
        return x;
    }
    double getY() const
    {
        return y;
    }
};

class sjx
{
    private:
       double longs,areas;
       double s1,s2,s3;
       point p1,p2,p3;
    public:
       sjx(const point& p1,const point& p2,const point& p3)
       :p1(p1),p2(p2),p3(p3)
       {
        s1=distance(p1,p2);
        s2=distance(p2,p3);
        s3=distance(p3,p1);

        longs=(s1+s2+s3);

        double s=longs/2.0;
        areas=sqrt(s*(s-s1)*(s-s2)*(s-s3));
       }

       double distance(const point& p1,const point& p2)
       {
        return sqrt((p1.getX()-p2.getX())*(p1.getX()-p2.getX())+(p1.getY()-p2.getY())*(p1.getY()-p2.getY()));
       }

       double getlongs()
       {
        return longs;
       }

       double getareas()
       {
        return areas;
       }
};

int main()
{
    double x1,x2,x3,y1,y2,y3;
    cin>>x1>>y1>>x2>>y2>>x3>>y3;
    point p1(x1,y1),p2(x2,y2),p3(x3,y3);
    sjx sjx(p1,p2,p3);

    cout<<sjx.getlongs()<<endl;
    cout<<sjx.getareas()<<endl;

    return 0;
}