#include <iostream>
#include <cstring> // 添加了cstring头文件（定义memset函数）
using namespace std;

#define LOG(x) cout<<x<<endl;

int main()
{
    //指针 
    int var=6;
    int* ptr=&var;//(*ptr)是一个整数变量，它的值是var的地址（指针变量ptr的值是var的地址），可以通过*ptr来访问var的值，而&是用来获得var的地址。
    *ptr=16;
    LOG(var);

    //使用内存块（字节）的指针 
    char* buffer=new char[8];
    memset(buffer,0,8);//将buffer中的8个字节都设置为0。如果不是0，则会出现乱码，因为是字符型变量。 
    LOG(buffer);
    delete[] buffer;

    return 0;
}

//指针