#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 创建一个整型 vector
    vector<int> vec;

    // 添加元素
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    // 访问元素
    cout << "Element at index 1: " << vec[0] << endl; // 输出 1

    // 使用迭代器遍历 vector
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) 
    {
        cout << *it << " ";
    }
    cout << endl;

    // 使用范围基于 for 循环遍历 vector (C++11 及以上)
    for (int val : vec) 
    {
        cout << val << " ";
    }
    cout << endl;

    // 获取 vector 的大小
    cout << "Vector size: " << vec.size() << endl; // 输出 3

    // 检查 vector 是否为空
    if (vec.empty()) {
        cout << "Vector is empty." << endl;
    } else {
        cout << "Vector is not empty." << endl;
    }

    // 删除最后一个元素
    vec.pop_back();

    // 插入元素
    vec.insert(vec.begin() + 1, 4);

    // 改变 vector 的大小
    vec.resize(5); // 可能添加默认构造的元素

    for (int val : vec) 
    {
        cout << val << " ";
    }
    cout << endl;

    // 清空 vector
    vec.clear();
    

    return 0;
}