#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool pal(string str) 
{
    stack<char> s;
    int len = str.length();
    
    for (int i = 0; i < len / 2; i++) 
    {
        s.push(str[i]);
    }
    
    int start = (len % 2 == 0) ? len / 2 : len / 2 + 1;
    
    for (int i = start; i < len; i++) 
    {
        if (s.empty() || s.top() != str[i]) 
        {
            return false;
        }
        s.pop();
    }
    
    return true;
}

int main()
{
    //例
    string test1 = "pop";
    string test2 = "level";
    string test3 = "hello";
    string test4 = "racecar";
    string test5 = "a";
    string test6 = "ab";
    string test7 = "aa";
    
    cout << "测试回文串判断函数:" << endl;
    cout << "\"" << test1 << "\" 是回文串吗? " << (pal(test1) ? "是" : "否") << endl;
    cout << "\"" << test2 << "\" 是回文串吗? " << (pal(test2) ? "是" : "否") << endl;
    cout << "\"" << test3 << "\" 是回文串吗? " << (pal(test3) ? "是" : "否") << endl;
    cout << "\"" << test4 << "\" 是回文串吗? " << (pal(test4) ? "是" : "否") << endl;
    cout << "\"" << test5 << "\" 是回文串吗? " << (pal(test5) ? "是" : "否") << endl;
    cout << "\"" << test6 << "\" 是回文串吗? " << (pal(test6) ? "是" : "否") << endl;
    cout << "\"" << test7 << "\" 是回文串吗? " << (pal(test7) ? "是" : "否") << endl;
    
    //输入测试
    cout << "\n输入一个字符串进行测试: ";
    string userInput;
    cin >> userInput;
    cout << "\"" << userInput << "\" 是回文串吗? " << "\n答案:" << (pal(userInput) ? "是" : "否") << endl;
    
    return 0;
}
