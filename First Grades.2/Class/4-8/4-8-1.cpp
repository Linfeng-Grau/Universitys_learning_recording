#include <iostream>//数组类
#include <stdexcept>
using namespace std;

class MyArray 
{
private:
    int* data;
    size_t size;

public:
    MyArray(size_t size) : size(size) 
    {
        data = new int[size];
    }

    ~MyArray() 
    {
        delete[] data;
    }

    int& operator [] (size_t index) 
    {
        if (index >= size) 
        {
            throw out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t getSize() const 
    {
        return size;
    }

    void remove(size_t index)
    {
        if(index>=size)
        {
            throw out_of_range("ERROR!");
        }
        else
        {
        for(size_t i=index;i<size-1;++i)
        {
            data[i]=data[i+1];
        }
        }
        --size;
    }
};



int main() 
{
    int i;
    int a;
    MyArray arr(40);
    for (size_t i = 0; i < arr.getSize(); ++i) 
    {
        arr[i] = i + 1;
    }

    for (size_t i = 0; i < arr.getSize(); ++i) 
    {
        cout << arr[i] <<" ";
    }
    cout << endl;
    
    while(1)
    {
        cout<<"删除？1/0"<<endl;
        cin>>a;
        if(a==0)
        {
            return 0;
        }
        cin>>i;
        try
        {
            arr.remove(i);
            cout<<"success"<<endl;
            for(size_t j=0;j<arr.getSize();++j)
            {
                cout<<arr[j]<<" ";
            }
            cout<<endl;
        }
        catch(const out_of_range& e)
        {
            cout<<"错误"<<e.what()<<endl;
        }
    }
    return 0;
}