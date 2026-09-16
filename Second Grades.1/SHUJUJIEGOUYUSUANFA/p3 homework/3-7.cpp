#include <iostream>
using namespace std;


struct IraTreeNode 
{
    int data;           
    int leftChild;     
    int rightChild;     
};


struct IraTree 
{
    IraTreeNode* nodes; 
    int maxSize;        
    int length;        
    int root;          
};


void preorderTraversal(IraTree t, int index) 
{
    if (index < 0 || index >= t.length) 
    {
        return;
    }
    
    IraTreeNode currentNode = t.nodes[index];
    
    cout << currentNode.data << ":";
    
    if (currentNode.leftChild != -1 && currentNode.leftChild < t.length) {
        cout << t.nodes[currentNode.leftChild].data << ",";
    } else {
        cout << "-1,";
    }
    
    if (currentNode.rightChild != -1 && currentNode.rightChild < t.length) {
        cout << t.nodes[currentNode.rightChild].data << endl;
    } else {
        cout << "-1" << endl;
    }
    
    if (currentNode.leftChild != -1) 
    {
        preorderTraversal(t, currentNode.leftChild);
    }
    
    if (currentNode.rightChild != -1) 
    {
        preorderTraversal(t, currentNode.rightChild);
    }
}

void print_IraTree(IraTree t) 
{
    if (t.length == 0 || t.root == -1) 
    {
        return;
    }
    
    preorderTraversal(t, t.root);
}

    //test   
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
IraTree createTestTree() 
{
    IraTree tree;
    tree.maxSize = 10;
    tree.nodes = new IraTreeNode[tree.maxSize];

    tree.nodes[0].data = 1;
    tree.nodes[0].leftChild = 1;
    tree.nodes[0].rightChild = 2;
    
    tree.nodes[1].data = 2;
    tree.nodes[1].leftChild = 3;
    tree.nodes[1].rightChild = 4;
    
    tree.nodes[2].data = 3;
    tree.nodes[2].leftChild = -1;
    tree.nodes[2].rightChild = -1;
    
    tree.nodes[3].data = 4;
    tree.nodes[3].leftChild = -1;
    tree.nodes[3].rightChild = -1;
    
    tree.nodes[4].data = 5;
    tree.nodes[4].leftChild = -1;
    tree.nodes[4].rightChild = -1;
    
    tree.length = 5;
    tree.root = 0;
    
    return tree;
}

int main() 
{
    IraTree testTree = createTestTree();
    
    cout << "二叉树节点信息（按先根遍历顺序）：" << endl;
    cout << "格式：节点数据:左孩子数据,右孩子数据" << endl;
    print_IraTree(testTree);
    
    delete[] testTree.nodes;
    
    return 0;
}

