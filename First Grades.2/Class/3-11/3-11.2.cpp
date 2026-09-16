#include <iostream>
using namespace std;

class ShallowCopyExample 
{
private:
    int* data;
public:
    // 构造函数
    ShallowCopyExample(int value) 
    {
        data = new int(value);
    }

    // 浅拷贝构造函数（编译器默认生成的也是这种行为）
    ShallowCopyExample(const ShallowCopyExample& other) 
    {
        data = other.data; // 只复制指针，不复制内存
    }

    // 析构函数
    ~ShallowCopyExample() 
    {
        delete data;
    }

    // 获取数据
    int getData() const 
    {
        return *data;
    }
};

int main() 
{
    ShallowCopyExample obj1(10);
    ShallowCopyExample obj2(obj1); // 浅拷贝

    cout << "obj1 data: " << obj1.getData() << endl;
    cout << "obj2 data: " << obj2.getData() << endl;

    return 0;
}
