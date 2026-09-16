#include <iostream>
using namespace std;

typedef int datatype;

struct Node 
{
    datatype data;
    Node* next;
};

typedef Node* chainList;

Node* createCircularLinkedList() 
{
    Node* head = new Node();
    head->data = 0; 
    head->next = head; 
    return head;
}

void insertNodeCircular(Node* head, datatype value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    
    if (head->next == head) 
    { 
        newNode->next = newNode;
        head->next = newNode;
    } 
    else
    {
        Node* tail = head->next;
        while (tail->next != head->next) 
        { 
            tail = tail->next;
        }
        newNode->next = head->next; 
        tail->next = newNode; 
    }
}

// 打印循环链表
void printCircularLinkedList(Node* head) 
{
    if (head->next == head) 
    {
        cout << "空链表" << endl;
        return;
    }
    
    Node* current = head->next;
    do 
    {
        cout << current->data << " -> ";
        current = current->next;
    } 
    while (current != head->next);
    cout << "(回到开始)" << endl;
}

Node* findNodeCircular(Node* head, datatype x) 
{
    if (head->next == head) 
    {
        return nullptr; 
    }
    
    Node* current = head->next;
    do 
    {
        if (current->data == x) 
        {
            return current;
        }
        current = current->next;
    } 
    while (current != head->next);
    
    return nullptr;
}

void rcl_delete_pre(chainList &p) 
{
    if (p == nullptr) 
    {
        return;
    }
    
    Node* prev = p;
    while (prev->next != p) 
    {
        prev = prev->next;
        if (prev == p) 
        {
            return; 
        }
    }
    
    Node* prevPrev = prev;
    while (prevPrev->next != prev) 
    {
        prevPrev = prevPrev->next;
    }
    
    if (prev == p) 
    {
        return;
    }
    
    prevPrev->next = prev->next; 
    delete prev;
}

int main() 
{
    Node* head = createCircularLinkedList();
    
    //举例
    insertNodeCircular(head, 1);
    insertNodeCircular(head, 2);
    insertNodeCircular(head, 3);
    insertNodeCircular(head, 4);
    insertNodeCircular(head, 5);
    
    cout << "原始循环链表: ";
    printCircularLinkedList(head);
    
    //查找为3的节点
    Node* node3 = findNodeCircular(head, 3);
    if (node3 != nullptr) 
    {
        cout << "找到节点3，其前驱是节点2" << endl;
        cout << "删除节点3的前驱(节点2)..." << endl;
        rcl_delete_pre(node3);
        cout << "删除后链表: ";
        printCircularLinkedList(head);
    }
    
    //查找为1的节点
    Node* node1 = findNodeCircular(head, 1);
    if (node1 != nullptr) 
    {
        cout << "找到节点1，其前驱是节点5" << endl;
        cout << "删除节点1的前驱(节点5)..." << endl;
        rcl_delete_pre(node1);
        cout << "删除后链表: ";
        printCircularLinkedList(head);
    }
    
    return 0;
}
