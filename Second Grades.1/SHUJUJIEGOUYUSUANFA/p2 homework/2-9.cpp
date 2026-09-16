#include <iostream>
using namespace std;

typedef int datatype;

struct Node {
    datatype data;
    Node* next;
};

typedef Node* chainList;

void cl_unique(chainList h) 
{
    if (h == nullptr || h->next == nullptr) 
    {
        return;
    }
    
    Node* current = h->next;
    
    while (current != nullptr && current->next != nullptr) 
    {
        if (current->data == current->next->data) 
        {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
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

void insertNode(Node* head, datatype value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

void printLinkedList(Node* head) {
    Node* current = head->next; 
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}


int main() 
{
    Node* head = createLinkedList();
//举例测试    
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head, 5);
    
    cout << "原始链表: ";
    printLinkedList(head);
    
    //删除重复节点
    cl_unique(head);
    
    cout << "去重后链表: ";
    printLinkedList(head);
    
    return 0;
}