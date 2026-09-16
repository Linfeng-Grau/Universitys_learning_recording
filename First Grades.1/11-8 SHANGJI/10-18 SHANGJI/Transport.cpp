#include <iostream>
using namespace std;

int main()
{
    double W,D,C;

    cout<<"请输入载重（吨）:";
    cin>>W;
    cout<<"请输入里程（公里）：";
    cin>>D;

    C=W*D;

if (D < 250) {
    // 没有折扣
    } else if (D < 500) {
        C *= 0.98; // 2%折扣
    } else if (D < 1000) {
        C *= 0.95; // 5%折扣
    } else if (D < 2000) {
        C *= 0.92; // 8%折扣
    } else if (D < 3000) {
        C *= 0.90; // 10%折扣
    } else {
        C *= 0.85; // 15%折扣
    }

    cout << "运输费用为：" << C << endl;
    
    return 0;
}