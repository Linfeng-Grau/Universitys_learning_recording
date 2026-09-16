
#include <iostream>

using namespace std;



int gys(int a,int b)

{

while(b!=0){int t=b;b=a%b;a=t;}

return a;

}



int main()

{

int n1,n2;

cin>>n1>>n2;

cout<<"答案为"<<gys(n1,n2);

}