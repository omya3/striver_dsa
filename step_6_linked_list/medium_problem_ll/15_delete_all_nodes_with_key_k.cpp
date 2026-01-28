#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data1, Node *next1, Node *prev1)
    {
        data = data1;
        next = next1;
        prev = prev1;
    }
};

Node *delete_node_with_k(Node *head_ref, int x)
{
    if (head_ref == NULL || *head_ref == NULL)
        return;

    Node *temp = head_ref;

    while (temp != NULL)
    {
        if (temp->data == x)
        {
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;

            // If this node is the head, move head forward
            if (temp == head_ref)
            {
                head_ref = nextNode;
            }

            // Fix the next node's prev pointer
            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }

            // Fix the previous node's next pointer
            if (prevNode != NULL)
            {
                prevNode->next = nextNode;
            }

            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head_ref;
}
int main()
{
}