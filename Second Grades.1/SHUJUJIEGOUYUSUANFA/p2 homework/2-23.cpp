#include <iostream>
#include <cstring>
using namespace std;

#define M 5

typedef struct csNode 
{
    char data[M+1];    
    csNode *pre;        
    csNode *next;    
    csNode():pre(NULL),next(NULL) 
    {
        for(int i=0; i<=M; i++)
            data[i]='\0';
    }
} *chainString;

// 创建链串
chainString createChainString(const char* str) 
{
    if (str == NULL || strlen(str) == 0) 
    {
        chainString head = new csNode();
        return head;
    }
    
    int len = strlen(str);
    chainString head = new csNode();
    chainString current = head;
    
    int nodeIndex = 0;
    for (int i = 0; i < len; i++) 
    {
        if (nodeIndex == M) 
        {
            chainString newNode = new csNode();
            current->next = newNode;
            newNode->pre = current;
            current = newNode;
            nodeIndex = 0;
        }
        
        current->data[nodeIndex] = str[i];
        nodeIndex++;
    }
    
    return head;
}

//计算长度
int length(chainString str) 
{
    if (str == NULL) return 0;
    
    int count = 0;
    chainString current = str;
    
    while (current != NULL) 
    {
        for (int i = 0; i < M && current->data[i] != '\0'; i++) 
        {
            count++;
        }
        current = current->next;
    }
    
    return count;
}

void printChainString(chainString str) 
{
    if (str == NULL) 
    {
        cout << "链串为空" << endl;
        return;
    }
    
    chainString current = str;
    while (current != NULL) 
    {
        for (int i = 0; i < M && current->data[i] != '\0'; i++) 
        {
            cout << current->data[i];
        }
        current = current->next;
    }
    cout << endl;
}

//求链串str中编号在区间[left,right)中的字符所构成的子串
chainString subStr(chainString str, int left, int right) 
{
    //检查有效性
    if (str == NULL || left < 0 || right < 0 || left >= right) 
    {
        chainString empty = new csNode();
        return empty;
    }
    
    int strLen = length(str);
    if (left >= strLen) 
    {
        chainString empty = new csNode();
        return empty;
    }
    
    if (right > strLen)
    {
        right = strLen;
    }
    
    chainString result = new csNode();
    chainString resultCurrent = result;
    
    chainString current = str;
    int currentIndex = 0;
    int nodeIndex = 0;
    
    while (current != NULL && currentIndex < left) 
    {
        while (nodeIndex < M && current->data[nodeIndex] != '\0' && currentIndex < left) 
        {
            nodeIndex++;
            currentIndex++;
        }
        
        if (currentIndex < left) 
        {
            current = current->next;
            nodeIndex = 0;
        }
    }
    
    if (current == NULL) {
        return result;
    }
    
    int resultNodeIndex = 0;
    while (current != NULL && currentIndex < right) 
    {
        while (nodeIndex < M && current->data[nodeIndex] != '\0' && currentIndex < right) 
        {
            if (resultNodeIndex == M) 
            {
                chainString newNode = new csNode();
                resultCurrent->next = newNode;
                newNode->pre = resultCurrent;
                resultCurrent = newNode;
                resultNodeIndex = 0;
            }
            
            resultCurrent->data[resultNodeIndex] = current->data[nodeIndex];
            resultNodeIndex++;
            nodeIndex++;
            currentIndex++;
        }
        
        if (currentIndex < right) 
        {
            current = current->next;
            nodeIndex = 0;
        }
    }
    
    return result;
}

//释放链串内存
void destroyChainString(chainString str) 
{
    chainString current = str;
    while (current != NULL) {
        chainString temp = current;
        current = current->next;
        delete temp;
    }
}


int main() 
{
    cout << "链串子串提取函数测试：" << endl;
    
    const char* testStr = "HelloWorldExample";
    chainString str = createChainString(testStr);
    
    cout << "原链串: ";
    printChainString(str);
    cout << "链串长度: " << length(str) << endl;
    
    //子串提取
    cout << "\n1. 提取子串[0, 5): ";
    chainString sub1 = subStr(str, 0, 5);
    printChainString(sub1);
    
    cout << "2. 提取子串[5, 10): ";
    chainString sub2 = subStr(str, 5, 10);
    printChainString(sub2);
    
    cout << "3. 提取子串[10, 17): ";
    chainString sub3 = subStr(str, 10, 17);
    printChainString(sub3);
    
    cout << "4. 提取子串[2, 7): ";
    chainString sub4 = subStr(str, 2, 7);
    printChainString(sub4);
    
    cout << "5. 提取子串[12, 20) (超出范围): ";
    chainString sub5 = subStr(str, 12, 20);
    printChainString(sub5);
    
    cout << "6. 提取子串[15, 16): ";
    chainString sub6 = subStr(str, 15, 16);
    printChainString(sub6);
    
    //边界情况
    cout << "\n7. 测试边界情况:" << endl;
    cout << "提取子串[0, 0): ";
    chainString sub7 = subStr(str, 0, 0);
    printChainString(sub7);
    
    cout << "提取子串[20, 25) (超出范围): ";
    chainString sub8 = subStr(str, 20, 25);
    printChainString(sub8);
    
    destroyChainString(str);
    destroyChainString(sub1);
    destroyChainString(sub2);
    destroyChainString(sub3);
    destroyChainString(sub4);
    destroyChainString(sub5);
    destroyChainString(sub6);
    destroyChainString(sub7);
    destroyChainString(sub8);
    
    return 0;
}
