#include <iostream>
#include <string>
using namespace std;

int main()
{
    string studentID, name, hometown, hobbies, goal;
    // 个人信息
    studentID = "2024***47046";
    name = "李林峰";
    hometown = "重庆市";
    hobbies = "旅游，编程，绘画";
    goal = "成为一名优秀的工程师";

    // 输出自我介绍
    cout << "学号：" << studentID ;
    cout << "姓名：" << name ;
    cout << "家乡：" << hometown << "，一个美丽的地方。" ;
    cout << "兴趣爱好：" << hobbies ;
    cout << "我的目标：" << goal ;

    return 0;
}