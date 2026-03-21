class Solution
{
    TreeNode *buildTreePost(vector<int> &postorder, int postStart,
                            int postEnd, vector<int> &inorder,
                            int inStart, int inEnd,
                            unordered_map<int, int> &inMap)
    {
        if (postStart > postEnd || inStart > inEnd)
            return nullptr;

        // root is the last element in current postorder segment
        int rootVal = postorder[postEnd];
        TreeNode *root = new TreeNode(rootVal);

        int inRoot = inMap[rootVal];          // index of root in inorder
        int numsLeft = inRoot - inStart;      // size of left subtree

        // left subtree: first numsLeft elements in this postorder range
        root->left = buildTreePost(postorder,
                                   postStart,
                                   postStart + numsLeft - 1,
                                   inorder,
                                   inStart,
                                   inRoot - 1,
                                   inMap);

        // right subtree: remaining elements before root in postorder
        root->right = buildTreePost(postorder,
                                    postStart + numsLeft,
                                    postEnd - 1,
                                    inorder,
                                    inRoot + 1,
                                    inEnd,
                                    inMap);

        return root;
    }

public:
    // NOTE: signature should be (inorder, postorder) for this problem
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        unordered_map<int, int> inMap;
        for (int i = 0; i < (int)inorder.size(); i++)
            inMap[inorder[i]] = i;

        return buildTreePost(postorder, 0, (int)postorder.size() - 1,
                             inorder, 0, (int)inorder.size() - 1,
                             inMap);
    }
};
