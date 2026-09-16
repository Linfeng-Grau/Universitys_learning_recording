#include <iostream>
#include <string>
#include <stack>
using namespace std;

string postorder(string str)
{
    if(str.empty())
    {
        return "";
    }
    
    stack<string> stk;
    int i=0;

    while(i<str.length())
    {
        if(str[i]=='#')
        {
            stk.push("#");
            i++;
        }
        else
        {
            char node=str[i];
            i++;

            string left="";
            string right="";

            if(!stk.empty())
            {
                left=stk.top();
                stk.pop();
            }

            if(!stk.empty())
            {
                right=stk.top();
                stk.pop();
            }

            string post=left+right+node;
            stk.push(post);
        }
    }

    return stk.empty()?"":stk.top();
}

int main()
{
    string test="AB#C##D##";
    cout<<"先根序列"<<test<<endl;
    cout<<"后根序列"<<postorder(test)<<endl;

    string test2 = "ABC##D##E#F";
    cout<<"先根序列:"<<test2<<endl;
    cout<<"后根序列:"<<postorder(test2)<<endl;
    
    return 0;
}