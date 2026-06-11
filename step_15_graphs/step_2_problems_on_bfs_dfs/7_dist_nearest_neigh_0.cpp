#include <vector>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // vis keeps track of visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));
        // dis will store the final shortest distances
        vector<vector<int>> dis(n, vector<int>(m, 0));

        // Queue stores tuple: {row, col, distance}
        queue<tuple<int, int, int>> q;

        // 1. Initialize: Find all 0s and push them as BFS starting sources
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j, 0});
                    vis[i][j] = 1; // Mark 0s as visited
                }
            }
        }

        // Direction arrays for traveling Up, Right, Down, Left
        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};

        // 2. Perform Multi-Source BFS
        while (!q.empty()) {
            auto [node_r, node_c, node_d] = q.front();
            q.pop();
            
            dis[node_r][node_c] = node_d;

            for (int k = 0; k < 4; k++) {
                int neigh_r = node_r + del_row[k];
                int neigh_c = node_c + del_col[k];

                // Boundary check and visited check
                if (neigh_r >= 0 && neigh_r < n && neigh_c >= 0 && neigh_c < m) {
                    if (!vis[neigh_r][neigh_c]) {
                        q.push({neigh_r, neigh_c, node_d + 1});
                        vis[neigh_r][neigh_c] = 1; // Mark as visited immediately
                    }
                }
            }
        }
        return dis;
    }
};
