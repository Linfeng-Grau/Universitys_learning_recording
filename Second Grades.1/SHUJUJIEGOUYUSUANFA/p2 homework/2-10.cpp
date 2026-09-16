#include <iostream>
using namespace std;

typedef int datatype;

struct Node {
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

void makeCircular(Node* head) 
{
    if (head == nullptr) return;
    
    Node* current = head;
    while (current->next != nullptr && current->next != head) {
        current = current->next;
    }
    current->next = head->next;
}

void insertNodeCircular(Node* head, datatype value) 
{
    Node* newNode = new Node();
    newNode->data = value;
    
    if (head->next == head) 
    {
        newNode->next = newNode;
        head->next = newNode;
    } else {
        Node* tail = head->next;
        while (tail->next != head->next) 
        {
            tail = tail->next;
        }
        newNode->next = head->next; 
        tail->next = newNode; 
    }
}


void printCircularLinkedList(Node* head) 
{
    if (head->next == head) {
        cout << "空链表" << endl;
        return;
    }
    
    Node* current = head->next;
    do {
        cout << current->data << " -> ";
        current = current->next;
    } while (current != head->next);
    cout << "(回到开始)" << endl;
}

//拆成两个循环链表h1和h2
//h1中包含h中序号为奇数的节点
//h2中包含h中序号为偶数的节点
void rcl_split(chainList h, chainList &h1, chainList &h2) 
{
    h1 = createCircularLinkedList();
    h2 = createCircularLinkedList();
    
    if (h == nullptr || h->next == h) 
    {
        return;
    }
    
    Node* current = h->next;
    Node* nextNode = nullptr;
    int position = 1;
    
    Node* tail1 = h1;
    Node* tail2 = h2;
    
    do 
    {
        nextNode = current->next;
        
        if (position % 2 == 1) 
        { 
            if (h1->next == h1) 
            { 
                h1->next = current;
                current->next = current;
                tail1 = current;
            } 
            else 
            {
                current->next = h1->next;
                tail1->next = current;
                tail1 = current;
            }
        } 
        else 
        { 
           
            if (h2->next == h2) 
            { 
                h2->next = current;
                current->next = current;
                tail2 = current;
            } 
            else 
            {
                current->next = h2->next;
                tail2->next = current;
                tail2 = current;
            }
        }
        
        current = nextNode;
        position++;
    } while (current != h->next && current != h);
    
    if (h1->next != h1) {
        tail1->next = h1->next;
    }
    
    if (h2->next != h2) {
        tail2->next = h2->next;
    }
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
    insertNodeCircular(head, 6);
    insertNodeCircular(head, 7);
    insertNodeCircular(head, 8);
    
    cout << "原始循环链表: ";
    printCircularLinkedList(head);
    
    Node* h1 = nullptr;
    Node* h2 = nullptr;
    
    //拆分
    rcl_split(head, h1, h2);
    
    cout << "奇数位置节点链表(h1): ";
    printCircularLinkedList(h1);
    
    cout << "偶数位置节点链表(h2): ";
    printCircularLinkedList(h2);
    
    return 0;
}
