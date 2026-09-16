#include <iostream>
#include <cmath>
using namespace std;

// 定义一个点类
class Point 
{
private:
    double x, y; // 点的坐标
public:
    // 构造函数，初始化点的坐标
    Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
    // 获取点的x坐标
    double getX() const { return x; }
    // 获取点的y坐标
    double getY() const { return y; }
};
// 定义一个三角形类
class Triangle 
{
private:
    Point p1, p2, p3; // 三角形的三个顶点
    double side1, side2, side3; // 三角形的三条边长
    double perimeter; // 三角形的周长
    double area; // 三角形的面积

public:
    // 构造函数，初始化三角形的三个顶点，并计算边长、周长和面积
    Triangle(const Point& p1, const Point& p2, const Point& p3)
    : p1(p1), p2(p2), p3(p3) 
    {
        // 计算三条边长
        side1 = distance(p1, p2);
        side2 = distance(p2, p3);
        side3 = distance(p3, p1);
        // 计算周长
        perimeter = side1 + side2 + side3;
        // 使用海伦公式计算面积
        double s = perimeter / 2.0; // 半周长
        area = sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    // 计算两点之间的距离
    double distance(const Point& p1, const Point& p2) 
    {
        return sqrt((p1.getX() - p2.getX()) * (p1.getX() - p2.getX()) +
                    (p1.getY() - p2.getY()) * (p1.getY() - p2.getY()));
    }
    // 获取三角形的周长
    double getPerimeter() const { return perimeter; }
    // 获取三角形的面积
    double getArea() const { return area; }
};

int main() 
{
    double x1, y1, x2, y2, x3, y3;
    // 输入三个点的坐标
    cout << "请输入三角形三个顶点的坐标（x1 y1 x2 y2 x3 y3）：";
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    // 创建三个点对象
    Point p1(x1, y1), p2(x2, y2), p3(x3, y3);
    // 创建三角形对象
    Triangle triangle(p1, p2, p3);
    // 输出三角形的周长和面积
    cout << "三角形的周长为：" << triangle.getPerimeter() << endl;
    cout << "三角形的面积为：" << triangle.getArea() << endl;
    return 0;
}