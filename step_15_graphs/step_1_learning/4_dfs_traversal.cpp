class Solution
{

private:
    vector<int> dfs_traversal(int node, vector<vector<int>> &adj, vector<int> &lis, vector<int> &vis)
    {
        vis[node] = 1;
        lis.push_back(node);

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                dfs_traversal(it, adj, lis, vis);
            }
        }
    }

public:
    vector<int> dfs(vector<vector<int>> &adj)
    {
        // Code here
        int v = adj.size();
        vector<int> lis;
        vector<int> vis(v, 0);
        int dfs_traversal(v, adj);
    }
};