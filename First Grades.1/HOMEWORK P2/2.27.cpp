#include <iostream>
using namespace std;

int main()
{
    char ch;
    cout<<"请输入一个字符：";
    cin>>ch;

    cout<<"输入字符为"<<ch;
    cout<<"对应的ASCII为"<<static_cast<int>(ch);

    return 0;
}