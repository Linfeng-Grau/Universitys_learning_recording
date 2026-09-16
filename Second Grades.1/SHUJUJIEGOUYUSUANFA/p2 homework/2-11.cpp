#include <iostream>
using namespace std;

typedef struct node 
{
    int a, e;      
    node *next;
} *poly;

poly createNode(int a, int e) 
{
    poly newNode = new node;
    newNode->a = a;
    newNode->e = e;
    newNode->next = nullptr;
    return newNode;
}

poly add(poly p1, poly p2) 
{
    poly result = nullptr, tail = nullptr;

    while (p1 != nullptr && p2 != nullptr) 
    {
        if (p1->e == p2->e) 
        {
            int sum = p1->a + p2->a;
            if (sum != 0) 
            {
                poly newNode = createNode(sum, p1->e);
                if (result == nullptr) 
                {
                    result = newNode;
                    tail = newNode;
                } 
                else 
                {
                    tail->next = newNode;
                    tail = newNode;
                }
            }
            p1 = p1->next;
            p2 = p2->next;
        } 
        else if (p1->e > p2->e) 
        {
            poly newNode = createNode(p1->a, p1->e);
            if (result == nullptr) 
            {
                result = newNode;
                tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                tail = newNode;
            }
            p1 = p1->next;
        } 
        else 
        {
            poly newNode = createNode(p2->a, p2->e);
            if (result == nullptr) 
            {
                result = newNode;
                tail = newNode;
            } 
            else 
            {
                tail->next = newNode;
                tail = newNode;
            }
            p2 = p2->next;
        }
    }

    while (p1 != nullptr) 
    {
        poly newNode = createNode(p1->a, p1->e);
        if (result == nullptr) 
        {
            result = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
        p1 = p1->next;
    }

    while (p2 != nullptr) 
    {
        poly newNode = createNode(p2->a, p2->e);
        if (result == nullptr) 
        {
            result = newNode;
            tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            tail = newNode;
        }
        p2 = p2->next;
    }

    return result;
}

// 多项式乘法
poly mul(poly p1, poly p2) 
{
    poly result = nullptr;

    while (p1 != nullptr) 
    {
        poly temp = nullptr, tail = nullptr;
        poly p2Current = p2;

        while (p2Current != nullptr) 
        {
            int newA = p1->a * p2Current->a;
            int newE = p1->e + p2Current->e;
            poly newNode = createNode(newA, newE);

            if (temp == nullptr) {
                temp = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            p2Current = p2Current->next;
        }

        result = add(result, temp);
        p1 = p1->next;
    }

    return result;
}

void printPoly(poly p) 
{
    while (p != nullptr) 
    {
        cout << p->a << "x^" << p->e;
        if (p->next != nullptr) 
        {
            cout << " + ";
        }
        p = p->next;
    }
    cout << endl;
}

int main() 
{
    //示例多项式P1(x)=3x^2+2x^1+1x^0
    poly p1 = createNode(3, 2);
    p1->next = createNode(2, 1);
    p1->next->next = createNode(1, 0);

    //示例多项式P2(x)=2x^1+1x^0
    poly p2 = createNode(2, 1);
    p2->next = createNode(1, 0);

    cout << "P1(x) = ";
    printPoly(p1);
    cout << "P2(x) = ";
    printPoly(p2);

    //多项式加法
    poly sum = add(p1, p2);
    cout << "P1(x) + P2(x) = ";
    printPoly(sum);

    //多项式乘法
    poly product = mul(p1, p2);
    cout << "P1(x) * P2(x) = ";
    printPoly(product);

    return 0;
}