#include <iostream>
using namespace std;

class deepcopy
{
    private:
        int *data;
    public:
        deepcopy(int value)
        {
            data=new int(value);
        }
        deepcopy(const deepcopy& A)
        {
            data=new int(*A.data);
        }
        ~deepcopy()
        {
            delete data;
        }
        int print()
        {
            return *data;
        }
};

int main()
{
    deepcopy A(8);
    deepcopy B(A);
    cout<<"A:"<<A.print()<<endl;
    cout<<"B:"<<B.print();
    return 0;
}

