#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

node* createlickedlist()
{
    node* head=new node();
    head->data=0;
    head->next=nullptr;
    return head;
}

void Innode(node* head,int value,int position=-1)
{
    node* newnode=new node();
    newnode->data=value;
    newnode->next=nullptr;
    node* now=head;

    if(position==-1)
    {
        while(now->next!=nullptr)
        {
            now=now->next;
        }
        now->next=newnode;
    }
    else
    {
        int Innow=0;
        while(now!=nullptr&&Innow<position)
        {
            now=now->next;
            Innow++;
        }
        if(now==nullptr)
        { 
            cout<<"输入超出链表范围!";
            delete newnode;
            return;
        }
        newnode->next=now->next;
        now->next=newnode;
    }
}

void deletenode(node*head,int position)
{
    node* now=head;

    if(position<0)
    {
        cout<<"输入位置非法!";
    }
    int deposition=0;
    while(now->next!=nullptr&&deposition<position)
    {
        now=now->next;
        deposition++;
    }
    if(now->next==nullptr)
    {
        cout<<"删除位置超出链表范围!删除失败!";
        return;
    }
    node* temp=now->next;
    now->next=temp->next;
    delete temp;
}

void printnode(node* head)
{
    node* now=head->next;
    while(now!=nullptr)
    {
        cout<<now->data<<"->";
        now=now->next;
    }
    cout<<"无";
}

int countnode(node* head)
{
    int count=0;
    node* now=head->next;
    while(now!=nullptr)
    {
        count++;
        now=now->next;
    }
    return count;
}

int main()
{
    node* head=createlickedlist();
    int n,n1,n2,num,position,deposition;
    
    cout<<"请输入要输入数据的数量(数据必须为整数):";
    cin>>n;
    cout<<"请输入"<<n<<"个数据:";
    for(int i=0;i<n;i++)
    {
        int value;
        cout<<"第"<<(i+1)<<"个:";
        cin>>value;
        Innode(head,value);
    }

    cout<<"数据内容为";printnode(head);
    cout<<"\n数据总数为"<<countnode(head);
    
    while(1)
    {
        cout<<"\n退出(0),继续插入(1),单个删除(2)";
        cin>>num;
        if(num<0&&num>2)
        {
            cout<<"输入非法!请重新输入:";
            continue;
        }
        
        switch (num)
        {
        case 0:
            return 0;
            break;
        case 1:
            cout<<"请输入要插入的数量/位置/数据:";
            cin>>n1>>position;
            for(int i=0;i<n1;i++)
            {
                int value;
                cout<<"第"<<(i+1)<<"个:";
                cin>>value;
                Innode(head,value,position);
                position++;
            }
            cout<<"目前数据内容为";printnode(head);
            cout<<"\n数据总数为"<<countnode(head);
            break;
        case 2:
            cout<<"请输入要删除的数据位置(单个删除)";
            cin>>deposition;
            deletenode(head,deposition);
            cout<<"目前数据内容为";printnode(head);
            cout<<"\n数据总数为"<<countnode(head);
            break;
        default:
            break;
        }
    }
}
