/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {

        if (root == NULL)
        {
            return 0;
        }
        unsigned long long ans = 0;
        queue<pair<TreeNode *, int>> qNodes;

        qNodes.push({root, 0});

        while (!qNodes.empty())
        {

            int size = qNodes.size();
            unsigned long long minm = qNodes.front().second;

            unsigned long long first, last;
            for (int i = 0; i < size; i++)
            {
                unsigned long long curr_id = qNodes.front().second - minm;
                TreeNode *node = qNodes.front().first;
                qNodes.pop();
                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;

                if (node->left)
                    qNodes.push({node->left, curr_id * 2 + 1});
                if (node->right)
                    qNodes.push({node->right, curr_id * 2 + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};