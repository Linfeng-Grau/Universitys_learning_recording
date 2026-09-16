#include <iostream>
#include <string>
using namespace std;

class invoice
{
    private:
        string num;
        string name;
        int amount;
        int price;
    public:
        void setinvoice(string n,string na,int am,int pr)
        {
            num=n;
            name=na;
            amount=am;
            price=pr;
        };
        string getnum()
        {
            return num;
        };
        string getname()
        {
            return name;
        };
        int getamount()
        {
            return amount;
        };
        int getprice()
        {
            return price;
        };
        int gettotal()
        {
            return amount*price;
        };
};
