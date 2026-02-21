#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data1, Node *next1 = nullptr)
    {
        data = data1;
    }
};

class MyQueue
{
private:
    Node *start; // start of queue
    Node *end;   // end of queue
    int sz;      // number of elements

public:
    MyQueue()
    {
        start = nullptr;
        end = nullptr;
        sz = 0;
    }

    void push(int x)
    {
        // new node points to current head, then becomes new head
        if (sz == 0)
        {
            start = end = new Node(x, nullptr);
        }
        else
        {
            Node *temp = new Node(x, nullptr);
            end->next = temp;
            end = temp;
        }
        sz++;
    }

    int pop()
    {
        if (sz == 0 || start == nullptr)
        {
            // depending on problem, could throw or return -1
            return -1;
        }
        Node *temp = start;
        int val = start->data;
        start = start->next;
        delete temp;
        sz--;
        return val;
    }

    int top()
    {
        if (sz == 0 || end == nullptr)
        {
            // undefined in real stack; here return -1 for safety
            return -1;
        }
        return end->data;
    }

    bool empty()
    {
        return sz == 0;
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    MyQueue qu;
    qu.push(10);
    qu.push(20);
    cout << qu.top() << "\n";                             // 20
    cout << qu.pop() << "\n";                             // 20
    cout << qu.top() << "\n";                             // 10
    cout << (qu.empty() ? "empty" : "not empty") << "\n"; // not empty
}
