#include <iostream>
#include <string>
using namespace std;

int main() 
{
    // 声明变量
    string studentID, name, hometown, hobbies, goal;

    // 请求用户输入信息
    cout << "请输入学号：";
    getline(cin, studentID);

    cout << "请输入姓名：";
    getline(cin, name);

    cout << "请输入家乡简介：";
    getline(cin, hometown);

    cout << "请输入兴趣爱好：";
    getline(cin, hobbies);

    cout << "请输入你的目标：";
    getline(cin, goal);

    // 输出用户输入的信息
    cout << "学号：" << studentID <<"\n" ;
    cout << "姓名：" << name <<"\n";
    cout << "家乡：" << hometown <<"\n";
    cout << "兴趣爱好：" << hobbies <<"\n";
    cout << "我的目标：" << goal <<"\n";

    return 0;
}