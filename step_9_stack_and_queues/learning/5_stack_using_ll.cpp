#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data1, Node* next1 = nullptr) {
        data = data1;
        next = next1;
    }
};

class MyStack {
private:
    Node* head;  // top of stack
    int sz;      // number of elements

public:
    MyStack() {
        head = nullptr;
        sz = 0;
    }

    void push(int x) {
        // new node points to current head, then becomes new head
        head = new Node(x, head);
        sz++;
    }

    int pop() {
        if (sz == 0 || head == nullptr) {
            // depending on problem, could throw or return -1
            return -1;
        }
        Node* temp = head;
        int val = head->data;
        head = head->next;
        delete temp;
        sz--;
        return val;
    }

    int top() {
        if (sz == 0 || head == nullptr) {
            // undefined in real stack; here return -1 for safety
            return -1;
        }
        return head->data;
    }

    bool empty() {
        return sz == 0;
    }

    int size() {
        return sz;
    }
};


int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    cout << st.top() << "\n"; // 20
    cout << st.pop() << "\n"; // 20
    cout << st.top() << "\n"; // 10
    cout << (st.empty() ? "empty" : "not empty") << "\n"; // not empty
}
