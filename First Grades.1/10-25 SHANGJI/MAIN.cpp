#include <iostream>
#include <map>
#include <string>
using namespace std;

//库与声明 
map<string,string> userdatebase;

//定义注册函数
void registerone()
{
    string username,password,confirmPSWD;
    
    cout<<"请输入用户名：";
    cin>>username;

    while(userdatebase.find(username)!=userdatebase.end())
    {
        cout<<"此用户已经被注册，请重新输入用户名：";
        cin>>username;
    }

    cout<<"请输入密码：";
    cin>>password;

    cout<<"请再次输入密码：";
    cin>>confirmPSWD;

    while (password!=confirmPSWD)
    {
        cout<<"两次输入的密码不一致！请重新开始输入密码！";
        cin>>password;
        cout<<"请再次输入密码！";
        cin>>confirmPSWD;
    }

    userdatebase[username] = password;
    cout<<"注册成功!";
}

//定义登录函数
bool loginone()
{
    string username,password;
    int attempts=3;

    cout<<"请输入用户名：";
    cin>>username;

    while(userdatebase.find(username)==userdatebase.end()&& attempts>0)
    {
        cout<<"该用户名不存在！请重新输入：";
        cin>>username;
        attempts--;
    }

    if(attempts==0)
    {
        cout<<"次数达到上限，谢谢使用。";
        return 0;
    }

    cout<<"请输入密码：";
    cin>>password;

    while(userdatebase[username]!=password&&attempts>0)
    {
        cout<<"密码错误！请重新输入；";
        cin>>password;
        attempts--;
    }

    if(attempts==0)
    {
        cout<<"次数达到上限，谢谢使用。";
        return 0;
    }
    else
    {
        cout<<"欢迎"<<username<<"!";
        return 1;
    }
}


//主要的执行程序
int main()
{
    int what;

    do
    {
        cout<<"请选择操作：注册（1） 登录（2） 退出（3）";
        cin>>what;

    switch(what)
    {
        case 1:
          registerone();
          cout<<"\n**********\n";
          break;
        case 2:
          if (loginone())
          {
            cout<<"\n您已经成功登录。";
          }
          cout<<"\n**********\n";
          break;
        case 3:
          cout<<"程序已退出。";
          cout<<"\n**********\n";
          break;
        default:
          cout<<"\n输入非法";
    }
    }while(what!=3);

    return 0;
}