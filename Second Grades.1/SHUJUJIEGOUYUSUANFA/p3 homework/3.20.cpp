#include <iostream>
using namespace std;

typedef char datatype;

struct thNode 
{
    datatype data;
    thNode* lchild;
    thNode* rchild;
    int ltag;  
    int rtag;  
};

typedef thNode* thTree;

void thTree_linsert(thTree p, datatype x) 
{
    if (p == NULL) 
    {
        cout << "节点p为空,无法插入" << endl;
        return;
    }
    
    thTree newNode = new thNode;
    newNode->data = x;
    newNode->ltag = 0; 
    newNode->rtag = 0;  
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    
    if (p->ltag == 0)
    {
        newNode->lchild = p->lchild;
        p->lchild = newNode;
    } 
    else 
    {
        p->lchild = newNode;
        p->ltag = 0;
    }
}

void thTree_rinsert(thTree p, datatype x) 
{
    if (p == NULL)
    {
        cout << "节点p为空,无法插入" << endl;
        return;
    }
    
    thTree newNode = new thNode;
    newNode->data = x;
    newNode->ltag = 0;  
    newNode->rtag = 0; 
    newNode->lchild = NULL;
    newNode->rchild = NULL;
    
    if (p->rtag == 0) 
    {
        newNode->rchild = p->rchild;
        p->rchild = newNode;
    } 
    else 
    {
        p->rchild = newNode;
        p->rtag = 0;
    }
}

thTree createNode(datatype data) 
{
    thTree node = new thNode;
    node->data = data;
    node->lchild = NULL;
    node->rchild = NULL;
    node->ltag = 0;
    node->rtag = 0;
    return node;
}

void inorder(thTree root) 
{
    if (root != NULL) 
    {
        inorder(root->lchild);
        cout << root->data << " ";
        inorder(root->rchild);
    }
}

//测试
int main() 
{
    // 创建简单的线索二叉树
    //     A
    //    / \
    //   B   C
    //  / \
    // D   E
    
    thTree root = createNode('A');
    root->lchild = createNode('B');
    root->rchild = createNode('C');
    root->lchild->lchild = createNode('D');
    root->lchild->rchild = createNode('E');
    
    cout << "插入前的中序遍历: ";
    inorder(root);
    cout << endl;
    
    //节点B的左分支插入节点F
    thTree_linsert(root->lchild, 'F');
    
    //节点B的右分支插入节点G
    thTree_rinsert(root->lchild, 'G');
    
    cout << "插入后的中序遍历: ";
    inorder(root);
    cout << endl;
    
    return 0;
}
