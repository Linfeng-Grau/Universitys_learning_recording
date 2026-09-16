#include<iostream>
using namespace std;

struct entity
{
    static int x,y;

    static void print()
    {
        cout<<x<<" "<<y;
    }
};

int entity::x;
int entity::y;

int main()
{
    entity::x=5;
    entity::y=10;

    entity::print();
    
    return 0;
}



