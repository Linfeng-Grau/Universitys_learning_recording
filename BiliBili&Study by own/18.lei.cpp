#include <iostream>
using namespace std;
#define LOG(x) cout<<x

class player//定义了一个“玩家”的类，并在类中定义了三个变量，以及一个函数move。
{
    public://public表示这个变量和函数可以被外部使用，不然在int函数内的就不能使用。与public相反的是private。
           //默认是private。
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
    player wanjia;//定义了一个“玩家”类名称为“wanjia”。
    wanjia.move(1,2);//调用了wanjia这一个“玩家”类中的函数move。

    return 0;
}

//   如果move移除了类“玩家”的定义，则wanjia这个类的函数move就不能使用了。
//   则会变成：
//   void move(Player& wanjia, int xa, int ya)
//   {
//       wanjia.x+=xa*wanjia.speed;
//       wanjia.y+=ya*wanjia.speed;
//   }
//   而int函数内的则是move(wanjia,1,2)
