#include <vector>

using namespace std;

class Solution
{
private:
    bool detectCycleDFS(int src, int parent, vector<vector<int>> &adj, vector<int> &vis)
    {
        vis[src] = 1;

        for (auto neighbor : adj[src])
        {
            // If neighbor is not visited, recursively call DFS
            if (!vis[neighbor])
            {
                // Fixed: Check and propagate the true value if a cycle is found deeper down
                if (detectCycleDFS(neighbor, src, adj, vis)) 
                {
                    return true;
                }
            }
            // If neighbor is visited and it is NOT the parent, a cycle is found
            else if (neighbor != parent)
            {
                return true;
            }
        }
        return false; // Fixed: added missing semicolon
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges)
    {
        // 1. Convert edge list to adjacency list representation
        vector<vector<int>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }

        // 2. Initialize tracking vector for visited vertices
        vector<int> vis(V, 0);

        // 3. Loop through all vertices to handle disconnected components
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                if (detectCycleDFS(i, -1, adj, vis))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
