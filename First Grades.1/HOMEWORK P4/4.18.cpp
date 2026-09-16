#include <iostream>
using namespace std;

int main()
{
    int N=1;
    cout<<"N\t10*N\t100*N\t1000*N\n";

    while(N<=5)
    {
        cout<<N<<"\t"<<N*10<<"\t"<<N*100<<"\t"<<N*1000<<"\n";
        ++N;
    }

    return 0;
}