#include <iostream>
#include <map>
#include <string>

using namespace std;

// 存储用户名和密码的映射
map<string, string> userDatabase;

// 注册函数
void registerUser() {
    string username, password, confirmPassword;

    cout << "请输入用户名: ";
    cin >> username;

    // 检查用户名是否已被注册
    while (userDatabase.find(username) != userDatabase.end()) {
        cout << "该用户名已被注册，请重新输入用户名: ";
        cin >> username;
    }

    cout << "请输入密码: ";
    cin >> password;

    cout << "请再次输入密码: ";
    cin >> confirmPassword;

    // 检查两次输入的密码是否相同
    while (password != confirmPassword) {
        cout << "两次输入的密码不一致，请重新输入密码: ";
        cin >> password;
        cout << "请再次输入密码: ";
        cin >> confirmPassword;
    }

    // 注册成功，将用户名和密码存入数据库
    userDatabase[username] = password;
    cout << "注册成功！" << endl;
}

// 登录函数
bool loginUser() {
    string username, password;
    int attempts = 3;

    cout << "请输入用户名: ";
    cin >> username;

    // 检查用户名是否存在
    while (userDatabase.find(username) == userDatabase.end() && attempts > 0) 
    {
        cout << "该用户名不存在，请重新输入: ";
        cin >> username;
        attempts--;
    }

    if (attempts == 0) 
    {
        cout << "谢谢使用。" << endl;
        return false;
    }

    cout << "请输入密码: ";
    cin >> password;

    // 检查密码是否正确
    while (userDatabase[username] != password && attempts > 0) {
        cout << "密码错误，请重新输入: ";
        cin >> password;
        attempts--;
    }
    
    if (attempts == 0) 
    {
        cout << "谢谢使用。" << endl;
        return false;
    } 
    else 
    {
        cout << "欢迎 " << username << "！" << endl;
        return true;
    }
}

int main() {
    int choice;

    do {
        cout << "请选择操作：1. 注册 2. 登录 3. 退出" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                if (loginUser()) 
                {
                    cout << "您已成功登录。" << endl;
                }
                break;
            case 3:
                cout << "程序已退出。" << endl;
                break;
            default:
                cout << "无效选项，请重新选择。" << endl;
        }
    } while (choice != 3);

    return 0;
}