#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size(); // Determine the number of vertices
        vector<int> visited(v, 0);
        vector<int> bfs_result;
        queue<int> q;
        
        // Start BFS from the first node (assuming node 0)
        visited[0] = 1;
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            bfs_result.push_back(node); // Fixed: changed 'i' to 'node'
            
            for (auto it : adj[node]) { // Iterating through neighbors
                if (!visited[it]) {     // Fixed: changed 'x' to 'it'
                    q.push(it);         // Fixed: changed 'i' to 'it'
                    visited[it] = 1;    // Fixed: changed 'i' to 'it'
                }
            }
        }
        return bfs_result;
    }
};

int main() {
    int v, e;
    if (!(cin >> v >> e)) return 0;
    
    vector<vector<int>> adj(v);
    for (int i = 0; i < e; i++) {
        int u, w;
        cin >> u >> w;
        adj[u].push_back(w);
        adj[w].push_back(u); // Remove this line if the graph is directed
    }
    
    Solution obj;
    vector<int> ans = obj.bfs(adj);
    
    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}
