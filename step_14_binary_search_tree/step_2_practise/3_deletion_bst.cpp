class Solution
{
private:
    TreeNode *findRight(TreeNode *Node)
    {
        while (Node->right != nullptr)
        {
            Node = Node->right;
        }
        return Node;
    }

private:
    TreeNode *helper(TreeNode *delNode)
    {
        if (delNode->left == nullptr)
        {
            return delNode->right;
        }
        if (delNode->right == nullptr)
        {
            return delNode->left;
        }

        TreeNode *extremeRight = findRight(delNode->left);
        extremeRight->right = delNode->right->left;
        delNode->right->left = delNode->left;

        return delNode->right;
    }

public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return root;
        }

        // If the root node itself is the one to be deleted
        if (root->val == key)
        {
            return helper(root);
        }

        // FIX 1 & 2: Use a separate pointer 'curr' to traverse so 'root' is preserved
        TreeNode *curr = root;

        while (curr != nullptr)
        {
            if (curr->val < key)
            {
                if (curr->right != nullptr && curr->right->val == key)
                {
                    curr->right = helper(curr->right);
                    break; // FIX 3: Stop searching once the node is deleted
                }
                else
                {
                    curr = curr->right;
                }
            }
            else
            {
                if (curr->left != nullptr && curr->left->val == key)
                {
                    curr->left = helper(curr->left);
                    break; // FIX 3: Stop searching once the node is deleted
                }
                else
                {
                    curr = curr->left;
                }
            }
        }
        return root; // FIX 4: Safely return the preserved head of the tree
    }
};
