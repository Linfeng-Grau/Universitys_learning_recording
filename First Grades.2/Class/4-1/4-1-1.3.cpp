#include <iostream>
using namespace std;//运算符重载-输入流(输出流同理)

class test 
{
private:
    string value;
public:
    test(const string& v=""):value(v){}

    friend istream& operator >> (istream& in, test& obj);

    void point() const
    {
        cout<<value;
    }
};

istream& operator >> (istream& in, test& obj) 
{
    in >> obj.value;
    return in;
}

int main()
{
    test a;
    cin >> a;//实际上是输入a的value
    a.point();
}