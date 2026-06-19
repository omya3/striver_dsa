#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // 1. Build an optimized adjacency list for an undirected graph
        vector<vector<pair<int, int>>> adj(V);
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Add reverse edge since graph is undirected
        }

        // 2. Initialize the distance vector with infinity (1e9 is safe for 32-bit int comparisons)
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // 3. Min-Heap Priority Queue storing pairs of {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});

        // 4. Run Dijkstra exploration loop
        while (!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            // Optimization: Skip stale, longer paths already bypassed in the heap
            if (dis > dist[node]) continue;

            // Traverse adjacent neighbors
            for (const auto &neighbor : adj[node]) {
                int nextNode = neighbor.first;
                int edgeWeight = neighbor.second;

                // Relaxation condition step
                if (dist[node] + edgeWeight < dist[nextNode]) {
                    dist[nextNode] = dist[node] + edgeWeight;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }
};
