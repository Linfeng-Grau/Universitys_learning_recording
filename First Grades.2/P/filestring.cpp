#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

int main()
{
    int num;

    ofstream A("exmple.txt");
    if(!A.is_open())
    {
        cout<<"ERROR!";
        return 1;
    }
    else
    {
        A<<"你好";
        A.close();
    }

    cout<<"删除?0/1\n";
    cin>>num;

    const char* K="exmple.txt";

    switch (num)
    {
    case 1:
        remove(K);
        break;
    case 0:
        return 0;
    default:
        break;
    }
}