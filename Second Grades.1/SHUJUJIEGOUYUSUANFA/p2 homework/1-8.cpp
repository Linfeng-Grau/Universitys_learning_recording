#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> cities;
    
    cities.push_back("Beijing");
    cities.push_back("Nanjing");
    cities.push_back("Shanghai");
    cities.push_back("Guangzhou");
    cities.push_back("Hangzhou");
    cities.push_back("Shenzheng");
    
    sort(cities.begin(), cities.end(), greater<string>());
    
    cout << "按字典序从大到小排序后的城市列表：" << endl;
    for (const auto& A : cities) 
    {
        cout << A << " ";
    }
    cout << endl;
    return 0;
}