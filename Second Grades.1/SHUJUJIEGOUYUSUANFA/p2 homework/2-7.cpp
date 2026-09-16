#include <iostream>
using namespace std;

typedef int datatype;

struct Node 
{
    datatype data;
    Node* next;
};

typedef Node* chainList;

void cl_delete(chainList h, datatype x) 
{
    Node* current = h;
    
    while (current->next != nullptr) 
    {
        if (current->next->data == x) 
        {
            Node* nodeToDelete = current->next;
            
            current->next = nodeToDelete->next;
            
            delete nodeToDelete;
        } 
        else 
        {
            current = current->next;
        }
    }
}

Node* createLinkedList() 
{
    Node* head = new Node();
    head->data = 0;      
    head->next = nullptr;
    return head;
}

void insertNode(Node* head, datatype value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    Node* current = head;
    while (current->next != nullptr) 
    {
        current = current->next;
    }
    current->next = newNode;
}

void printLinkedList(Node* head) 
{
    Node* current = head->next; 
    while (current != nullptr) 
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

int main() 
{
    Node* head = createLinkedList();
    
    //测试数据，有重复值
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    insertNode(head, 20);
    insertNode(head, 40);
    insertNode(head, 20);
    insertNode(head, 50);
    
    cout << "初始链表内容: ";
    printLinkedList(head);
    
    //删除20的节点
    cl_delete(head, 20);
    cout << "删除所有值为20的节点后: ";
    printLinkedList(head);
    
    //再插入20
    insertNode(head, 20);
    insertNode(head, 20);
    cout << "再次插入两个20后: ";
    printLinkedList(head);
    
    //再次删除为20的节点
    cl_delete(head, 20);
    cout << "再次删除所有值为20的节点后: ";
    printLinkedList(head);
    
    return 0;
}
