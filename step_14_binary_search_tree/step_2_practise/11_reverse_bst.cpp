class Solution
{
private:
    // FIX 1: Explicitly declared each tracker as a TreeNode pointer '*'
    TreeNode *first, *middle, *last, *prev;

    void inorder(TreeNode *root)
    {
        if (root == nullptr)
            return;

        inorder(root->left);

        // A violation occurs if the current node is smaller than the previous node
        if (prev != nullptr && (root->val < prev->val))
        {
            // First violation: 'prev' is the larger swapped node, 'root' is a candidate for 'middle'
            if (first == nullptr)
            {
                first = prev;
                middle = root;
            }
            // Second violation: 'root' is the smaller swapped node
            else
            {
                last = root; // FIX 3: Fixed 'rootl' typo
            }
        }

        prev = root;
        inorder(root->right); // FIX 4: Fixed 'iorder' typo
    }

public:
    void recoverTree(TreeNode *root)
    {
        // FIX 2 & 6: Cleanly reset pointers to nullptr for every fresh test run
        first = middle = last = prev = nullptr;

        inorder(root);

        // Case 1: Swapped nodes were non-adjacent (both violations triggered)
        if (first && last)
        {
            swap(first->val, last->val); // FIX 5: Fixed 'firts' typo
        }
        // Case 2: Swapped nodes were adjacent (only one violation triggered)
        else if (first && middle)
        {
            swap(first->val, middle->val);
        }
    }
};
