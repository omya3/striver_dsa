class Solution {
private:
    // FIX 1: Pass 'count' by reference (&) so all calls update the same counter.
    // Also changed return type to int to safely bubble up the found value.
    int inorder(TreeNode* root, int k, int &count) {
        if (root == nullptr) {
            return -1;
        }

        // Search the left subtree
        int left_res = inorder(root->left, k, count);
        // If the value was already found in the left subtree, bubble it up immediately
        if (left_res != -1) {
            return left_res;
        }
        
        // Process the current node
        count++;
        if (k == count) {
            return root->val;
        }

        // Search the right subtree
        return inorder(root->right, k, count);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr) {
            return -1;
        }

        int count = 0; // Local counter initialized here
        return inorder(root, k, count);
    }
};
