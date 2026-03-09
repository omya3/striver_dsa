class Solution
{
public:
    vector<int> pre;

    void helper(TreeNode* root) {
        if (!root) return;
        pre.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        pre.clear();
        helper(root);
        return pre;
    }
};
