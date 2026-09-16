#include <iostream>
using namespace std;

typedef int datatype;
#define N 100

typedef struct sqNode 
{
    datatype data[N];
    int count;           //队列中元素的个数
    int rear;            //队尾
    sqNode() : count(0), rear(-1) {}
} seqQueue;

//判断队空
bool isEmpty(seqQueue& q) 
{
    return q.count == 0;
}

//判断队满
bool isFull(seqQueue& q) 
{
    return q.count == N;
}

// 入队
bool enqueue(seqQueue& q, datatype item) 
{
    if (isFull(q)) 
    {
        cout << "队列已满，无法入队!" << endl;
        return false;
    }
    
    q.rear = (q.rear + 1) % N;
    
    q.data[q.rear] = item;
    
    q.count++;
    
    return true;
}

//出队
bool dequeue(seqQueue& q, datatype& item) 
{
    if (isEmpty(q)) 
    {
        cout << "队列为空，无法出队!" << endl;
        return false;
    }
    
    int front = (q.rear - q.count + 1 + N) % N;
    
    item = q.data[front];
    
    q.count--;
    
    return true;
}

//获取队头
bool getFront(seqQueue& q, datatype& item) 
{
    if (isEmpty(q)) 
    {
        cout << "队列为空!" << endl;
        return false;
    }

    int front = (q.rear - q.count + 1 + N) % N;
    
    item = q.data[front];
    
    return true;
}

//获取元素个数
int size(seqQueue& q) 
{
    return q.count;
}

void printQueue(seqQueue& q) 
{
    if (isEmpty(q)) {
        cout << "队列为空" << endl;
        return;
    }
    
    cout << "队列内容: ";
    int front = (q.rear - q.count + 1 + N) % N;
    
    for (int i = 0; i < q.count; i++) {
        int index = (front + i) % N;
        cout << q.data[index] << " ";
    }
    cout << endl;
}


int main() 
{
    seqQueue q;
    
    cout << "队列操作测试：" << endl;
    
    cout << "队列是否为空: " << (isEmpty(q) ? "是" : "否") << endl;
    
    cout << "\n1. 测试入队操作:" << endl;
    for (int i = 1; i <= 5; i++) 
    {
        if (enqueue(q, i * 10)) 
        {
            cout << "入队成功: " << i * 10 << endl;
        }
    }
    
    cout << "当前队列大小: " << size(q) << endl;
    printQueue(q);
    
    cout << "\n2. 测试获取队头元素:" << endl;
    int frontItem;
    if (getFront(q, frontItem)) 
    {
        cout << "队头元素: " << frontItem << endl;
    }
    
    cout << "\n3. 测试出队操作:" << endl;
    for (int i = 0; i < 3; i++) 
    {
        int item;
        if (dequeue(q, item)) 
        {
            cout << "出队元素: " << item << endl;
        }
    }
    
    cout << "当前队列大小: " << size(q) << endl;
    printQueue(q);
    
    cout << "\n4. 继续入队测试循环特性:" << endl;
    for (int i = 6; i <= 8; i++) 
    {
        if (enqueue(q, i * 10)) 
        {
            cout << "入队成功: " << i * 10 << endl;
        }
    }
    
    printQueue(q);
    
    cout << "\n5. 测试队满:" << endl;
    cout << "队列是否已满: " << (isFull(q) ? "是" : "否") << endl;
    
    while (!isFull(q)) 
    {
        enqueue(q, 999);
    }
    
    cout << "队列已满: " << (isFull(q) ? "是" : "否") << endl;
    cout << "当前队列大小: " << size(q) << endl;
    
    return 0;
}
