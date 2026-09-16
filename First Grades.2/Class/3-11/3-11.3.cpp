#include <iostream>         
using namespace std;

class deepcopy
{
    private:
        int *data;
    public:
        deepcopy(int value)
        {
            data=new int(value);       //深拷贝
        }
        deepcopy(const deepcopy& A)
        {
            data=new int(*A.data);
        }
        ~deepcopy()
        {
            delete data;
        }
        int getdata()
        {
            return *data;
        }
};

int main()
{
    deepcopy A(10);
    deepcopy B(A);
    cout<<"A data:"<<A.getdata()<<endl; 
    cout<<"B data:"<<B.getdata()<<endl;
    return 0;
}