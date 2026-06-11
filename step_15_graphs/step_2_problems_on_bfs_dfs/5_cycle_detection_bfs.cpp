#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution {
private:
    bool detectCycleBFS(int src, vector<vector<int>> &adj, vector<int> &vis) {
        // Queue stores pair of {current_node, parent_node}
        queue<pair<int, int>> q;
        
        vis[src] = 1;
        q.push({src, -1}); // Source node has no parent, so use -1
        
        while (!q.empty()) {
            auto [node, parent] = q.front();
            q.pop();
            
            for (auto neighbor : adj[node]) {
                // If neighbor is not visited, mark visited and push to queue
                if (!vis[neighbor]) {
                    vis[neighbor] = 1;
                    q.push({neighbor, node});
                }
                // If neighbor is visited and it is NOT the parent, cycle found
                else if (neighbor != parent) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    bool isCycle(int V, vector<vector<int>> &edges) {
        // 1. Convert edge list to adjacency list representation
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Since the graph is undirected
        }
        
        // 2. Initialize tracking vector for visited vertices
        vector<int> vis(V, 0);
        
        // 3. Loop through all vertices to handle disconnected components
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detectCycleBFS(i, adj, vis)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
