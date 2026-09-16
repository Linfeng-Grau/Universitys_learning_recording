#include <iostream>
#include <string>
using namespace std;
#include "3-11.1EXTRA.cpp"

int main()
{
    string num,name;
    int amount,price;
    invoice A;
    cin>>num>>name>>amount>>price;
    A.setinvoice(num,name,amount,price);
    cout<<A.getnum()<<endl;
    cout<<A.getname()<<endl;
    cout<<A.getamount()<<endl;
    cout<<A.getprice()<<endl;
    cout<<A.gettotal()<<endl;
    return 0;
}