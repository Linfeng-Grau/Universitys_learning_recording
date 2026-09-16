#include <iostream>
using namespace std;

int main()
{
    int counter,number,largest;
    counter=number=largest=0;

    cout<<"请输入10个数（依次）\n";
    
    while(counter<10)
    {
        cin>>number;
        
        if(counter==0)
        {
            largest=number;
        }
        else
        {
            if (number>largest)
            {
                largest=number;
            }    
        }

        ++counter;
    }

    cout<<"最大数是"<<largest;

}