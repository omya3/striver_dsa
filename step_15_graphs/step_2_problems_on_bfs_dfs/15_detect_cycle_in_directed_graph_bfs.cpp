#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // 1. Convert the edge list into an adjacency list and calculate in-degrees
        vector<vector<int>> adjList(V);
        vector<int> indegree(V, 0);
        
        for (const auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
            indegree[v]++;
        }

        // 2. Push all nodes with an in-degree of 0 into the BFS queue
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. Process nodes via BFS
        int cnt = 0; // Track how many nodes we can successfully process
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++; // Successfully processed a node outside of any cycle

            // Reduce the in-degree of all outgoing neighbors
            for (int neighbor : adjList[node]) {
                indegree[neighbor]--;
                
                // If a neighbor's incoming edge count drops to 0, add it to the queue
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // 4. If we couldn't process all V nodes, there must be a cycle
        if (cnt == V) {
            return false; // No cycle found
        }
        return true; // Cycle detected
    }
};
