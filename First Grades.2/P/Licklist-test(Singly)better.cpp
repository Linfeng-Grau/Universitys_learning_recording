#include <iostream>
using namespace std;

struct Node//储存的信息
{
    int data;
    Node* next;
};

Node* createLickedlist()//创建并初始化链表内容信息
{
    Node* head=new Node();
    head->data=0;
    head->next=nullptr;
    return head;
}

void inNode(Node* head,int value,int position=-1)//输入或插入数据至链表中
{
    Node* newnode=new Node();
    newnode->data=value;
    newnode->next=nullptr;
    
    if(position==-1)//默认在尾部插入数据
    {
        Node* now=head;
        while(now->next!=nullptr)
        {
            now=now->next;
        }
        now->next=newnode;
    }
    else//在指定位置插入 
    {
        Node* now=head;
        int nowIndex=0;
        while(now!=nullptr&&nowIndex<position)
        {
            now=now->next;
            nowIndex++;
        }
        if(now==nullptr)
        {
            cout<<"超出链表范围,插入失败！";
            delete newnode;
            return;
        }
        newnode->next=now->next;//将要新插入的节点的下一个节点连接指向当前节点的下一个节点
        now->next=newnode;//将现在指向的节点连接新插入的节点，即将新插入节点插入到现指向的节点和其下一个节点中间
    }
}

void deleteNode(Node* head,int position)//删除链表中的单个指定数据
{
    if(position<0)
    {
        cout<<"无效的位置！";
        return;
    }
    
    Node* now=head;
    int nowIndex=0;
    while(now->next!=nullptr&&nowIndex<position)
    {
        now=now->next;
        nowIndex++;
    }

    if(now->next==nullptr)
    {
        cout<<"所选位置超出链表范围，删除失败！";
        return;
    }

    Node* temp=now->next;
    now->next=temp->next;
    delete temp;
}

void printLickedlist(Node*head)//打出所有的链表
{
    Node* now=head->next;
    while(now!=nullptr)
    {
        cout<<now->data<<"->";
        now=now->next;
    }
    cout<<"无";
}

int countnodes(Node* head)//计算数据个数
{
    int count=0;
    Node* now=head->next;
    while(now!=nullptr)
    {
        count++;
        now=now->next;
    }
    return count;
}

//------------------------------------------------------------------------------------------//

int main()
{
    Node* head=createLickedlist();//创建链表，并让其中数据初始化 
    int n;int n2;int n3;
    int num;
    int position;
    int deposition;

    cout<<"请输入要插入数据的数量(所有数据内容必须为整数!):";
    cin>>n;
    cout<<"请输入"<<n<<"个数据：";
    for(int i=0;i<n;i++)//最初的数据
    {
        int value;
        cin>>value;
        inNode(head,value);
    }

    cout<<"链表内容:";
    printLickedlist(head);

    int nodeCount=countnodes(head);
    cout<<"\n节点数量为"<<nodeCount;
    
    while(1)
    {
        cout<<"\n更改完成!输入0退出,输入1插入新数据,输入2删除指定单个位置的数据。";
        cin>>num;
        switch (num)
        {
        case 0:
            return 0;
            break;

        case 1:
            cout<<"请输入要插入的 数量/位置/数据(第一个数据计为位置0):";
            cin>>n2;
            cin>>position;            
            for(int i=0;i<n2;i++)
            {
               int value;
               cin>>value;
               inNode(head,value,position);
               position++;
            }
            cout<<"目前列表为";
            printLickedlist(head);
            cout<<"\n共有"<<countnodes(head)<<"个";
            break;

        case 2:
            cout<<"请输入要删除的 数据位置(第一个数据计为位置0):";
            cin>>deposition;
            deleteNode(head,deposition);
            cout<<"目前列表为";
            printLickedlist(head);
            cout<<"\n共有"<<countnodes(head)<<"个";
            break;
        default:
            break;
        }
    }
}