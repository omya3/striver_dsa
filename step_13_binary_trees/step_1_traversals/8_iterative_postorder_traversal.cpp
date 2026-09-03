class Solution {
public:
    vector<int> postorderTraversalTwoStacks(TreeNode* root) {
        vector<int> postOrder;
        if (!root) return postOrder;

        /* 
         * =========================================================================
         * INTUITION & MENTAL MODEL:
         * =========================================================================
         * Standard Pre-Order is:     [Root -> Left -> Right]
         * If we modify it slightly:  [Root -> Right -> Left]
         * If we completely reverse:  [Left -> Right -> Root]  <-- This is Post-Order!
         *
         * Stack 1 acts as our modified Pre-Order traverser (Root -> Right -> Left).
         * Stack 2 acts as a giant bucket that catches everything Stack 1 discards.
         * Because a stack is Last-In, First-Out (LIFO), pushing items into Stack 2
         * automatically reverses the entire order when we dump it out at the end.
         * =========================================================================
         */

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            
            // Catch the node in Stack 2. It sits here waiting to be reversed later.
            st2.push(node);

            // CRITICAL ORDER CHECK:
            // Since Stack is LIFO, we push Left first so that Right stays on top.
            // This ensures Stack 1 pops: Root, then Right, then Left.
            if (node->left) {
                st1.push(node->left);
            }
            if (node->right) {
                st1.push(node->right);
            }
        }

        // Stack 2 currently holds the elements in [Root, Right, Left] from top to bottom.
        // Popping them out completely flips them into [Left, Right, Root].
        while (!st2.empty()) {
            postOrder.push_back(st2.top()->val);
            st2.pop();
        }

        return postOrder;
    }
};


class Solution {
public:
    vector<int> postorderTraversalOneStack(TreeNode* root) {
        vector<int> postOrder;
        stack<TreeNode*> st;
        TreeNode* current = root;
        
        // Tracks the node we JUST finalized and popped.
        // This stops us from falling into an infinite loop on the right child.
        TreeNode* lastVisited = nullptr; 

        /* 
         * =========================================================================
         * INTUITION & MENTAL MODEL:
         * =========================================================================
         * In Post-Order, you cannot print a Parent node until its entire Left 
         * AND Right subtrees are completely finished.
         *
         * Strategy:
         * 1. Dive as deep Left as possible, bookmarking parents on the stack.
         * 2. When you hit a dead end (NULL), peek at the parent at the top of the stack.
         * 3. Before popping that parent, check its Right child:
         *    - Scenario A: It has a Right child we haven't visited yet? We must jump 
         *      to that Right child and repeat the deep Left dive.
         *    - Scenario B: No Right child exists, OR we just finished processing it 
         *      (verified because right child == lastVisited)? We can safely pop 
         *      and print the parent.
         * =========================================================================
         */

        while (current != nullptr || !st.empty()) {
            
            // STEP 1: Keep diving Left. Keep pushing parents to remember them.
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } 
            
            // STEP 2: Left path is completely exhausted. Time to look Right.
            else {
                TreeNode* peekNode = st.top();

                // Scenario A: Does a Right child exist that we haven't touched yet?
                if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                    current = peekNode->right; // Pivot to the right side and dive Left again.
                } 
                
                // Scenario B: Right side is either empty or already processed!
                else {
                    postOrder.push_back(peekNode->val); // Safe to print this parent now.
                    lastVisited = peekNode;             // Tag it as fully processed.
                    st.pop();                           // Remove it from our tracking stack.
                }
            }
        }
        return postOrder;
    }
};


