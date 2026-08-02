class Solution {
private:
    TreeNode* createPreorder(vector<int>& preorder, int &i, int ub){

        TreeNode* node = nullptr; // Pro-tip: nullptr is preferred over NULL in modern C++
        int n = preorder.size();
        
        // CRITICAL FIX: Ensure 'i < n' is checked FIRST to avoid out-of-bounds crash
        if (i < n && preorder[i] < ub) {
            node = new TreeNode(preorder[i]);
            i += 1;
            if (i < n)
                node->left = createPreorder(preorder, i, node->val);
            if (i < n)
                node->right = createPreorder(preorder, i, ub);
            return node;
        }
        else {
            return nullptr;
        }
    }

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0; 
        return createPreorder(preorder, index, INT_MAX);
    }
};
