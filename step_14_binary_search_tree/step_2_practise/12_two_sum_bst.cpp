/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class BSTIterator
{
private:
    stack<TreeNode *> st;

    // Helper method to push a node and all of its sequential left descendants
    void pushAll(TreeNode *root)
    {
        // FIX 2: Standardized tracking using the 'root' pointer directly
        while (root != nullptr)
        {
            st.push(root);     // Push the parent node itself first
            root = root->left; // Move down to its left child
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        // FIX 1: Populate the stack with the leftmost path upon instantiation
        pushAll(root);
    }

    int next()
    {
        TreeNode *node = st.top();
        st.pop();

        // FIX 3: Cleanly pass the right child directly (pushAll handles nulls safely)
        pushAll(node->right);

        return node->val;
    }

    bool hasNext()
    {
        return !st.empty();
    }
};

class BSTIteratorRight
{
private:
    stack<TreeNode *> st;

    // Helper method to push a node and all of its sequential left descendants
    void pushAll(TreeNode *root)
    {
        // FIX 2: Standardized tracking using the 'root' pointer directly
        while (root != nullptr)
        {
            st.push(root);      // Push the parent node itself first
            root = root->right; // Move down to its left child
        }
    }

public:
    BSTIteratorRight(TreeNode *root)
    {
        // FIX 1: Populate the stack with the leftmost path upon instantiation
        pushAll(root);
    }

    int before()
    {
        TreeNode *node = st.top();
        st.pop();

        // FIX 3: Cleanly pass the right child directly (pushAll handles nulls safely)
        pushAll(node->left);

        return node->val;
    }

    bool hasBefore()
    {
        return !st.empty();
    }
};

class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == nullptr)
            return false;

        // Allocating iterators on the stack instead of 'new' to prevent memory leaks
        // and allow easy dot '.' syntax notation
        BSTIterator BST_next(root);
        BSTIteratorRight BST_before(root);

        int left = BST_next.next();
        int right = BST_before.before();

        // FIX 4: Loop must continue until pointers meet or cross, just like a standard array Two-Sum
        while (left < right)
        {
            int sum = left + right; // FIX 2: Added 'int' type declaration

            if (sum == k)
            {
                return true;
            }
            else if (sum > k)
            {
                right = BST_before.before(); // FIX 1: Works smoothly with stack instances
            }
            else
            {
                left = BST_next.next();
            }
        }
        return false; // FIX 3: Fixed 'retur' typo
    }
};
