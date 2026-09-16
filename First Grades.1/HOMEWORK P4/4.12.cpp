#include <iostream>
using namespace std;

int main()
{
    unsigned int y=0;
    unsigned int x=1;
    unsigned int total=0;

    while(x<=10)
    {
        y=x*x;
        cout<<y<<"\n";
        total +=y;
        ++x;
    }

    cout<<"Total is"<<total;

}