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
class Solution
{
public:
    int maxi = 0;
    int maxPathSum(TreeNode *root)
    {
        int sum = findMaxPathSum(root);
        return maxi;
    }

    int findMaxPathSum(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int left_sum = findMaxPathSum(root->left);
        int right_sum = findMaxPathSum(root->right);

        maxi = max(maxi, root->val + left_sum + right_sum);

        return root->val + max(left_sum, right_sum);
    }
};