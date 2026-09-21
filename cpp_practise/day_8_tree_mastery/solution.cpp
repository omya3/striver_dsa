#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

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

int tree_height(const TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + max(tree_height(root->left), tree_height(root->right));
}

int count_nodes(const TreeNode* root)
{
    if (root == nullptr)
    {
        return 0;
    }

    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

vector<int> iterative_preorder(const TreeNode* root)
{
    vector<int> result;
    if (root == nullptr)
    {
        return result;
    }

    stack<const TreeNode*> pending;
    pending.push(root);

    while (!pending.empty())
    {
        const TreeNode* current = pending.top();
        pending.pop();
        result.push_back(current->value);

        if (current->right != nullptr)
        {
            pending.push(current->right);
        }
        if (current->left != nullptr)
        {
            pending.push(current->left);
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
    TreeNode node8(8);
    TreeNode node3(3);
    TreeNode node10(10);
    TreeNode node1(1);
    TreeNode node6(6);
    TreeNode node14(14);

    node8.left = &node3;
    node8.right = &node10;
    node3.left = &node1;
    node3.right = &node6;
    node10.right = &node14;

    vector<int> inorder_values;
    inorder(&node8, inorder_values);
    print_values("inorder: ", inorder_values);
    print_values("level order: ", level_order(&node8));

    cout << "height=" << tree_height(&node8) << '\n';
    cout << "nodes=" << count_nodes(&node8) << '\n';

    print_values("iterative preorder: ", iterative_preorder(&node8));
}

int main()
{
    tree_drill();
}
