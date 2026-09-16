#include <iostream>
#include <fstream>
#include <stdexcept> 
using namespace std;

int main()
{
    try
    {
        ifstream A("NM.test");
        if(!A.is_open())
        {
            cout<<"Sorry!There are some something wrong.";
        }
        cout<<"File opened successfully!\n";

        string thing;
        while(getline(A,thing))
        {
            cout<<thing<<endl;
        }
        A.close();
    }
    catch(const runtime_error& e)
    {
        cerr<<"ERROR:"<<e.what();
    }
    return 0;
}