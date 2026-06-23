#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int spanningTree(int V, vector<vector<int>> &edges)
    {
        // Step 1: Convert edges list to adjacency list representation
        // adj[u] will store {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Undirected graph
        }

        // Step 2: Prim's Algorithm Logic exactly from your screenshot
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>, greater<pair<int, int>>>
            pq;

        vector<int> vis(V, 0);
        // {wt, node}
        pq.push({0, 0});
        int sum = 0;

        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();

            int node = it.second;
            int wt = it.first;

            if (vis[node] == 1)
                continue;
            // add it to the mst
            vis[node] = 1;
            sum += wt;

            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int edW = it.second;
                if (!vis[adjNode])
                {
                    pq.push({edW, adjNode});
                }
            }
        }
        return sum;
    }
};
