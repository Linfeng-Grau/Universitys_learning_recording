//1.exit语句对全局/局部析构函数的影响example

#include <iostream>
#include <cstdlib>
using namespace std;

class Object 
{
public:
   Object() 
   {
      cout << "全局对象构造" <<endl;
   }
   ~Object() 
   {
      cout << "全局对象析构" <<endl;
   }
};

Object g;  // 全局对象,此时运行时会调用析构函数

int main() 
{
   cout << "程序开始运行。" <<endl;
   cout << "调用exit函数提前退出程序。" <<endl;
   exit(0);  // 提前退出程序
   cout << "这行代码不会被执行。" <<endl;
   return 0;
}
//如果Object g这个语句在int mian（）中，此时为局部对象，此时析构函数不会被调用，不会打出“全局对象析构”这句话。

//exit(0)表示成功运行后正常退出
//exit(1)表示程序运行错误后异常退出
//exit(-1)同(1)一样，但是表示更具体的错位类型
