class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        // Fix 1: Handle the edge case where the tree is completely empty
        if (root == nullptr)
        {
            return new TreeNode(val);
        }

        TreeNode *curr = root;

        // Fix 2: Loop based on the traversal pointer (or use while(true))
        while (curr)
        {

            // Fix 3: Changed 'k' to 'val' to match the function parameter
            if (curr->val < val)
            {
                if (curr->right != nullptr)
                {
                    curr = curr->right;
                }
                else
                {
                    curr->right = new TreeNode(val);
                    break; // Fix 4: Exit the loop after successful insertion
                }
            }
            else
            {
                if (curr->left != nullptr)
                {
                    curr = curr->left;
                }
                else
                {
                    curr->left = new TreeNode(val);
                    break; // Fix 4: Exit the loop after successful insertion
                }
            }
        }
        return root;
    }
};
