#include<iostream>
using namespace std;

class interest
{
public:
    static interest& get()
    {
        static interest example;
        return example;
    }
    void hello(){cout<<"Hello!";};
};

int main()
{
    interest::get().hello();
    return 0;
}