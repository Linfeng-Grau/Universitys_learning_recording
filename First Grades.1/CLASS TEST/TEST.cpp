#include <iostream>
#include <ctime>
using namespace std; 

int main() 
{
    int b=10,a=1;
    srand(time(0));

    for (int i=0; i<10;i++)
    {
       int random_number = a+rand()%(b-a+1);
       cout << "\nRandom number: " << random_number ;
    }
       
    return 0;
} 
