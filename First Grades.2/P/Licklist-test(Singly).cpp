#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

// 创建链表
Node* createLinkedList() 
{
    Node* head = new Node();
    head->data = 0;      // 头节点不存储实际数据
    head->next = nullptr;
    return head;
}

// 插入节点
void insertNode(Node* head, int value, int position = -1) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (position == -1) 
    { // 默认尾插
        Node* current = head;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
    } 
    else 
    { // 指定位置插入
        Node* current = head;
        int currentIndex = 0;
        while (current != nullptr && currentIndex < position) 
        {
            current = current->next;
            currentIndex++;
        }
        if (current == nullptr) {
            cout << "位置超出链表范围，插入失败！" << endl;
            delete newNode; // 防止内存泄漏
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// 删除指定位置的节点
void deleteNode(Node* head, int position) 
{
    if (position < 0) 
    {
        cout << "无效的位置！" << endl;
        return;
    }

    Node* current = head;
    int currentIndex = 0;
    while (current->next != nullptr && currentIndex < position) 
    {
        current = current->next;
        currentIndex++;
    }

    if (current->next == nullptr) 
    {
        cout << "位置超出链表范围，删除失败！" << endl;
        return;
    }

    Node* temp = current->next; // 保存要删除的节点
    current->next = temp->next; // 跳过要删除的节点
    delete temp; // 释放节点内存
}

// 打印链表
void printLinkedList(Node* head) 
{
    Node* current = head->next; // 跳过头节点
    while (current != nullptr) 
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// 统计链表中节点的数量
int countNodes(Node* head) 
{
    int count = 0;
    Node* current = head->next; // 跳过头节点
    while (current != nullptr) 
    {
        count++;
        current = current->next;
    }
    return count;
}

int main() 
{
    Node* head = createLinkedList(); // 创建链表

    int n; // 要插入的数据数量
    cout << "请输入要插入的数据数量: ";
    cin >> n;

    cout << "请输入 " << n << " 个数据: ";
    for (int i = 0; i < n; i++) 
    {
        int value;
        cin >> value; // 从标准输入读取数据
        insertNode(head, value); // 默认尾插
    }

    // 打印链表
    cout << "链表内容: ";
    printLinkedList(head);

    // 统计插入数据的数量
    int nodeCount = countNodes(head);
    cout << "链表中节点的数量: " << nodeCount << endl;

    // 测试删除指定位置的节点
    int deletePosition;
    cout << "\n请输入要删除的节点位置（从0开始）: ";
    cin >> deletePosition;
    deleteNode(head, deletePosition);

    // 再次打印链表
    cout << "删除后链表内容: ";
    printLinkedList(head);

    // 再次统计链表中节点的数量
    nodeCount = countNodes(head);
    cout << "删除后链表中节点的数量: " << nodeCount << endl;

    return 0;
}