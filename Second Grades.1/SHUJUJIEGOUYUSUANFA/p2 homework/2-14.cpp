#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* prev;
    Node* next;
    
    Node(int value) : data(value), prev(nullptr), next(nullptr) {}
};

class DoubleCircularLinkedList
{
private:
    Node* head;
    int size;

public:
    DoubleCircularLinkedList() : head(nullptr), size(0) {}
    
    ~DoubleCircularLinkedList() 
    {
        clear();
    }
    
    void create() 
    {
        head = nullptr;
        size = 0;
    }
    
    void insert(int value) 
    {
        insertAt(size, value);
    }
    
    void insertAt(int position, int value) 
    {
        if (position < 0 || position > size) 
        {
            cout << "插入位置无效!" << endl;
            return;
        }
        
        Node* newNode = new Node(value);
        
        if (head == nullptr) 
        {
            head = newNode;
            head->next = head;
            head->prev = head;
        } 
        else if (position == 0) 
        {
            newNode->next = head;
            newNode->prev = head->prev;
            head->prev->next = newNode;
            head->prev = newNode;
            head = newNode;
        } 
        else 
        {
            Node* current = head;
            for (int i = 0; i < position; i++) 
            {
                current = current->next;
            }
            
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
        }
        
        size++;
    }
    
    //删除节点
    void deleteAt(int position) 
    {
        if (position < 0 || position >= size) 
        {
            cout << "删除位置无效!" << endl;
            return;
        }
        
        if (head == nullptr) 
        {
            cout << "链表为空!" << endl;
            return;
        }
        
        Node* nodeToDelete = head;
        
        for (int i = 0; i < position; i++) 
        {
            nodeToDelete = nodeToDelete->next;
        }
        
        if (size == 1) 
        {
            head = nullptr;
        } 
        else 
        {
            nodeToDelete->prev->next = nodeToDelete->next;
            nodeToDelete->next->prev = nodeToDelete->prev;
            
            //头节点？更新头指针
            if (nodeToDelete == head) 
            {
                head = head->next;
            }
        }
        
        delete nodeToDelete;
        size--;
    }
    
    //查找位置
    int search(int value) 
    {
        if (head == nullptr) 
        {
            return -1;
        }
        
        Node* current = head;
        for (int i = 0; i < size; i++) 
        {
            if (current->data == value) 
            {
                return i;
            }
            current = current->next;
        }
        
        return -1;
    }
    
    //位置获取节点值
    int get(int position) 
    {
        if (position < 0 || position >= size) 
        {
            cout << "位置无效!" << endl;
            return -1;
        }
        
        Node* current = head;
        for (int i = 0; i < position; i++) 
        {
            current = current->next;
        }
        
        return current->data;
    }
    
    //链表大小
    int getSize() {
        return size;
    }
    
    //链表是否为空
    bool isEmpty() 
    {
        return size == 0;
    }
    
    //清空
    void clear() 
    {
        while (!isEmpty()) 
        {
            deleteAt(0);
        }
    }
    
    //打印链表（正）
    void printForward() 
    {
        if (head == nullptr) 
        {
            cout << "链表为空" << endl;
            return;
        }
        
        Node* current = head;
        cout << "链表内容（正向）: ";
        for (int i = 0; i < size; i++) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    
    //打印链表（反）
    void printBackward() 
    {
        if (head == nullptr) 
        {
            cout << "链表为空" << endl;
            return;
        }
        
        Node* current = head->prev;
        cout << "链表内容（反向）: ";
        for (int i = 0; i < size; i++) 
        {
            cout << current->data << " ";
            current = current->prev;
        }
        cout << endl;
    }
};


int main() 
{
    DoubleCircularLinkedList list;
    
    cout << "=== 双向循环链表演示 ===" << endl;
    
    //插入元素
    cout << "\n1. 插入元素测试:" << endl;
    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.printForward();
    list.printBackward();
    
    //指定位置插入
    cout << "\n2. 在指定位置插入元素测试:" << endl;
    list.insertAt(0, 5);  
    list.insertAt(2, 15); 
    list.insertAt(list.getSize(), 50);
    list.printForward();
    
    //查询元素
    cout << "\n3. 查询元素测试:" << endl;
    int pos = list.search(15);
    if (pos != -1) 
    {
        cout << "元素15在位置: " << pos << endl;
    } 
    else
    {
        cout << "未找到元素15" << endl;
    }
    
    pos = list.search(100);
    if (pos != -1) 
    {
        cout << "元素100在位置: " << pos << endl;
    } 
    else 
    {
        cout << "未找到元素100" << endl;
    }
    
    //位置获取元素
    cout << "\n4. 根据位置获取元素测试:" << endl;
    cout << "位置0的元素: " << list.get(0) << endl;
    cout << "位置3的元素: " << list.get(3) << endl;
    
    //删除元素
    cout << "\n5. 删除元素测试:" << endl;
    cout << "删除位置2的元素:" << endl;
    list.deleteAt(2);
    list.printForward();
    
    cout << "删除第一个元素:" << endl;
    list.deleteAt(0);
    list.printForward();
    
    cout << "删除最后一个元素:" << endl;
    list.deleteAt(list.getSize() - 1);
    list.printForward();
    
    cout << "\n最终链表大小: " << list.getSize() << endl;
    
    return 0;
}
