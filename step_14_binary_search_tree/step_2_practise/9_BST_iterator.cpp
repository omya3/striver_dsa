class BSTIterator {
private:
    stack<TreeNode *> st;

    // Helper method to push a node and all of its sequential left descendants
    void pushAll(TreeNode* root) {
        // FIX 2: Standardized tracking using the 'root' pointer directly
        while (root != nullptr) {
            st.push(root);      // Push the parent node itself first
            root = root->left;  // Move down to its left child
        }
    }

public:
    BSTIterator(TreeNode* root) {
        // FIX 1: Populate the stack with the leftmost path upon instantiation
        pushAll(root);
    }
    
    int next() {
        TreeNode* node = st.top();
        st.pop();
        
        // FIX 3: Cleanly pass the right child directly (pushAll handles nulls safely)
        pushAll(node->right);
        
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};
