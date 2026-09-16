#include <iostream>
using namespace std;
#define LOG(x) cout<<x

struct player //结构体类型,与class不同的是，默认是public.如果想要结构体内不能被读写的话，则需添加private。
{             //结构体与类的区别是：结构体的默认是public，而类的默认是private。且两者差距不大，并且struct可以与C语言兼容。
              //但处理大量数据时，建议使用类。
        int x,y;
        int speed;

        void move(int xa, int ya)
        {
            x+=xa*speed;
            y+=ya*speed;
        }
};

int main()
{
    player wanjia;
    wanjia.move(1,2);

    return 0;
}

//结构体