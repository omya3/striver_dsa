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

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node *convert_array_to_dll(vector<int> &arr)
{

    Node *head = new Node(arr[0], nullptr, nullptr);
    Node *prev = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node *insert_before_head_of_dll(Node *head, int val)
{
    Node *newhead = new Node(val, head, nullptr);
    head->back = newhead;
    newhead->back = nullptr;
    head = newhead;
    return head;
}

Node *insert_befor_tail_of_dll(Node *head)
{

    if (head == NULL)
        return nullptr;

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

Node *insert_befor_kth_element_of_dll(Node *head, int k, int val)
{

    if (k == 1)
        return insert_before_head_of_dll(head, val);

    Node *temp = head;
    int cnt = 0;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

Node *delete_head_of_dll(Node *head)
{
    if (head == NULL || head->next == NULL)
        return nullptr;

    Node *prev;
    prev = head;
    head = head->next;

    head->back = nullptr;
    delete prev;
    return head;
}

Node *delete_tail_of_dll(Node *head)
{

    if (head == NULL)
        return nullptr;

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

Node *delete_kth_element_dll(Node *head, int k)
{
    if (head == NULL)
        return nullptr;

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        if (head != nullptr)
        {
            head->back = nullptr;
        }
        delete temp;
        return head;
    }

    int cnt = 1;
    Node *temp = head;
    Node *prev = nullptr;

    while (temp != nullptr && cnt < k)
    {
        prev = temp;
        temp = temp->next;
        cnt++;
    }

    // k-th node not found
    if (temp == nullptr)
        return head;

    // Delete middle/last node
    prev->next = temp->next;
    if (temp->next != nullptr)
    {
        temp->next->back = prev;
    }
    delete temp;

    return head;
}

void delete_node_dll(Node *temp)
{
    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        delete temp;
        return;
    }

    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    delete temp;
}

int main()
{

    vector<int> arr = {2, 3, 8, 7};
    Node y = Node(arr[0], nullptr, nullptr);
    cout << y.data << endl;
    cout << y.next << endl;
    Node *head = convert_array_to_dll(arr);
    cout << head->data << endl;
    head = delete_head_of_dll(head);
    cout << head->data << endl;
    head = delete_tail_of_dll(head);
}