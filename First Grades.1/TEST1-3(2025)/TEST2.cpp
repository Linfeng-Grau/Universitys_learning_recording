#include <iostream>
using namespace std;

void IN(int& ref)
{
    ref++;
}
int value=10;
int main()
{
    cout<<::value;
    IN(value);cout<<endl;
    cout<<::value;
}