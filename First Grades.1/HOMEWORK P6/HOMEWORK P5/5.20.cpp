#include <iostream>
using namespace std;

int main() 
{
    int side1, side2, S;

    for (S=1;S<=500;++S) 
    {
        for (side1=1; side1<=S;++side1) 
        {
            for (side2=side1;side2<=S;++side2) 
            {
                if (side1*side1+side2*side2==S*S) 
                {
                    cout<<"毕达哥拉斯三元组: ("<<side1<<", "<<side2<<", "<<S<<")\n";
                }
            }
        }
    }

    return 0;
}