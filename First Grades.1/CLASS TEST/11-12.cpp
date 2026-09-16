#include <iostream>
using namespace std;

int a=2;
int main()
{
    int b=2,c=3;
    ++a;
    c+=++b;

    if(++a||++b||++c)
    cout<<a<<" "<<b<<" "<<c;
    {
       int a=3,c;
       c=b*3;
       a+=c;
       cout<<a<<" "<<b<<" "<<c;
    }
    a+=c;
    cout<<a<<" "<<b<<" "<<c;
}
