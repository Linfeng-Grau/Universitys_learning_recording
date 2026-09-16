#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double JIA(double a, double b);
double JIAN(double a, double b);
double CHENG(double a, double b);
double CHU(double a, double b);
double JUEDUI(int a);
double PINGFANG(double a);
double EZHISHU(double a);
double ZHISHU(double x, double y);
void TUICHU();

int main() 
{
    int choice;
    double num1, num2;
    int intNum1, intNum2;

    while (1) 
    {
        cout << "\n欢迎使用简易计算器！\n";
        cout << "1. 加法\n";
        cout << "2. 减法\n";
        cout << "3. 乘法\n";
        cout << "4. 除法\n";
        cout << "5. 绝对值\n";
        cout << "6. 平方根\n";
        cout << "7. e^x\n";
        cout << "8. x^y\n";
        cout << "9. 退出\n";
        cout << "请选择操作（1-9）：";
        cin >> choice;

        switch (choice) 
        {
            case 1:
                cout << "请输入两个浮点数：";
                cin >> num1 >> num2;
                cout << "结果是: " << fixed << setprecision(2) << JIA(num1, num2);
                break;
            case 2:
                cout << "请输入两个浮点数：";
                cin >> num1 >> num2;
                cout << "结果是: " << fixed << setprecision(2) << JIAN(num1, num2);
                break;
            case 3:
                cout << "请输入两个浮点数：";
                cin >> num1 >> num2;
                cout << "结果是: " << fixed << setprecision(2) << CHENG(num1, num2);
                break;
            case 4:
                cout << "请输入两个浮点数：";
                cin >> num1 >> num2;
                cout << "结果是: " << fixed << setprecision(2) << CHU(num1, num2);
                break;
            case 5:
                cout << "请输入一个整数：";
                cin >> intNum1;
                cout << "结果是: " << JUEDUI(intNum1);
                break;
            case 6:
                cout << "请输入一个整数：";
                cin >> num1;
                cout << "结果是: " << fixed << setprecision(2) << PINGFANG(num1);
                break;
            case 7:
                cout << "请输入一个整数：";
                cin >> num1;
                cout << "结果是: " << fixed << setprecision(2) << EZHISHU(num1);
                break;
            case 8:
                cout << "请输入两个整数：";
                cin >> intNum1 >> intNum2;
                cout << "结果是: " << ZHISHU(intNum1, intNum2);
                break;
            case 9:
                TUICHU();
                break;
            default:
                cout << "无效的选择，请重新输入。";
        }
    }
    return 0;
}


double JIA(double a, double b) 
{
    return a + b;
}

double JIAN(double a, double b) 
{
    return a - b;
}

double CHENG(double a, double b) 
{
    return a * b;
}

double CHU(double a, double b) 
{
    if (b != 0)
    {
        return a / b;
    } else {
        cout << "除数不能为0。";
        return 0;
    }
}

double JUEDUI(int a) 
{
    return abs(a);
}

double PINGFANG(double a) 
{
    if (a >= 0) 
    {
        return sqrt(a);
    } else 
    {
        cout << "负数没有实数平方根。";
        return 0;
    }
}

double EZHISHU(double a) 
{
    return exp(a);
}

double ZHISHU(double x, double y) 
{
    return pow(x, y);
}

void TUICHU() 
{
    cout << "感谢使用简易计算器，再见！";
    exit(0);
}