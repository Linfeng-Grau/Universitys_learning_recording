#include <iostream>
using namespace std;
#define LOG(x) cout<<x

int main()
{
    LOG('S');
    #ifdef LOG
      cout<<"B";
    #else
      cout<<"C";
    #endif

    return 0;
}