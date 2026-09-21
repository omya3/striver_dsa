#include <iostream>
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

bool contains_bst(const TreeNode* root, int target)
{
    const TreeNode* current = root;
    while (current != nullptr)
    {
        if (current->value == target)
        {
            return true;
        }

        current = target < current->value ? current->left : current->right;
    }
    return false;
}

vector<int> path_to_target(const TreeNode* root, int target)
{
    vector<int> path;
    const TreeNode* current = root;

    while (current != nullptr)
    {
        path.push_back(current->value);
        if (current->value == target)
        {
            return path;
        }

        current = target < current->value ? current->left : current->right;
    }

    return {};
}

const TreeNode* minimum_node(const TreeNode* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    const TreeNode* current = root;
    while (current->left != nullptr)
    {
        current = current->left;
    }
    return current;
}

const TreeNode* maximum_node(const TreeNode* root)
{
    if (root == nullptr)
    {
        return nullptr;
    }

    const TreeNode* current = root;
    while (current->right != nullptr)
    {
        current = current->right;
    }
    return current;
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

void bst_drill()
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

    cout << boolalpha;
    cout << "contains 6=" << contains_bst(&node8, 6) << '\n';
    cout << "contains 5=" << contains_bst(&node8, 5) << '\n';

    print_values("path to 6: ", path_to_target(&node8, 6));

    const vector<int> missing_path = path_to_target(&node8, 5);
    cout << "path to 5: "
         << (missing_path.empty() ? "missing" : "found") << '\n';

    const TreeNode* minimum = minimum_node(&node8);
    const TreeNode* maximum = maximum_node(&node8);
    if (minimum != nullptr)
    {
        cout << "minimum=" << minimum->value << '\n';
    }
    if (maximum != nullptr)
    {
        cout << "maximum=" << maximum->value << '\n';
    }
}

int main()
{
    bst_drill();
}
