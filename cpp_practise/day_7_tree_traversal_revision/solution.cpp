#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct ListNode
{
    int value;
    ListNode* next;

    explicit ListNode(int node_value) : value(node_value), next(nullptr)
    {
    }
};

void print_list(const ListNode* head)
{
    const ListNode* current = head;
    while (current != nullptr)
    {
        cout << current->value << ' ';
        current = current->next;
    }
    cout << '\n';
}

ListNode* reverse_list(ListNode* head)
{
    ListNode* previous = nullptr;
    ListNode* current = head;

    while (current != nullptr)
    {
        ListNode* next_node = current->next;
        current->next = previous;
        previous = current;
        current = next_node;
    }

    return previous;
}

void linked_list_revision()
{
    ListNode first(10);
    ListNode second(20);
    ListNode third(30);

    first.next = &second;
    second.next = &third;

    cout << "list forward: ";
    print_list(&first);

    ListNode* reversed_head = reverse_list(&first);
    cout << "list reversed: ";
    print_list(reversed_head);
    cout << '\n';
}

struct TreeNode
{
    int value;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int node_value)
        : value(node_value), left(nullptr), right(nullptr)
    {
    }
};

void preorder(const TreeNode* root, vector<int>& result)
{
    if (root == nullptr)
    {
        return;
    }

    result.push_back(root->value);
    preorder(root->left, result);
    preorder(root->right, result);
}

void inorder(const TreeNode* root, vector<int>& result)
{
    if (root == nullptr)
    {
        return;
    }

    inorder(root->left, result);
    result.push_back(root->value);
    inorder(root->right, result);
}

vector<int> level_order(const TreeNode* root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    queue<const TreeNode*> pending;
    pending.push(root);

    while (!pending.empty())
    {
        const TreeNode* current = pending.front();
        pending.pop();
        result.push_back(current->value);

        if (current->left != nullptr)
        {
            pending.push(current->left);
        }
        if (current->right != nullptr)
        {
            pending.push(current->right);
        }
    }

    return result;
}

void print_values(const string& label, const vector<int>& values)
{
    cout << label;
    for (int value : values)
    {
        cout << value << ' ';
    }
    cout << '\n';
}

void tree_drill()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);

    node1.left = &node2;
    node1.right = &node3;
    node2.left = &node4;
    node2.right = &node5;
    node3.right = &node6;

    vector<int> preorder_values;
    preorder(&node1, preorder_values);
    print_values("preorder: ", preorder_values);

    vector<int> inorder_values;
    inorder(&node1, inorder_values);
    print_values("inorder: ", inorder_values);

    print_values("level order: ", level_order(&node1));
}

int main()
{
    linked_list_revision();
    tree_drill();
}
