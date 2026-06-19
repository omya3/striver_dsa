#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // 1. Properly initialize the 2D vector for the adjacency list
        vector<vector<int>> adj(V);
        for (auto &it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); // Graph is unweighted and undirected
        }

        // 2. Safe vector initialization matching the return type
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            // 3. Fixed: Use front() instead of top() for standard FIFO queues
            int node = q.front();
            q.pop();

            for (auto neigh : adj[node]) {
                if (dist[node] + 1 < dist[neigh]) {
                    dist[neigh] = dist[node] + 1;
                    q.push(neigh);
                }
            }
        }

        // 4. Convert unreachable nodes from 1e9 to -1
        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};
