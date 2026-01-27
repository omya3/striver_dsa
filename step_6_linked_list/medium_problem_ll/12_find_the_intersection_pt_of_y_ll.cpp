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

Node *find_intersetion_ll(Node *head1, Node *head2)
{

    if (head1 == NULL || head2 == NULL)
        return NULL;

    Node *t1 = head1;
    Node *t2 = head2;

    while (t1 != t2)
    {
        t1 = (t1 == NULL) ? head2 : t1->next;
        t2 = (t2 == NULL) ? head1 : t2->next;
    }

    return t1;
}

int main()
{
}