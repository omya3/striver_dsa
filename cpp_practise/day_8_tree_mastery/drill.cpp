// Day 8: tree syntax mastery for placements.
// Complete every TODO without opening solution.cpp.

#include <algorithm> // max
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

using namespace std;

struct TreeNode
{
    // TODO: Add int value, TreeNode* left, and TreeNode* right.
    int value;
    TreeNode *left;
    TreeNode *right;
    // MISTAKE FIXED: default nullptr values allow TreeNode node(8).
    explicit TreeNode(int node_value, TreeNode *left_child = nullptr,
                      TreeNode *right_child = nullptr)
        : value(node_value), left(left_child), right(right_child)
    {
    }
};

void inorder(const TreeNode *root, vector<int> &result)
{
    // TODO: Base case, then left -> node -> right.
    if (root == nullptr)
        return;

    inorder(root->left, result);
    result.push_back(root->value);
    // MISTAKE FIXED: recurse on root->right, not on the result vector.
    inorder(root->right, result);
}

vector<int> level_order(const TreeNode *root)
{
    // TODO: Return an empty vector for a null root.
    vector<int> result = {};
    if (root == nullptr)
        return result;
    // MISTAKE FIXED: preserve const from the function parameter.
    queue<const TreeNode *> q;
    q.push(root);

    // TODO: Traverse with queue<const TreeNode*>.
    while (!q.empty())
    {
        const int n_nodes = static_cast<int>(q.size());
        for (int i = 0; i < n_nodes; i++)
        {
            const TreeNode *curr_node = q.front();
            result.push_back(curr_node->value);
            // MISTAKE FIXED: queue uses pop(), not pop_front().
            q.pop();

            if (curr_node->left)
            {
                q.push(curr_node->left);
            }
            if (curr_node->right)
            {
                q.push(curr_node->right);
            }
        }
    }
    return result;
}

int tree_height(const TreeNode *root)
{
    // TODO: Return 0 for null; otherwise 1 + maximum subtree height.
    if (root == nullptr)
        return 0;

    int left_height = 0;
    if (root->left)
        left_height = tree_height(root->left);

    int right_height = 0;
    if (root->right)
        right_height = tree_height(root->right);

    return 1 + max(left_height, right_height);
}

int count_nodes(const TreeNode *root)
{
    // TODO: Return 0 for null; otherwise count this node and both subtrees.
    if (root == nullptr)
        return 0;

    int left_count = 0;
    if (root->left)
        left_count = count_nodes(root->left);

    int right_count = 0;
    if (root->right)
        // MISTAKE FIXED: count nodes with count_nodes(), not tree_height().
        right_count = count_nodes(root->right);

    return 1 + left_count + right_count;
}

vector<int> iterative_preorder(const TreeNode *root)
{
    // root, left, right;
    // TODO: Return an empty vector for a null root.
    vector<int> result = {};
    if (root == nullptr)
        return result;

    // MISTAKE FIXED: preserve const in the stack as well.
    stack<const TreeNode *> st;
    st.push(root);

    // TODO: Traverse with stack<const TreeNode*>.
    while (!st.empty())
    {
        const TreeNode *curr = st.top();
        st.pop();
        result.push_back(curr->value);

        if (curr->right)
            st.push(curr->right);

        if (curr->left)
            st.push(curr->left);
    }
    // TODO: Push the right child before the left child.
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
    // TODO: Create stack nodes 8, 3, 10, 1, 6, and 14.
    TreeNode n1(8);
    TreeNode n2(3);
    TreeNode n3(10);
    TreeNode n4(1);
    TreeNode n5(6);
    TreeNode n6(14);

    // TODO: Connect them to match the tree in README.md.
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;
    // TODO: Run and print every traversal and metric.
    vector<int> result = {};
    inorder(&n1, result);
    // MISTAKE FIXED: print inorder before replacing the result vector.
    print_values("inorder: ", result);

    result = level_order(&n1);
    print_values("level order: ", result);

    result = iterative_preorder(&n1);
    print_values("iterative preorder: ", result);

    cout << "height=" << tree_height(&n1) << '\n';
    cout << "nodes=" << count_nodes(&n1) << '\n';
}

int main()
{
    tree_drill();
}
