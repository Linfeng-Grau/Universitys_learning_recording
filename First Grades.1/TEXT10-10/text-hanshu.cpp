#include <iostream>
using namespace std;

void log(int n,int r)
{
    cout<<max(n,r);    
}

void Multiplylog(int n,int r)
{
    log(n,r);
    cout<<"!";
}

int main()
{
    int n,r;
    cin>>n>>r;

    Multiplylog(n,r);
}