#include <iostream>
#include <vector>
using namespace std;

// 函数用于检查一个数是否为素数
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0)
            return false;
    }
    return true;
}

int main() {
    const int limit = 100; // 找出小于等于100的所有孪生素数
    vector<pair<int, int>> twinPrimes; // 用于存储孪生素数对

    for (int i = 2; i <= limit; ++i) {
        if (isPrime(i) && isPrime(i + 2)) {
            twinPrimes.emplace_back(i, i + 2);
        }
    }

    // 输出所有孪生素数对
    for (const auto& pair : twinPrimes) {
        cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    cout << endl;

    return 0;
}