#include <iostream>
#include <vector>
#include <string>
using namespace std;

class a
{
    public:
    int n,m;
    a(int n,int m):n(n),m(m){}
};

class b
{
    public:
    vector<a> a;
    
    void ad()
    {
        int n=10;
        for(int i=0;i<n;++i)
        {
        a.emplace_back(0,0);
        }
        cin>>a[0].n;
        cin>>a[2].m;      
    }

    void display()
    {
        cout<<a[2].m;
        cout<<a[0].n;
    }
};

int main()
{
    b b;
    b.ad();
    b.display();
}