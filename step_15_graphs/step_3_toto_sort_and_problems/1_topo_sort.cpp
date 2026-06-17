#include <vector>
#include <stack>
using namespace std;

class Solution {
private:
    // 1. Changed vis to vector reference and edges to a proper adjacency list representation
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adjList, stack<int> &st) {
        vis[node] = 1;

        // 2. Loop ONLY through the immediate neighbors of the current node
        for (int neighbor : adjList[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, adjList, st);
            }
        }
        
        // Push node to stack only after all its neighbors are fully processed
        st.push(node);
    }

public:
    vector<int> topoSort(int V, vector<vector<int>> &edges) {
        // 3. Convert the edge list into a directed adjacency list
        vector<vector<int>> adjList(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjList[u].push_back(v);
        }

        // 4. Safe vector initialization instead of raw VLAs
        vector<int> vis(V, 0);
        stack<int> st;

        // 5. Added the missing visited guard before calling DFS
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, vis, adjList, st);
            }
        }

        // Pop elements from stack to get the correct topological order
        vector<int> res;
        while (!st.empty()) {
            res.push_back(st.top());
            st.pop();
        }

        return res;
    }
};
