#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *add_two_numbers(Node *ll1, Node *ll2)
{
    Node *dummy_node = new Node(-1, nullptr);
    Node *curr = dummy_node;

    Node *t1 = ll1;
    Node *t2 = ll2;
    int carry = 0;
    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1)
            sum += t1->data;
        if (t2)
            sum += t2->data;

        Node *newNode = new Node(sum % 10, nullptr);
        carry = sum / 10;

        curr->next = newNode;
        curr = newNode;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
    }

    if (carry)
    {
        Node *newNode = new Node(1, nullptr);
        curr->next = newNode;
    }
    return dummy_node->next;
}