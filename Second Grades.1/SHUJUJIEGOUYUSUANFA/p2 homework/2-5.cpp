#include <iostream>
using namespace std;

typedef int datatype;

struct Node
{
    datatype data;
    Node* next;
};

typedef Node* chainList;

Node* cl_search(chainList h,datatype x,int &ord)
{
    Node* current=h->next;
    ord=1;

    while (current!=nullptr)
    {
        if (current->data==x)
        {
            return current;
        }
        current=current->next;
        ord++;
    }

    ord=-1;
    return nullptr;
}

Node* createLinkedList()
{
    Node* head=new Node();
    head->data=0;
    head->next=nullptr;
    return head;
}

void insertNode(Node* head,datatype value)
{
    Node* newNode=new Node();
    newNode->data=value;
    newNode->next=nullptr;

    Node* current=head;
    while(current->next!=nullptr)
    {
        current=current->next;
    }
    current->next=newNode;
}

void printLinkedList(Node* head)
{
    Node* current=head->next;
    while(current!=nullptr)
    {
        cout<<current->data<<"->";
        current=current->next;
    }
    cout<<"nullptr"<<endl;
}

int main()
{
    int value;

    Node* head =createLinkedList();
    
    insertNode(head,1);
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);

    cout<<"链表内容:";
    printLinkedList(head);
    
    int ord;
    cout<<"请输入查找的值:";
    cin>>value;
    Node* result=cl_search(head,value,ord);

    if(result!=nullptr)
    {
        cout<<"";
    }
}



