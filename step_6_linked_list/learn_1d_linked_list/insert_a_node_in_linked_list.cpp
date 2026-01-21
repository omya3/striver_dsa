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

Node *insert_a_node(int data, Node *head)
{
    return new Node(data, head);
}

Node *insert_a_node_at_end(int data, Node *head)
{
    if (head == NULL)
    {
        return new Node(data, nullptr);
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new Node(data, nullptr);
    return head;
}

Node *insert_a_node_at_k(int data, int k, Node *head)
{
    // Insert at position 1 (new head)
    if (k == 1)
    {
        return new Node(data, head);
    }

    Node *temp = head;
    int pos = 1;

    while (temp != nullptr && pos < k - 1)
    {
        temp = temp->next;
        pos++;
    }

    if (temp == nullptr)
    {
        return head;
    }

    Node *new_node = new Node(data);
    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

Node *insert_a_node_befor_x(int data, int x, Node *head)
{
    Node *new_node = new Node(data);

    // Case 1: Insert before head (if head->data == x)
    if (head != nullptr && head->data == x)
    {
        new_node->next = head;
        return new_node;
    }

    // Case 2: Find predecessor of node with value x
    Node *temp = head;
    while (temp != nullptr &&
           (temp->next == nullptr || temp->next->data != x))
    {
        temp = temp->next;
    }

    // x not found
    if (temp == nullptr)
    {
        delete new_node; // cleanup
        return head;
    }

    // Insert before temp->next (which has data == x)
    new_node->next = temp->next;
    temp->next = new_node;

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 8, 7};
    Node *head = convert_array_to_ll(arr);
    head = insert_a_node(100, head);
    cout << head->data;
}