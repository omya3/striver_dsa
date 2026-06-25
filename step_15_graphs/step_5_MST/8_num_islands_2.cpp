#include <vector>
#include <vector>
#include <cstring>

using namespace std;

// 1. Your Disjoint Set Class Template
class DisjointSet {
    vector<int> rank, parent, size;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

// 2. Main Solution Class matching your template
class Solution {
private:
    // Helper function to ensure coordinates are inside the grid boundaries
    bool isValid(int r, int c, int n, int m) {
        return (r >= 0 && r < n && c >= 0 && c < m);
    }

public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n * m);
        
        // Dynamically allocating a 2D visitor array to handle constraints efficiently
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        int cnt = 0;
        vector<int> ans;
        
        // Direction arrays for traveling Up, Right, Down, Left
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        for (auto &it : operators) {
            int row = it[0];
            int col = it[1];
            
            // If cell is already processed land, count remains unchanged
            if (vis[row][col] == 1) {
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            // Checking all 4 neighboring cells
            for (int ind = 0; ind < 4; ind++) {
                int adjr = row + dr[ind];
                int adjc = col + dc[ind];
                
                if (isValid(adjr, adjc, n, m)) {
                    if (vis[adjr][adjc] == 1) {
                        // Map 2D coordinates (row, col) to a flat 1D index
                        int nodeNo = row * m + col;
                        int adjNodeNo = adjr * m + adjc;
                        
                        // If they are in different island components, merge them
                        if (ds.findUPar(nodeNo) != ds.findUPar(adjNodeNo)) {
                            cnt--;
                            ds.unionBySize(nodeNo, adjNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};
