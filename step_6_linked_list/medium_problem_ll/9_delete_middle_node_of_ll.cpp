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

Node *delete_mid_ll(Node *head)
{

    if (head == NULL || head->next == nullptr)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head->next->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    return head;
}

int main()
{
    vector<int> arr = {2, 3, 8, 7};
    Node *head = convert_array_to_ll(arr);
}