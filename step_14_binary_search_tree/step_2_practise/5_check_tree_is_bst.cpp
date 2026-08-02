class Solution
{
private:
    // Use long long boundaries to prevent INT_MIN/INT_MAX overflow bugs
    bool checkValidity(TreeNode *root, long long left, long long right)
    {
        // Base case: An empty node or leaf's child is always a valid BST
        if (root == NULL)
            return true;

        // Current node value must fall strictly between left and right limits
        if (root->val <= left || root->val >= right)
        {
            return false;
        }

        // Recursively validate left and right subtrees
        // Passing the NULL children up will correctly return true
        return checkValidity(root->left, left, root->val) &&
               checkValidity(root->right, root->val, right);
    }

public:
    bool isValidBST(TreeNode *root)
    {
        // Use long long limits for the initial root call
        return checkValidity(root, LLONG_MIN, LLONG_MAX);
    }
};
