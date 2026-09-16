#include <iostream>
#include <iomanip>
#include <bitset>
using namespace std;

int main() 
{
    cout<<"十进制\t二进制\t八进制\t十六进制\n";
    for (int i = 1; i <= 256; ++i) 
    {
        cout<<i<<"\t";
        cout<<setfill('0')<<setw(8)<<bitset<8>(i).to_string()<<"\t";
        cout<<setfill('0')<<setw(3)<<oct<<i<<"\t";
        cout<<setfill('0')<<setw(2)<<hex<<i<<"\n";
    }
}