#include <iostream>
using namespace std;

int A=1,X=5;

int main()
{
    while(1)
    {
        for (int i = X; i > 0; i--)
        {
            A*=i;
        }
        cout<<X<<"!:"<<A<<"\n";
        X=(X-1);
        A=1;
        if(X==0)
        {
            break;
        }
    }
}