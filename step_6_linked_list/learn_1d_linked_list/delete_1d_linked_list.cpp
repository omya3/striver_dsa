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
    if (arr.empty())
        return nullptr;
    Node *new_node = new Node(arr[0], nullptr);
    Node *head = new_node;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        new_node->next = temp;
        new_node = temp;
    }
    return head;
}

Node *delete_head_of_ll(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node *delete_tail_of_ll(Node *head)
{
    if (head == NULL)
        return NULL;

    if (head->next == NULL)
    {
        delete head;
        return nullptr;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;
    delete temp->next->next;
    temp->next = nullptr;
    return head;
}

Node *delete_kth_element(Node *head, int k)
{
    if (head == NULL)
        return nullptr;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    int cnt = 0;
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node *delete_value(Node *head, int k)
{
    if (head == NULL)
        return nullptr;

    if (head->data == k)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *temp = head;
    Node *prev = nullptr;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 8, 7, 6, 5};
    Node *head = convert_array_to_ll(arr);
    cout << head->data << endl;
    head = delete_head_of_ll(head);
    cout << head->data << endl;
    head = delete_tail_of_ll(head);
    head = delete_kth_element(head, 2);
    head = delete_value(head, 2);
}