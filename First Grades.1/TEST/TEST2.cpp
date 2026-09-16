#include <iostream>
using namespace std;

unsigned long long FR(int n)
{
if(n<=1){return 1;}
else{return n*FR(n-1);}
}

int main()
{
int x,y;
cin>>x>>y;
cout<<(FR(x)/(FR(y)*FR((x-y))));
return 0;
}