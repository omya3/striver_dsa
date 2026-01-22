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
        Node *temp = new Node(arr[i], nullptr);
        new_node->next = temp;
        new_node = temp;
    }
    return head;
}

int traverse_a_ll(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int length_a_ll(Node *head)
{
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

bool check_data_in_ll(Node *head, int data)
{
    int cnt = 0;
    Node *temp = head;
    bool present = false;
    while (temp != NULL)
    {
        if (data == temp->data)
        {
            present = true;
        }
        temp = temp->next;
    }
    return present;
}

int main()
{
    vector<int> arr = {2, 3, 8, 7};
    Node y = Node(arr[0], nullptr);
    cout << y.data << endl;
    cout << y.next << endl;
    Node *head = convert_array_to_ll(arr);
    int count = traverse_a_ll(head);
    int count = length_a_ll(head);
    cout << count << endl;
    bool present = check_data_in_ll(head, 7);
    cout << present << endl;
}