class Solution
{
public:
    vector<int> in;

    void helper(TreeNode *root)
    {
        if (!root)
            return;
        helper(root->left);
        in.push_back(root->val);
        helper(root->right);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        in.clear();
        helper(root);
        return in;
    }
};
