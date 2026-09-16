#include <iostream>
using namespace std;

struct node
{
    int fk;
    int sk;
};

bool compare(const node& a,const node& b)
{
    if(a.fk<b.fk) return 0;
    if(a.fk>b.fk) return 1;
    
}