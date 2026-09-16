#include <iostream>
using namespace std;

typedef int datatype;

struct DNode {
    datatype data;
    DNode* prev;
    DNode* next;
};

typedef DNode* dchainList;

DNode* createDoublyLinkedList() 
{
    DNode* head = new DNode();
    head->data = 0;
    head->prev = nullptr;
    head->next = nullptr;
    return head;
}

void insertNodeDoubly(DNode* head, datatype value) 
{
    DNode* newNode = new DNode();
    newNode->data = value;
    newNode->next = nullptr;
    
    DNode* current = head;
    while (current->next != nullptr) 
    {
        current = current->next;
    }
    
    current->next = newNode;
    newNode->prev = current;
}

void printDoublyLinkedList(DNode* head) 
{
    DNode* current = head->next; 
    while (current != nullptr) 
    {
        cout << current->data << " <-> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

bool dcl_swap(dchainList &h, datatype x) 
{
    if (h == nullptr || h->next == nullptr) 
    {
        return false; 
    }

    DNode* current = h->next; 
    while (current != nullptr && current->data != x) 
    {
        current = current->next;
    }
    
    if (current == nullptr) 
    {
        return false;
    }
    
    if (current->prev == h) 
    {
        return false;
    }
    
    DNode* prevNode = current->prev; 
    DNode* nextNode = current->next; 
    DNode* prevPrevNode = prevNode->prev;
    
    if (prevPrevNode != nullptr) 
    {
        prevPrevNode->next = current;
    }
    current->prev = prevPrevNode;
    
    current->next = prevNode;
    prevNode->prev = current;
    
    prevNode->next = nextNode;
    if (nextNode != nullptr) 
    {
        nextNode->prev = prevNode;
    }
    
    if (prevNode == h->next)
    {
        h->next = current;
    }
    
    return true;
}

int main() 
{
    DNode* head = createDoublyLinkedList();
    
    insertNodeDoubly(head, 1);
    insertNodeDoubly(head, 2);
    insertNodeDoubly(head, 3);
    insertNodeDoubly(head, 4);
    insertNodeDoubly(head, 5);
    
    cout << "原始双向链表: ";
    printDoublyLinkedList(head);
    
    cout << "尝试交换值为3的节点与其前驱节点..." << endl;
    if (dcl_swap(head, 3)) 
    {
        cout << "交换成功!" << endl;
    } 
    else 
    {
        cout << "交换失败!" << endl;
    }
    cout << "交换后链表: ";
    printDoublyLinkedList(head);
    
    cout << "尝试交换值为1的节点与其前驱节点..." << endl;
    if (dcl_swap(head, 1)) 
    {
        cout << "交换成功!" << endl;
    } 
    else 
    {
        cout << "交换失败(第一个节点没有前驱)!" << endl;
    }
    cout << "链表状态: ";
    printDoublyLinkedList(head);
    
    cout << "尝试交换值为10的节点与其前驱节点..." << endl;
    if (dcl_swap(head, 10)) 
    {
        cout << "交换成功!" << endl;
    } 
    else 
    {
        cout << "交换失败(未找到值为10的节点)!" << endl;
    }
    cout << "链表状态: ";
    printDoublyLinkedList(head);
    
    return 0;
}
