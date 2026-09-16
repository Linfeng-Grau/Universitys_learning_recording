#include <iostream>
#include <string>
#include <stack>
using namespace std;

//括号是否正确配对
bool check(string exp) 
{
    stack<char> s;
    
    for (int i = 0; i < exp.length(); i++) 
    {
        char ch = exp[i];
        
        if (ch == '(' || ch == '[' || ch == '{') 
        {
            s.push(ch);
        }
        else if (ch == ')' || ch == ']' || ch == '}') 
        {
            if (s.empty()) 
            {
                return false;
            }
            
            char top = s.top();
            s.pop();
            
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) 
            {
                return false;
            }
        }
    }
    
    return s.empty();
}

int main() 
{
    string test1 = "()";           //1
    string test2 = "()[]{}";       //1
    string test3 = "([{}])";       //1
    string test4 = "([)]";         //0
    string test5 = "(((";          //0
    string test6 = ")))";          //0
    string test7 = "{[()]}";       //1
    string test8 = "{[(])}";       //0
    string test9 = "";             //1
    string test10 = "a+b*(c-d)";   //1
    
    cout << "测试括号匹配检查函数:" << endl;
    cout << "\"" << test1 << "\" 括号正确配对吗? " << (check(test1) ? "是" : "否") << endl;
    cout << "\"" << test2 << "\" 括号正确配对吗? " << (check(test2) ? "是" : "否") << endl;
    cout << "\"" << test3 << "\" 括号正确配对吗? " << (check(test3) ? "是" : "否") << endl;
    cout << "\"" << test4 << "\" 括号正确配对吗? " << (check(test4) ? "是" : "否") << endl;
    cout << "\"" << test5 << "\" 括号正确配对吗? " << (check(test5) ? "是" : "否") << endl;
    cout << "\"" << test6 << "\" 括号正确配对吗? " << (check(test6) ? "是" : "否") << endl;
    cout << "\"" << test7 << "\" 括号正确配对吗? " << (check(test7) ? "是" : "否") << endl;
    cout << "\"" << test8 << "\" 括号正确配对吗? " << (check(test8) ? "是" : "否") << endl;
    cout << "\"" << test9 << "\" 括号正确配对吗? " << (check(test9) ? "是" : "否") << endl;
    cout << "\"" << test10 << "\" 括号正确配对吗? " << (check(test10) ? "是" : "否") << endl;
    
    //输入测试
    cout << "\n请输入一个表达式进行测试(只支持英文括号): ";
    string userInput;
    getline(cin, userInput);
    cout << "\"" << userInput << "\" 括号正确配对吗? " << "\n答案是:" << (check(userInput) ? "是" : "否") << endl;
    
    return 0;
}
