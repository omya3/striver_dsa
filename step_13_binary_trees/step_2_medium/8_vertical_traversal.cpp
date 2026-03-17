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

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // col -> (row -> multiset of values)
        map<int, map<int, multiset<int>>> nodes;

        // queue of (node, (col, row))
        queue<pair<TreeNode*, pair<int,int>>> nodeQ;
        if (root)
            nodeQ.push({root, {0, 0}}); // FIX: correct brace-init

        while (!nodeQ.empty()) {
            auto p = nodeQ.front();
            nodeQ.pop();

            TreeNode* node = p.first;
            int x = p.second.first;   // column
            int y = p.second.second;  // row

            // FIX: insert into multiset, not overwrite map
            nodes[x][y].insert(node->val);

            if (node->left) {
                nodeQ.push({node->left, {x - 1, y + 1}});  // FIX: use pair brace-init
            }
            if (node->right) {
                nodeQ.push({node->right, {x + 1, y + 1}});
            }
        }

        // build result from ordered maps
        vector<vector<int>> ans;  // FIX: declare ans, not res
        for (auto &p : nodes) {
            vector<int> col;
            for (auto &q : p.second) {
                // each q.second is a multiset<int>
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};
