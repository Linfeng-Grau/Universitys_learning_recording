#include <iostream>
using namespace std;

struct IraTreeNode
{
    int data;
    int leftchild;
    int rightchild;
};

struct IraTree
{
    IraTreeNode* nodes;
    int maxsize;
    int length;
    int root;
};

int count0(IraTree t)
{
    if(t.root==-1||t.length==0)
    {
        return 0;
    }

    int count=0;
    for(int i=0;i<t.length;i++)
    {
        if(t.nodes[i].data!=0)
        {
            if(t.nodes[i].leftchild==-1&&t.nodes[i].rightchild==-1)
            {
                count++;
            }
        }
    }

    return count;
}

int count1(IraTree t)
{
    if(t.root==-1||t.length==0)
    {
        return 0;
    }

    int count=0;
    for(int i=0;i<t.length;i++)
    {
        if(t.nodes[i].data!=0)
        {
            bool hasLeft=(t.nodes[i].leftchild!=-1);
            bool hasRight=(t.nodes[i].rightchild!=-1);

            if((hasLeft&&!hasRight)||(!hasLeft&&hasRight))
            {
                count++;
            }
        }
    }

    return count;
}

int count2(IraTree t)
{
    if(t.root==-1||t.length==0)
    {
        return 0;
    }

    int count=0;
    for(int i=0;i<t.length;i++)
    {
        if(t.nodes[i].data!=0)
        {
            if(t.nodes[i].leftchild!=-1&&t.nodes[i].rightchild!=-1)
            {
                count++;
            }
        }
    }

    return count;
}

int getheight(IraTree t,int index)
{
    if(index==-1||index>=t.length)
    {
        return 0;
    }

    int leftheight = getheight(t, t.nodes[index].leftchild);
    int rightheight = getheight(t, t.nodes[index].rightchild);

    return 1+(leftheight>rightheight?leftheight:rightheight);
}

int height(IraTree t)
{
    if(t.root==-1||t.length==0)
    {
        return 0;
    }

    return getheight(t,t.root);
}

int main()//测试
{
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    
    IraTree tree;
    tree.maxsize = 10;
    tree.nodes = new IraTreeNode[tree.maxsize];
    
    tree.nodes[0].data = 1;
    tree.nodes[0].leftchild = 1;
    tree.nodes[0].rightchild = 2;
    
    tree.nodes[1].data = 2;
    tree.nodes[1].leftchild = 3;
    tree.nodes[1].rightchild = 4;
    
    tree.nodes[2].data = 3;
    tree.nodes[2].leftchild = -1;
    tree.nodes[2].rightchild = -1;
    
    tree.nodes[3].data = 4;
    tree.nodes[3].leftchild = -1;
    tree.nodes[3].rightchild = -1;
    
    tree.nodes[4].data = 5;
    tree.nodes[4].leftchild = -1;
    tree.nodes[4].rightchild = -1;
    
    tree.length = 5;
    tree.root = 0;
    
    cout << "叶节点数量: " << count0(tree) << endl;
    cout << "度为1的节点数量: " << count1(tree) << endl;
    cout << "度为2的节点数量: " << count2(tree) << endl;
    cout << "树的高度: " << height(tree) << endl;
    
    delete[] tree.nodes;
    return 0;    
}