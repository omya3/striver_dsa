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

Node *find_tail(Node *head)
{
    Node *tail = head;
    while (tail->next != NULL)
        tail = tail->next;
    return tail;
}

vector<pair<int, int>> find_pairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;
    Node *left = head;
    Node *right = find_tail(head);
    while (left->data < right->data)
    {
        int sum = left->data + right->data;
        if (sum == target)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < target)
            left = left->next;
        else
            right = right->prev;
    }
    return ans;
}

int main()
{
}