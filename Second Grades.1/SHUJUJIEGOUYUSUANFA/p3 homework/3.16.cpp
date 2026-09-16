#include <iostream>
using namespace std;

class MinHeap 
{
private:
    int* heapArray;  
    int capacity;    
    int currentSize; 

    int parent(int i) 
    { 
        return (i - 1) / 2; 
    }
    
    int leftChild(int i) 
    { 
        return 2 * i + 1; 
    }
    
    int rightChild(int i) 
    { 
        return 2 * i + 2; 
    }
    
    void swap(int& x, int& y) 
    {
        int temp = x;
        x = y;
        y = temp;
    }
    
    void heapifyUp(int index) 
    {
        while (index != 0 && heapArray[parent(index)] > heapArray[index]) 
        {
            swap(heapArray[index], heapArray[parent(index)]);
            index = parent(index);
        }
    }
    
    void heapifyDown(int index) 
    {
        int smallest = index;
        int left = leftChild(index);
        int right = rightChild(index);
        
        if (left < currentSize && heapArray[left] < heapArray[smallest])
            smallest = left;
            
        if (right < currentSize && heapArray[right] < heapArray[smallest])
            smallest = right;
            
        if (smallest != index) 
        {
            swap(heapArray[index], heapArray[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    MinHeap(int cap) 
    {
        capacity = cap;
        currentSize = 0;
        heapArray = new int[cap];
    }
    
    ~MinHeap() 
    {
        delete[] heapArray;
    }
    
    void insert(int value) 
    {
        if (currentSize == capacity) 
        {
            cout << "堆已满" << endl;
            return;
        }
        
        currentSize++;
        int index = currentSize - 1;
        heapArray[index] = value;
        
        heapifyUp(index);
    }
    
    int extractMin() 
    {
        if (currentSize <= 0) 
        {
            cout << "堆为空" << endl;
            return -1;
        }
        
        if (currentSize == 1) 
        {
            currentSize--;
            return heapArray[0];
        }
        
        int root = heapArray[0];
        
        heapArray[0] = heapArray[currentSize - 1];
        currentSize--;
        
        heapifyDown(0);
        
        return root;
    }
    
    bool isEmpty()
    {
        return currentSize == 0;
    }
    
    int size() 
    {
        return currentSize;
    }
};

void sort_heap(int a[], int n) 
{
    MinHeap heap(n);
    
    for (int i = 0; i < n; i++) 
    {
        heap.insert(a[i]);
    }
    
    for (int i = 0; i < n; i++) 
    {
        a[i] = heap.extractMin();
    }
}

int main() //测试
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    cout << "排序前的数组: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    sort_heap(arr, n);
    
    cout << "排序后的数组: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
