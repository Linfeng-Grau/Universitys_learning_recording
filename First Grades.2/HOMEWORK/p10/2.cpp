#include <iostream>
#include <cmath>
using namespace std;

class rn 
{
private:
    int n; 
    int d; 

    void simplify() 
    {
        if (d == 0) 
        {
            throw invalid_argument("分母不能为0");
        }
        if (d < 0) 
        {
            n = -n;
            d = -d;
        }

        int gcd = abs(n);
        for (int i = abs(d); i > 1; --i) 
        {
            if (n % i == 0 && d % i == 0) 
            {
                gcd = i;
                break;
            }
        }
        n /= gcd;
        d /= gcd;
    }

public:
    rn(int num = 0, int denom = 1) {
        if (denom == 0) {
            throw invalid_argument("分母不能为0");
        }
        n = num;
        d = denom;
        simplify();
    }

    rn operator+(const rn& rhs) const 
    {
        return rn(n * rhs.d + rhs.n * d,d * rhs.d);
    }

    rn operator-(const rn& rhs) const 
    {
        return rn(n * rhs.d - rhs.n * d,d * rhs.d);
    }

    rn operator*(const rn& rhs) const 
    {
        return rn(n * rhs.n, d * rhs.d);
    }

    rn operator/(const rn& rhs) const 
    {
        if (rhs.n == 0) 
        {
            throw invalid_argument("除数不能为0");
        }
        return rn(n * rhs.d, d * rhs.n);
    }

    bool operator==(const rn& rhs) const 
    {
        return (n == rhs.n) && (d == rhs.d);
    }

    bool operator!=(const rn& rhs) const 
    {
        return !(*this == rhs);
    }

    bool operator<(const rn& rhs) const 
    {
        return n * rhs.d < rhs.n * d;
    }

    bool operator>(const rn& rhs) const 
    {
        return rhs < *this;
    }

    bool operator<=(const rn& rhs) const 
    {
        return !(*this > rhs);
    }

    bool operator>=(const rn& rhs) const 
    {
        return !(*this < rhs);
    }

    friend ostream& operator<<(ostream& out, const rn& r) {
        if (r.d == 1) 
        {
            out << r.n;
        } 
        else 
        {
            out << r.n << "/" << r.d;
        }
        return out;
    }
};

int main() 
{
    try 
    {
        rn r1(3, 4);
        rn r2(2, 3);

        cout << "r1 = " << r1 << endl;
        cout << "r2 = " << r2 << endl;

        rn r3 = r1 + r2;
        cout << "r1 + r2 = " << r3 << endl;

        rn r4 = r1 - r2;
        cout << "r1 - r2 = " << r4 << endl;

        rn r5 = r1 * r2;
        cout << "r1 * r2 = " << r5 << endl;

        rn r6 = r1 / r2;
        cout << "r1 / r2 = " << r6 << endl;

        cout << "r1 == r2: " << (r1 == r2) << endl;
        cout << "r1 != r2: " << (r1 != r2) << endl;
        cout << "r1 < r2: " << (r1 < r2) << endl;
        cout << "r1 > r2: " << (r1 > r2) << endl;
        cout << "r1 <= r2: " << (r1 <= r2) << endl;
        cout << "r1 >= r2: " << (r1 >= r2) << endl;
    } 
    catch (const exception& e) 
    {
        cerr << "发生错误: " << e.what() << endl;
    }

    return 0;
}