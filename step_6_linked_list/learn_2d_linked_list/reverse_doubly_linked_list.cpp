#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1, Node *next1, Node *back1)
    {
        data = data1;
        next = next1;
        back = back1;
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

Node *reverse_dll(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *last = nullptr;
    Node *current = head;

    while (current != NULL)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }

    return last->back;
}

int main()
{
    vector<int> arr = {2, 3, 8, 7};
    Node *head = convert_array_to_ll(arr);
    head = reverse_dll(head);
}