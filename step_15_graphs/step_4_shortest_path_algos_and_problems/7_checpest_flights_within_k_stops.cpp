#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    int findCheapestCost(int n, vector<vector<int>> &edges, int src, int dst, int k)
    {
        // Step 1: Build the adjacency list using the 'edges' parameter
        vector<pair<int, int>> adj[n];
        for (auto &it : edges)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Queue stores: {stops, {node, cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while (!q.empty())
        {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // If we have already reached more than k intermediate nodes, skip
            if (stops > k)
                continue;

            for (auto iter : adj[node])
            {
                int adjNode = iter.first;
                int edW = iter.second;

                // If a cheaper path is found within the allowed node budget
                if (cost + edW < dist[adjNode] && stops <= k)
                {
                    dist[adjNode] = cost + edW;
                    q.push({stops + 1, {adjNode, cost + edW}});
                }
            }
        }

        if (dist[dst] == 1e9)
            return -1;
        return dist[dst];
    }
};
