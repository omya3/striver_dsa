class Solution {
private:
    // 1. Changed return type from vector<int> to bool
    bool dfs_traversal(int node, int col, vector<int>& color, vector<vector<int>>& adj) {
        color[node] = col;

        // 2. Loop only through immediate neighbors, not all V vertices
        for (int neighbor : adj[node]) {
            // 3. Simplified check for uncolored nodes
            if (color[neighbor] == -1) {
                if (dfs_traversal(neighbor, !col, color, adj) == false) {
                    return false;
                }
            } 
            // If the neighbor is already colored with the same color, it's not bipartite
            else if (color[neighbor] == col) {
                return false;
            }
        }
        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        // Using vector instead of raw VLAs for safe initialization
        vector<int> color(v, -1);

        for (int i = 0; i < v; i++) {
            if (color[i] == -1) {
                if (dfs_traversal(i, 0, color, graph) == false) {
                    return false;
                }
            }
        }
        // 4. Added the missing return statement
        return true;
    }
};
