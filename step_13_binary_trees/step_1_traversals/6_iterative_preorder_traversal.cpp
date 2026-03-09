class Solution
{
public:
    vector<int> pre;

    void helper(TreeNode* root)
    {
        if (!root) return;

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();

            pre.push_back(node->val);
            if (node->right) st.push(node->right);
            if (node->left)  st.push(node->left);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        pre.clear();
        helper(root);
        return pre;
    }
};
