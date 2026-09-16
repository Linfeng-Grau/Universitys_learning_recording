#include <iostream>
using namespace std;

typedef int datatype;

struct Node 
{
    datatype data;
    Node* next;
};

typedef Node* chainList;

void merge(chainList cl1, chainList cl2, chainList &cl) 
{
    Node* head = new Node();
    head->next = nullptr;
    Node* current = head;
    
    Node* p1 = cl1->next;
    Node* p2 = cl2->next;
    
    while (p1 != nullptr && p2 != nullptr) 
    {
        if (p1->data >= p2->data) 
        {
            current->next = p1;
            p1 = p1->next;
        } 
        else 
        {
            current->next = p2;
            p2 = p2->next;
        }
        current = current->next;
    }

    if (p1 != nullptr) 
    {
        current->next = p1;
    } 
    else 
    {
        current->next = p2;
    }
    
    cl = head;
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
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() 
{
    Node* cl1 = createLinkedList();
    Node* cl2 = createLinkedList();
    Node* cl = createLinkedList();
    
    //举例
    insertNode(cl1, 9);
    insertNode(cl1, 7);
    insertNode(cl1, 5);
    insertNode(cl1, 3);
    insertNode(cl1, 1);
    
    insertNode(cl2, 8);
    insertNode(cl2, 6);
    insertNode(cl2, 4);
    insertNode(cl2, 2);
    
    cout << "链表1: ";
    printLinkedList(cl1);
    
    cout << "链表2: ";
    printLinkedList(cl2);
    
    //合并
    merge(cl1, cl2, cl);
    
    cout << "合并后的链表: ";
    printLinkedList(cl);
    
    return 0;
}
