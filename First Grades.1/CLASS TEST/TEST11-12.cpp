#include <iostream>
using namespace std;


// 定义一个强类型枚举
enum class DayOfWeek 
{
    Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
};

// 函数声明
void printDayActivity(DayOfWeek day);

void printDayActivity(DayOfWeek day) 
{
    switch (day) {
        case DayOfWeek::Sunday:
        case DayOfWeek::Saturday:
            cout << "Let's relax!";
            break;
        case DayOfWeek::Monday:
        case DayOfWeek::Tuesday:
        case DayOfWeek::Wednesday:
        case DayOfWeek::Thursday:
        case DayOfWeek::Friday:
            cout << "Time to work!";
            break;
        default:
            cout << "Invalid day";
    }
}

int main() {
    char choice;
    cout << "欢迎使用简易星期选择器！\n";
    do {
        cout << "请输入星期（1-7）选择对应的星期：\n";
        cout << "1. Sunday\n2. Monday\n3. Tuesday\n4. Wednesday\n5. Thursday\n6. Friday\n7. Saturday\n0. 退出\n";
        cout << "请选择（0-7）：";
        cin >> choice;

        switch (choice) {
            case '1':
                printDayActivity(DayOfWeek::Sunday);
                break;
            case '2':
                printDayActivity(DayOfWeek::Monday);
                break;
            case '3':
                printDayActivity(DayOfWeek::Tuesday);
                break;
            case '4':
                printDayActivity(DayOfWeek::Wednesday);
                break;
            case '5':
                printDayActivity(DayOfWeek::Thursday);
                break;
            case '6':
                printDayActivity(DayOfWeek::Friday);
                break;
            case '7':
                printDayActivity(DayOfWeek::Saturday);
                break;
            case '0':
                cout << "感谢使用简易星期选择器，再见！";
                break;
            default:
                cout << "无效的选择，请重新输入";
        }
    } while (choice != '0');

    return 0;
}

