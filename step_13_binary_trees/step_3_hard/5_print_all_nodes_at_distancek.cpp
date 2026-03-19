#include <bits/stdc++.h>
using namespace std;



class Solution
{
    void markParents(TreeNode *root,
                     unordered_map<TreeNode *, TreeNode *> &parent_map)
    {
        if (!root)
            return;

        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            if (node->left)
            {
                parent_map[node->left] = node; // parent is current node
                q.push(node->left);
            }
            if (node->right)
            {
                parent_map[node->right] = node; // parent is current node
                q.push(node->right);
            }
        }
    }

public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        if (!root || !target)
            return {};

        unordered_map<TreeNode *, TreeNode *> parent_map;
        markParents(root, parent_map);

        unordered_map<TreeNode *, bool> visited;
        queue<TreeNode *> q;

        q.push(target);
        visited[target] = true;
        int curr_level = 0;

        while (!q.empty())
        {
            int size = q.size();
            if (curr_level == k)
                break;

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();

                // left child
                if (node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                // right child
                if (node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                // parent
                if (parent_map.count(node) && !visited[parent_map[node]])
                {
                    q.push(parent_map[node]);
                    visited[parent_map[node]] = true;
                }
            }
            curr_level++;
        }

        vector<int> result;
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            result.push_back(node->val);
        }
        return result;
    }
};
