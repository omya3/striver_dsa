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

Node *find_mid_ll(Node *head)
{

    if (head == NULL || head->next == nullptr)
    {
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge_ll(Node *list1, Node *list2)
{
    Node *dummyNode = new Node(-1, nullptr);
    Node *temp = dummyNode;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else
        {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1)
    {
        temp->next = list1;
    }
    else
    {
        temp->next = list2;
    }
    return dummyNode->next;
}

Node *sort(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *middle_node = find_mid_ll(head);

    Node *right = middle_node->next;
    middle_node->next = nullptr;
    Node *left = head;

    left = sort(left);
    right = sort(right);
    return merge_ll(left, right);
}

int main() {}