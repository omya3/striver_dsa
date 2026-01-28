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

int add_1_to_ll(Node *temp)
{
    if (temp == NULL)
    {
        return 1;
    }
    int carry = add_1_to_ll(temp->next);
    temp->data += carry;
    if (temp->data == 10)
    {
        temp->data = 0;
        return 1;
    }
    return 0;
}

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

Node *main()
{
    vector<int> arr = {2, 3, 8, 7};
    Node *head = convert_array_to_ll(arr);
    if (add_1_to_ll(head))
    {
        Node *new_node = new Node(1, head);
        return new_node;
    }
    return head;
}