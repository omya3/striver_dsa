class Solution
{
    int findHeightLeft(TreeNode *root)
    {
        int height = 0;
        while (root != NULL)
        {
            height++;
            root = root->left;
        }
        return height;
    }

    int findHeightRight(TreeNode *root)
    {
        int height = 0;
        while (root != NULL)
        {
            height++;
            root = root->right;
        }
        return height;
    }

public:
    int countNodes(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = findHeightLeft(root);  // from root
        int rh = findHeightRight(root); // from root

        // Perfect subtree
        if (lh == rh)
        {
            return (1 << lh) - 1; // 2^lh - 1
        }

        // Otherwise recurse on children
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
