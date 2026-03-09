class Solution
{
public:
    vector<int> post;

    void helper(TreeNode *root)
    {
        if (!root)
            return;
        helper(root->left);
        helper(root->right);
        post.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode *root)
    {
        post.clear();
        helper(root);
        return post;
    }
};
