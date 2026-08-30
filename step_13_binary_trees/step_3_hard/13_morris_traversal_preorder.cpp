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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            if (curr->left == nullptr)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                TreeNode *prev = curr->left;
                while (prev->right != nullptr && prev->right != curr)
                {
                    prev = prev->right;
                }

                if (prev->right == nullptr)
                {
                    prev->right = curr;
                    preorder.push_back(curr->val); // Print/record root before visiting left
                    curr = curr->left;             // Move ahead towards left and create more threads
                }
                else
                {
                    // Since the thread already exists, cut the thread
                    // and move right since left of curr already got explored.
                    prev->right = nullptr;
                    curr = curr->right;
                }
            }
        }
        return preorder;
    }
};
