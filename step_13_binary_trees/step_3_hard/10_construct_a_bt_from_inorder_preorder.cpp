class Solution
{
    TreeNode *buildTreeRec(vector<int> &preorder, int preStart,
                           int preEnd, vector<int> &inorder,
                           int inStart, int inEnd,
                           unordered_map<int, int> &inMap)
    {
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        int rootVal = preorder[preStart];
        TreeNode *root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];
        int numsLeft = inRoot - inStart;

        root->left = buildTreeRec(preorder,
                                  preStart + 1,
                                  preStart + numsLeft,
                                  inorder,
                                  inStart,
                                  inRoot - 1,
                                  inMap);

        root->right = buildTreeRec(preorder,
                                   preStart + numsLeft + 1,
                                   preEnd,
                                   inorder,
                                   inRoot + 1,
                                   inEnd,
                                   inMap);

        return root;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < (int)inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        return buildTreeRec(preorder, 0, (int)preorder.size() - 1,
                            inorder, 0, (int)inorder.size() - 1,
                            inMap);
    }
};
