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

Node *convert_array_to_ll(vector<int> &arr)
{

    Node *new_node = new Node(arr[0], nullptr);
    Node *head = new_node;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[0], nullptr);
        new_node->next = temp;
        new_node = temp;
    }
    return head;
}

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

Node *recursive_reverse_ll(Node *curr)
{
    if (curr == NULL || curr->next == NULL)
        return curr;

    Node *front = curr->next;
    Node *newhead = recursive_reverse_ll(curr->next);
    front->next = curr;
    curr->next = nullptr;
    return newhead;
}

int main()
{
    vector<int> arr = {2, 3, 8, 7};
    Node *head = convert_array_to_ll(arr);
}