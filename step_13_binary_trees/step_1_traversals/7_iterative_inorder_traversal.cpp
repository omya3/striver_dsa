class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> in;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while (curr != nullptr || !st.empty())
        {
            // go as far left as possible
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            in.push_back(curr->val);     // visit node

            // then go to right subtree
            curr = curr->right;
        }

        return in;
    }
};
