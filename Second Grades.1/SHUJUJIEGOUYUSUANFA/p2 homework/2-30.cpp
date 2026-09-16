#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//广义表节点类型
enum NodeType { ATOM, LIST };

struct gNode 
{
    NodeType tag; //ATOM表示原子，LIST表示子表
    union {
        int atom;
        struct {
            gNode* hp; //头
            gNode* tp; //尾
        } ptr;
    };
    
    // 构造函数
    gNode() : tag(ATOM), atom(0) {}
    gNode(int value) : tag(ATOM), atom(value) {}
    gNode(NodeType t, gNode* h = nullptr, gNode* tl = nullptr) : tag(t) 
    {
        if (t == LIST) 
        {
            ptr.hp = h;
            ptr.tp = tl;
        } 
        else 
        {
            atom = 0;
        }
    }
};

typedef gNode* gTable;

//创建原子节点
gNode* makeAtom(int value) 
{
    gNode* node = new gNode(value);
    return node;
}

//创建子表节点
gNode* makeList(gNode* head = nullptr, gNode* tail = nullptr) 
{
    gNode* node = new gNode(LIST, head, tail);
    return node;
}

//求表长
int gt_length(gTable gt) 
{
    if (gt == nullptr) return 0;
    
    int length = 0;
    gNode* current = gt;
    
    while (current != nullptr) 
    {
        length++;
        if (current->tag == LIST) 
        {
            current = current->ptr.tp;
        } 
        else 
        {
            break; 
        }
    }
    
    return length;
}

//求原子的数量
int gt_count(gTable gt) 
{
    if (gt == nullptr) return 0;
    
    if (gt->tag == ATOM) 
    {
        return 1;
    } 
    else 
    {
        int headCount = (gt->ptr.hp != nullptr) ? gt_count(gt->ptr.hp) : 0;
        int tailCount = (gt->ptr.tp != nullptr) ? gt_count(gt->ptr.tp) : 0;
        return headCount + tailCount;
    }
}

//求深度
int gt_depth(gTable gt) 
{
    if (gt == nullptr) return 0;
    
    if (gt->tag == ATOM) 
    {
        return 0;
    } 
    else 
    {
        int headDepth = (gt->ptr.hp != nullptr) ? gt_depth(gt->ptr.hp) : 0;
        int tailDepth = (gt->ptr.tp != nullptr) ? gt_depth(gt->ptr.tp) : 0;
        return 1 + max(headDepth, tailDepth);
    }
}

void printGList(gTable gt) 
{
    if (gt == nullptr) 
    {
        cout << "()";
        return;
    }
    
    if (gt->tag == ATOM) 
    {
        cout << gt->atom;
    } 
    else 
    {
        cout << "(";
        if (gt->ptr.hp != nullptr) 
        {
            printGList(gt->ptr.hp);
        }
        if (gt->ptr.tp != nullptr) 
        {
            cout << ",";
            printGList(gt->ptr.tp);
        }
        cout << ")";
    }
}

//释放内存
void destroyGList(gTable gt) 
{
    if (gt == nullptr) return;
    
    if (gt->tag == LIST) 
    {
        if (gt->ptr.hp != nullptr) 
        {
            destroyGList(gt->ptr.hp);
        }
        if (gt->ptr.tp != nullptr) 
        {
            destroyGList(gt->ptr.tp);
        }
    }
    delete gt;
}


int main() 
{
    //创建广义表A=(1,(2,3),4)
    gNode* atom1 = makeAtom(1);
    gNode* atom2 = makeAtom(2);
    gNode* atom3 = makeAtom(3);
    gNode* atom4 = makeAtom(4);
    
    //创建子表(2, 3)
    gNode* subList23 = makeList(atom2, makeList(atom3));
    
    //创建广义表A=(1,(2,3),4)
    gNode* listA = makeList(atom1, makeList(subList23, makeList(atom4)));
    
    cout << "广义表A:";
    printGList(listA);
    cout << endl;
    
    cout << "广义表A的表长: " << gt_length(listA) << endl;
    cout << "广义表A中原子的数量: " << gt_count(listA) << endl;
    cout << "广义表A的深度: " << gt_depth(listA) << endl;
    
    //创建广义表B=(1,(2,(3,4)),5)
    gNode* atom5 = makeAtom(1);
    gNode* atom6 = makeAtom(2);
    gNode* atom7 = makeAtom(3);
    gNode* atom8 = makeAtom(4);
    gNode* atom9 = makeAtom(5);
    
    //创建子表(3,4)
    gNode* subList34 = makeList(atom7, makeList(atom8));
    
    //创建子表(2,(3,4))
    gNode* subList2_34 = makeList(atom6, makeList(subList34));
    
    //创建广义表B =(1,(2,(3,4)),5)
    gNode* listB = makeList(atom5, makeList(subList2_34, makeList(atom9)));
    
    cout << "\n广义表B:";
    printGList(listB);
    cout << endl;
    
    cout << "广义表B的表长: " << gt_length(listB) << endl;
    cout << "广义表B中原子的数量: " << gt_count(listB) << endl;
    cout << "广义表B的深度: " << gt_depth(listB) << endl;
    
    //创建空广义表
    gNode* emptyList = nullptr;
    cout << "\n空广义表: ";
    printGList(emptyList);
    cout << endl;
    cout << "空广义表的表长: " << gt_length(emptyList) << endl;
    cout << "空广义表中原子的数量: " << gt_count(emptyList) << endl;
    cout << "空广义表的深度: " << gt_depth(emptyList) << endl;
    
    //创建只有一个原子的广义表
    gNode* singleAtom = makeAtom(42);
    cout << "\n单原子广义表: ";
    printGList(singleAtom);
    cout << endl;
    cout << "单原子广义表的表长: " << gt_length(singleAtom) << endl;
    cout << "单原子广义表中原子的数量: " << gt_count(singleAtom) << endl;
    cout << "单原子广义表的深度: " << gt_depth(singleAtom) << endl;
    
    destroyGList(listA);
    destroyGList(listB);
    destroyGList(singleAtom);
    
    return 0;
}
