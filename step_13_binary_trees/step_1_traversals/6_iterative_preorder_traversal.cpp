class Solution {
public:
    vector<int> pre;

    void helper(TreeNode* root) {
        if (!root) return;

        /* 
         * =========================================================================
         * INTUITION & MENTAL MODEL:
         * =========================================================================
         * Pre-Order Order: [Root -> Left -> Right]
         * 
         * 1. Process the "Root" (current node) instantly as soon as you pop it.
         * 2. Since stacks are Last-In, First-Out (LIFO), whatever is pushed LAST 
         *    gets pulled out FIRST.
         * 3. We want Left to be processed before Right. Therefore, we must push the 
         *    Right child into the stack first, and the Left child second. 
         * 4. This guarantees that the Left child sits at the very top of the stack 
         *    and gets handled next, perfectly preserving the Pre-Order flow.
         * =========================================================================
         */
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()) {
            // Pop the current node (acting as the current 'Root')
            TreeNode* node = st.top();
            st.pop();

            // STEP 1: Process Root (Add its value to the output list immediately)
            pre.push_back(node->val);

            // STEP 2: Push Right child first. 
            // It sits lower in the stack, waiting for the left paths to clear out.
            if (node->right) {
                st.push(node->right);
            }

            // STEP 3: Push Left child second. 
            // It sits on top of the stack and will be processed immediately on the next loop.
            if (node->left) {
                st.push(node->left);
            }
        }
    }

    vector<int> preorderTraversal(TreeNode *root) {
        // Clear global/class-level vector to avoid leftover data from previous test cases
        pre.clear();
        helper(root);
        return pre;
    }
};
