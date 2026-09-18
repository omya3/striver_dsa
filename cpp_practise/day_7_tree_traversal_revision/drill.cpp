// Day 7: linked-list revision and binary-tree traversal.
// Complete every TODO without opening solution.cpp or yesterday's drill.

// TODO 1: Add all required standard-library headers.
#include <iostream>
using namespace std;

// ---------- Day 6 revision ----------

struct ListNode
{
    // TODO: Add int value and ListNode* next.
    int value;
    ListNode *next;
    // TODO: Add a constructor that initializes next to nullptr.
    ListNode(int value, ListNode *next = nullptr) : value(value), next(next)
    {
    }
};

void print_list(const ListNode *head)
{
    // TODO: Traverse with a read-only node pointer and print each value.
    const ListNode *curr = head;
    while (curr != NULL)
    {
        cout << curr->value;
        curr = curr->next;
    }
    cout << endl;
}

ListNode *reverse_list(ListNode *head)
{
    // TODO: Reverse using previous, current, and next_node.
    ListNode *prev = nullptr;
    ListNode *curr = head;
    ListNode *next_node = nullptr;

    while (curr != NULL)
    {
        next_node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next_node;
    }

    return prev;
}

void linked_list_revision()
{
    // TODO: Create stack nodes 10, 20, and 30.
    ListNode n1(10);
    ListNode n2(20);
    ListNode n3(30);

    // TODO: Connect them using addresses.
    n1.next = &n2;
    n2.next = &n3;
    // TODO: Print forward, reverse, then print the returned head.
    print_list(&n1);
    ListNode *rev = reverse_list(&n1);
    print_list(rev);
    cout << '\n';
}

// ---------- Today's progression ----------

struct TreeNode
{
    // TODO: Add int value, TreeNode* left, and TreeNode* right.
    int value;
    TreeNode *left;
    TreeNode *right;
    // TODO: Add a constructor that initializes both children to nullptr.
    TreeNode(int value, TreeNode *left = nullptr, TreeNode *right = nullptr) : value(value), left(left), right(right)
    {
    }
};

void preorder(const TreeNode *root, vector<int> &result)
{
    // TODO: Base case, then node -> left -> right.
    if (root == nullptr)
        return;

    result.push_back(root->value);
    preorder(root->left, result);
    preorder(root->right, result);
}

void inorder(const TreeNode *root, vector<int> &result)
{
    // TODO: Base case, then left -> node -> right.
    if (root == nullptr)
        return;

    preorder(root->left, result);
    result.push_back(root->value);
    preorder(root->right, result);
}

vector<int> level_order(const TreeNode *root)
{
    vector<int> result;
    // TODO: Return an empty vector for a null root.
    if (root == nullptr)
        return result;

    queue<TreeNode *> q;
    q.push(root);
    // TODO: Traverse with queue<const TreeNode*>.
    while (!q.empty())
    {
        int n_nodes = q.size();

        for (int i = 0; i < n_nodes; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            result.push_back(curr->value);
            if (curr->left != nullptr)
                q.push(curr->left);
            if (curr->right != nullptr)
                q.push(curr->right);
        }
    }

    return result;
}

void print_values(const string &label, const vector<int> &values)
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
    // TODO: Create stack nodes 1 through 6.
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);

    // TODO: Connect them to match the tree in README.md.
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    // TODO: Fill and print preorder and inorder vectors.
    vector<int> result = {};
    preorder(&n1, result);
    print_values("preorder", result);

    result = {};
    preorder(&n1, result);
    print_values("inorder", result);
    // TODO: Call and print level_order().

    result = level_order(&n1);
    print_values("levelorder", result);
    cout << '\n';
}

int main()
{
    linked_list_revision();
    tree_drill();
}
