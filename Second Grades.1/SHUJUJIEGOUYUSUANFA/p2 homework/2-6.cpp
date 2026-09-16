#include <iostream>
using namespace std;

typedef int datatype;

struct Node 
{
    datatype data;
    Node* next;
};

typedef Node* chainList;

void cl_insert(chainList h, datatype x1, datatype x2) 
{
    Node* current = h;
    
    while (current != nullptr) 
    {
        if (current->data == x1) 
        {
            Node* newNode = new Node();
            newNode->data = x2;
            newNode->next = current->next;
            current->next = newNode;
            return;
        }
        current = current->next;
    }
    
    current = h;
    while (current->next != nullptr) 
    {
        current = current->next;
    }
    
    Node* newNode = new Node();
    newNode->data = x2;
    newNode->next = nullptr;
    current->next = newNode;
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
    
    insertNode(head, 10);
    insertNode(head, 20);
    insertNode(head, 30);
    
    cout << "初始链表内容: ";
    printLinkedList(head);
    
    cl_insert(head, 20, 25);
    cout << "在值为20的节点后插入值为25的节点后: ";
    printLinkedList(head);
    
    cl_insert(head, 50, 55);
    cout << "尝试在值为50的节点后插入值为55的节点后: ";
    printLinkedList(head);
    
    return 0;
}