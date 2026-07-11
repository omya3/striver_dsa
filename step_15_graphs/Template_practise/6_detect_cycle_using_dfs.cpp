#include <iostream>
using namespace std;

bool dfs_check(int i, vector < vector<int> & adj, vector<int> &vis, vector<int> &path_vis)
{
    vis[i] = 1;
    path_vis[i] = 1;

    for (int neigh : adj[i])
    {
        if (!vis[i])
        {
            if (dfs_check(neigh, adj, visited, path_vis))
            {
                return true;
            }
        }
        else if (path_vis[i])
        {
            return true;
        }
    }

    path_vis[i] = 0;
    return false;
}

bool isCyclic(int V, vector<vector<int>> &edges)
{

    vector<int> visited(V, false);
    vector<int> path_visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (dfs_check(i, adj, visited, path_visited))
        {
            return true;
        }
    }
    return false;
}
