#include <iostream>
using namespace std;
#include <string>

string preorder(string a)
{
    string result="";

    if(a.empty())
    {
        return "输入是空的喵=w=";
    }

    int l=0,r=0;
    
    for(int i=0;i<a.length();i++)
    {
        if(a[i]=='(')
        {
            l++;
        }
        else if(a[i]==')')
        {
            r++;
        }
    }

    if(l!=r)
    {
        return "\nERROR!输入非法!";
    }

    for(int n=0;n<a.length();n++)
    {
        if(a[n]!='('&&a[n]!=')'&&a[n]!=',')
        {
            result+=a[n];
        }
    }

    return result;
}

int main()
{
    string test;
    cout<<"请输入括号表达式:"<<endl;
    cin>>test;
    cout<<"结果为"<<preorder(test);
    return 0;
}