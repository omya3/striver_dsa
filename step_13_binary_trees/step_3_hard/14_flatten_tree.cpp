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

// solution 1
// reverse postorder method
class Solution {
TreeNode * prev = NULL;

public:
    void flatten(TreeNode* root) {
        TreeNode *node = root;
        if(node==NULL) return;

        flatten(node->right);
        flatten(node->left);

        node->right = prev;
        node->left = NULL;
        prev = node;
    }
};