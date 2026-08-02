class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        while (root != nullptr) { // Pro-tip: nullptr is preferred over NULL in modern C++
            // Case 1: Both nodes are greater, so LCA must be in the right subtree
            if (root->val < p->val && root->val < q->val) {
                root = root->right;
            }
            // Case 2: Both nodes are smaller, so LCA must be in the left subtree
            else if (root->val > p->val && root->val > q->val) {
                root = root->left;
            }
            // Case 3: We found the split point (or one of the nodes matches root)
            else {
                return root;
            }
        }
        
        return nullptr; // FIX: Fallback return statement to ensure all paths return a value
    }
};
