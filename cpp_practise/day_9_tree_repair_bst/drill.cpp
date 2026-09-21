// Day 9: repair revision plus placement-focused BST syntax.
// Complete every TODO without opening solution.cpp.

// TODO 1: Add all required standard-library headers.
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    // TODO: Add int value, TreeNode* left, and TreeNode* right.
    int value;
    TreeNode *left;
    TreeNode *right;
    // TODO: Add a constructor that initializes both children to nullptr.

    // MEMORY: distinct parameter names prevent accidental self-initialization.
    explicit TreeNode(int node_value, TreeNode *left_child = nullptr,
                      TreeNode *right_child = nullptr)
        : value(node_value), left(left_child), right(right_child)
    {
    }
};

bool contains_bst(const TreeNode *root, int target)
{
    // MISTAKE FIXED: the task requested iterative search, so move one pointer.
    const TreeNode *current = root;
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

vector<int> path_to_target(const TreeNode *root, int target)
{
    vector<int> path;
    const TreeNode *current = root;

    while (current != nullptr)
    {
        path.push_back(current->value);
        if (current->value == target)
        {
            return path;
        }

        // MEMORY: smaller goes left; larger goes right.
        current = target < current->value ? current->left : current->right;
    }

    // MISTAKE FIXED: missing targets return an empty path.
    return {};
}

const TreeNode *minimum_node(const TreeNode *root)
{
    // TODO: Follow left pointers until no left child remains.
    if (root == nullptr)
    {
        // MISTAKE FIXED: `root;` is not a return statement.
        return nullptr;
    }

    const TreeNode *curr = root;
    while (curr->left != nullptr)
    {
        curr = curr->left;
    }
    return curr;
}

const TreeNode *maximum_node(const TreeNode *root)
{
    // TODO: Follow right pointers until no right child remains.
    if (root == nullptr)
    {
        return nullptr;
    }

    const TreeNode *curr = root;
    while (curr->right != nullptr)
    {
        curr = curr->right;
    }
    return curr;
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

void bst_drill()
{
    // TODO: Create stack nodes 8, 3, 10, 1, 6, and 14.
    TreeNode n1(8);
    TreeNode n2(3);
    TreeNode n3(10);
    TreeNode n4(1);
    TreeNode n5(6);
    TreeNode n6(14);

    // TODO: Connect them to match the BST in README.md.
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;

    cout << boolalpha;
    // TODO: Print search results using boolalpha.
    cout << "contains 6=" << contains_bst(&n1, 6) << '\n';
    cout << "contains 5=" << contains_bst(&n1, 5) << '\n';

    // TODO: Print the path to 6 and print "missing" for the path to 5.
    const vector<int> path_to_6 = path_to_target(&n1, 6);
    print_values("path to 6: ", path_to_6);

    const vector<int> path_to_5 = path_to_target(&n1, 5);
    cout << "path to 5: " << (path_to_5.empty() ? "missing" : "found") << '\n';

    // TODO: Print minimum and maximum values safely.
    const TreeNode *min_node = minimum_node(&n1);
    const TreeNode *max_node = maximum_node(&n1);

    // MISTAKE FIXED: check a returned pointer before dereferencing it.
    if (min_node != nullptr)
    {
        cout << "minimum=" << min_node->value << '\n';
    }
    if (max_node != nullptr)
    {
        cout << "maximum=" << max_node->value << '\n';
    }
}

int main()
{
    bst_drill();
}
