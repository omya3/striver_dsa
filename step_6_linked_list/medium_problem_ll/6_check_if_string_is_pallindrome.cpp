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

Node *iterative_reverse_ll(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *prev = NULL;
    Node *temp = head;
    Node *front;

    while (temp != NULL)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

bool check_pallindrome_ll(Node *head)
{
    if (head == NULL && head->next == NULL)
        return true;
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *newhead = iterative_reverse_ll(slow->next);
    Node *first = head;
    Node *second = newhead;

    while (second != NULL)
    {
        if (first->data != second->data)
        {
            iterative_reverse_ll(newhead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    iterative_reverse_ll(newhead);
    return true;
}

int main()
{
}