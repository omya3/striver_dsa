struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    void changeBT(TreeNode *root)
    {
        if (root == NULL)
            return;

        int child = 0;

        if (root->left)
            child += root->left->val;
        if (root->right)
            child += root->right->val;

        if (child >= root->val) {
            root->val = child;
        } else {
            if (root->left)
                root->left->val = root->val;
            if (root->right)
                root->right->val = root->val;
        }

        changeBT(root->left);
        changeBT(root->right);

        int tot = 0;
        if (root->left)
            tot += root->left->val;
        if (root->right)
            tot += root->right->val;
        if (root->left || root->right)
            root->val = tot;
    }
};
