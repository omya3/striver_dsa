#include <vector>
#include <stack>
using namespace std;

class Solution
{
private:
    // 1. Added 'void' return type and corrected the adjacency list parameter type
    void toposort(int i, vector<vector<pair<int, int>>> &adj, vector<int> &vis, stack<int> &st)
    {
        vis[i] = 1;
        for (auto it : adj[i])
        {
            int v = it.first;
            if (!vis[v])
            {
                toposort(v, adj, vis, st);
            }
        }
        st.push(i);
    }

public:
    // Added 'src' parameter commonly required by this problem (defaults to 0 if not provided)
    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges, int src = 0)
    {
        // 2. Corrected to a standard 2D vector for safety
        vector<vector<pair<int, int>>> adj(V);

        // 3. Fixed loop bounds to run up to E (edge count) instead of V
        for (int i = 0; i < E; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u].push_back({v, d});
        }

        // 4. Using safe vector initialization instead of raw arrays
        vector<int> vis(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                toposort(i, adj, vis, st);
            }
        }

        vector<int> dist(V, 1e9);
        dist[src] = 0; // 5. Use the designated source node

        while (!st.empty())
        {
            // 6. Fixed: Use top() instead of front() for stack
            int node = st.top();
            st.pop();

            // 7. Critical: Only relax neighbors if the current node is reachable
            if (dist[node] != 1e9)
            {
                for (auto neigh : adj[node])
                {
                    int v = neigh.first;
                    int wt = neigh.second;

                    if (dist[node] + wt < dist[v])
                    {
                        dist[v] = dist[node] + wt;
                    }
                }
            }
        }

        // 8. Convert unreachable nodes to -1 as per typical platform standards
        for (int i = 0; i < V; i++)
        {
            if (dist[i] == 1e9)
            {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
