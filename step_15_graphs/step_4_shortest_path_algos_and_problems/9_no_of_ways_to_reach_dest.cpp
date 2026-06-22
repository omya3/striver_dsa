#include <vector>
#include <queue>

using namespace std;

class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // Step 1: Fix the compilation error by using a vector of pairs
        // adj[u] will store pairs of {neighbor, weight}
        vector<vector<pair<int, int>>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time}); // Undirected graph
        }

        // Step 2: Use Priority Queue to ensure path counts are accurate
        // Stores pairs of {distance, node} ordered by smallest distance first
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        
        // Use long long to prevent integer overflow during distance addition
        vector<long long> dist(V, 1e18);
        vector<long long> ways(V, 0);
        long long mod = 1e9 + 7;

        // Base case setup
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Optimization: Skip processing if we already found a shorter path to this node
            if (dis > dist[node]) continue;

            for (auto& it : adj[node]) {
                int adjNode = it.first;
                long long edW = it.second;

                // Condition 1: Found a strictly shorter path
                if (dis + edW < dist[adjNode]) {
                    dist[adjNode] = dis + edW;
                    ways[adjNode] = ways[node]; // Overwrite with new path count
                    pq.push({dist[adjNode], adjNode});
                }
                // Condition 2: Found an alternative path with the exact same shortest distance
                else if (dis + edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[V - 1];
    }
};
