class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> in;
        stack<TreeNode*> st;
        TreeNode* curr = root;

        /* 
         * =========================================================================
         * INTUITION & MENTAL MODEL:
         * =========================================================================
         * In-Order Traversal sequence: [Left -> Root -> Right]
         * 
         * Think of this code as a "Dive, Process, Pivot" machine:
         * 
         * 1. THE ENGINE: The outer loop relies on TWO things to keep running:
         *    - `curr != nullptr`: Means there is an unexplored path or subtree ahead of us.
         *    - `!st.empty()`  : Means we have bookmarked parents waiting behind us.
         * 
         * 2. THE DIVE (Phase 1 - Go Left): We delay visiting any node until its 
         *    entire left branch is complete. We dive deep left, putting every parent 
         *    on a stack "bookmark" line.
         * 
         * 3. THE PROCESS (Phase 2 - Visit Root): When we hit a dead end (`nullptr`), 
         *    we pop the stack. This gives us the leftmost available node (the "Root"). 
         *    We process its value immediately.
         * 
         * 4. THE PIVOT (Phase 3 - Step Right): After processing the Root, we shift 
         *    our focus entirely to its `right` subtree. The outer loop will reset 
         *    and start diving left on this new path.
         * =========================================================================
         */

        while (curr != nullptr || !st.empty())
        {
            // PHASE 1: Go as far left as possible
            // Keep bookmarking parents on the stack so we can return to them later.
            while (curr != nullptr)
            {
                st.push(curr);
                curr = curr->left;
            }

            // PHASE 2: Left path is exhausted. Pop the top node.
            // This node is the immediate leftmost "Root" node waiting to be handled.
            curr = st.top();
            st.pop();

            in.push_back(curr->val);     // Visit/Process the node

            // PHASE 3: Pivot to the right subtree
            // If the right child exists, the loop restarts Phase 1 on it.
            // If the right child is null, Phase 1 will be skipped next loop, 
            // and we will immediately pop the next waiting parent from the stack!
            curr = curr->right;
        }

        return in;
    }
};
