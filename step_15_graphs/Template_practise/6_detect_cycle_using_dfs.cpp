#include <iostream>
#include <vector> // FIX 3: Added missing header

using namespace std;

// FIX 2: Fixed parameter names (vis) and syntax types
bool dfs_check(int i, const vector<vector<int>> &adj, vector<int> &vis, vector<int> &path_vis)
{
    vis[i] = 1;
    path_vis[i] = 1;

    for (int neigh : adj[i])
    {
        // FIX 1: Check the neighbor 'neigh', NOT the current node 'i'
        if (!vis[neigh])
        {
            if (dfs_check(neigh, adj, vis, path_vis)) // FIX 2: Passed 'vis' instead of 'visited'
            {
                return true;
            }
        }
        // FIX 1: If neighbor is already visited on the CURRENT recursive path, a cycle exists!
        else if (path_vis[neigh])
        {
            return true;
        }
    }

    path_vis[i] = 0; // Backtrack: Remove node from current path stack
    return false;
}

// FIX 2: Changed parameter name from 'edges' to 'adj' to match the interior calls
bool isCyclic(int V, const vector<vector<int>> &adj)
{
    vector<int> visited(V, 0);
    vector<int> path_visited(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!visited[i]) // Safe-guard to avoid re-checking fully processed components
        {
            if (dfs_check(i, adj, visited, path_visited))
            {
                return true;
            }
        }
    }
    return false;
}
