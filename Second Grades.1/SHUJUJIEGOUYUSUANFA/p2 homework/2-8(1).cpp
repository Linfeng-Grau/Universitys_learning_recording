#include <iostream>
using namespace std;

typedef int datatype;

const int MAXSIZE = 100;
typedef struct 
{
    datatype data[MAXSIZE];
    int length;               
} seqList;

void merge(seqList sl1, seqList sl2, seqList &sl) 
{
    int i = 0, j = 0, k = 0;
    
    while (i < sl1.length && j < sl2.length) 
    {
        if (sl1.data[i] >= sl2.data[j]) 
        {
            sl.data[k] = sl1.data[i];
            i++;
        } 
        else 
        {
            sl.data[k] = sl2.data[j];
            j++;
        }
        k++;
    }
    
    while (i < sl1.length) 
    {
        sl.data[k] = sl1.data[i];
        i++;
        k++;
    }
    
    while (j < sl2.length) 
    {
        sl.data[k] = sl2.data[j];
        j++;
        k++;
    }
    
    sl.length = k;
}

void printSeqList(seqList sl) 
{
    for (int i = 0; i < sl.length; i++) 
    {
        cout << sl.data[i] << " ";
    }
    cout << endl;
}
//举例
int main() 
{
    seqList sl1, sl2, sl;
    
    sl1.length = 5;
    sl1.data[0] = 9;
    sl1.data[1] = 7;
    sl1.data[2] = 5;
    sl1.data[3] = 3;
    sl1.data[4] = 1;
    
    sl2.length = 4;
    sl2.data[0] = 8;
    sl2.data[1] = 6;
    sl2.data[2] = 4;
    sl2.data[3] = 2;
    
    cout << "顺序表1: ";
    printSeqList(sl1);
    
    cout << "顺序表2: ";
    printSeqList(sl2);
    
    merge(sl1, sl2, sl);
    
    cout << "合并后的顺序表: ";
    printSeqList(sl);
    
    return 0;
}
