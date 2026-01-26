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

Node *delete_nth_node_from_last(Node *head, int n)
{
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < n; i++)
    {
        if (fast == NULL)
            return head;
        fast = fast->next;
    }

     if (fast == NULL)
    {
        Node *delnode = head;
        head = head->next;
        delete delnode;
        return head;
    }


    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }

    Node *delnode = slow->next;

    slow->next = slow->next->next;
    delete delnode;
    return head;
}