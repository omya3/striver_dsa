class Solution
{

private:
    bool dfs_check(int node, vector<vector<int>> &adj, int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int i = 0; i < adj.size(); i++)
        {
            if (!vis[i])
            {
                if (dfs_check(i, adj, vis, pathVis) == true)
                    return true;
            }
            else if (pathVis[i])
                return true;
        }

        pathVis[node = 0];
        return false;
    }

public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        // code here
        int vis[V] = {0};
        int pathVis[V] = 0;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (dfs_check(i, adj, vis, pathVis) == true)
                    return true;
            }
        }
    }
};