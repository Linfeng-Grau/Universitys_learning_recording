#include <iostream>
using namespace std;

typedef int datatype;

const int MAXSIZE = 100;
typedef struct 
{
    datatype data[MAXSIZE];
    int length;               
} seqList;

int sl_search(seqList sl, int left, int right, datatype x) 
{
    //检查合法
    if (left < 0 || right >= sl.length || left >= right) 
    {
        return 1;
    }
    
    //指定区间内查找
    for (int i = left; i < right; i++) 
    {
        if (sl.data[i] == x) 
        {
            return i;
        }
    }
    
    return -1;  //未找到返回
}

int main() 
{
    seqList sl;
    sl.length = 6;
    sl.data[0] = 10;
    sl.data[1] = 20;
    sl.data[2] = 30;
    sl.data[3] = 20;  //重复元素
    sl.data[4] = 40;
    sl.data[5] = 50;
    
    int result;
    datatype x;

    cout << "请输入要查找的元素x:";
    cin >> x;

    int left,right;
    cout<<"请输入要查找的区间[left,right)"<<endl;
    cout<<"数据总长:"<<sl.length<<"，有效范围[0]~[5]"<<endl;
    cout<<"Left:";
    cin>>left;
    cout<<"Right:";
    cin>>right;
    result=sl_search(sl,left,right,x);
    if(result==1)
    {
        cout<<"输入区间参数非法！"<<endl;
        return 0;        
    }
    else 
    {
    if(result==-1)
    {
        cout<<"该区间未找到元素！"<<endl;    
        return 0; 
    }
    else
    {
        cout<<"该区间已找到元素"<<x<<",位置:"<<result<<endl;
        return 0;
    }
    }
}

