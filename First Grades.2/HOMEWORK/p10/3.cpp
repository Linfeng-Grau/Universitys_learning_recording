#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

class p 
{
private:
    vector<pair<double, int>> terms;

    void st() 
    {
        sort(terms.begin(), terms.end(), [](const pair<double, int>& a, const pair<double, int>& b) {return a.second > b.second;});
    }

    void ct() 
    {
        st();
        for (size_t i = 0; i < terms.size(); ++i) 
        {
            for (size_t j = i + 1; j < terms.size(); ++j) 
            {
                if (terms[i].second == terms[j].second) 
                {
                    terms[i].first += terms[j].first;
                    terms.erase(terms.begin() + j);
                    --j;
                }
            }
        }
    }

public:
    p(const vector<pair<double, int>>& initTerms = {}) 
    {
        terms = initTerms;
        ct();
    }

    p(const p& other) 
    {
        terms = other.terms;
    }

    p& operator=(const p& other) 
    {
        if (this != &other) 
        {
            terms = other.terms;
        }
        return *this;
    }

    p operator+(const p& rhs) const 
    {
        p result(*this);
        result.terms.insert(result.terms.end(), rhs.terms.begin(), rhs.terms.end());
        result.ct();
        return result;
    }

    p& operator+=(const p& rhs) 
    {
        terms.insert(terms.end(), rhs.terms.begin(), rhs.terms.end());
        ct();
        return *this;
    }

    p operator-(const p& rhs) const 
    {
        p result(*this);
        for (const auto& term : rhs.terms) 
        {
            result.terms.push_back({-term.first, term.second});
        }
        result.ct();
        return result;
    }

    p& operator-=(const p& rhs) 
    {
        for (const auto& term : rhs.terms) 
        {
            terms.push_back({-term.first, term.second});
        }
        ct();
        return *this;
    }

    p operator*(const p& rhs) const 
    {
        vector<pair<double, int>> resultTerms;
        for (const auto& term1 : terms) 
        {
            for (const auto& term2 : rhs.terms) 
            {
                resultTerms.push_back({term1.first * term2.first, term1.second + term2.second});
            }
        }
        return p(resultTerms);
    }

    p& operator*=(const p& rhs) 
    {
        *this = *this * rhs;
        return *this;
    }

    friend ostream& operator<<(ostream& o, const p& p) 
    {
        bool first = true;
        for (const auto& term : p.terms) 
        {
            if (!first && term.first > 0) 
            {
                o << " + ";
            } else if (!first && term.first < 0) 
            {
                o << " - ";
            }
            if (abs(term.first) != 1 || term.second == 0) 
            {
                o << abs(term.first);
            }
            if (term.second > 0) 
            {
                o << "x";
                if (term.second > 1) 
                {
                    o << "^" << term.second;
                }
            }
            first = false;
        }

        if (p.terms.empty()) 
        {
            o << "0";
        }
        return o;
    }
};

int main() 
{
    p p1({{3, 2}, {2, 1}, {1, 0}}); // 3x^2 + 2x + 1
    p p2({{1, 2}, {-1, 1}, {2, 0}}); // x^2 - x + 2

    cout << "p1 = " << p1 << endl;
    cout << "p2 = " << p2 << endl;

    p p3 = p1 + p2;
    cout << "p1 + p2 = " << p3 << endl;

    p p4 = p1 - p2;
    cout << "p1 - p2 = " << p4 << endl;

    p p5 = p1 * p2;
    cout << "p1 * p2 = " << p5 << endl;

    p p6 = p1;
    cout << "p6 = p1 = " << p6 << endl;

    p6 += p2;
    cout << "p6 += p2 = " << p6 << endl;
    p6 -= p2;
    cout << "p6 -= p2 = " << p6 << endl;
    p6 *= p2;
    cout << "p6 *= p2 = " << p6 << endl;

    return 0;
}