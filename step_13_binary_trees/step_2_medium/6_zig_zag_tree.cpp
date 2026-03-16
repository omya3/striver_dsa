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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
            return result;

        bool direction = true;
        queue<TreeNode *> nodeQueues;
        nodeQueues.push(root);

        while (!nodeQueues.empty())
        {
            int size = nodeQueues.size();
            vector<int> level(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = nodeQueues.front();
                nodeQueues.pop();

                if (direction)
                {
                    level[i] = node->val;
                }
                else
                {
                    level[size - i - 1] = node->val;
                }

                if (node->left)
                {
                    nodeQueues.push(node->left);
                }
                if (node->right)
                {
                    nodeQueues.push(node->right);
                }
            }
            direction = !direction;
            result.push_back(level);
        }
        return result;
    }
};