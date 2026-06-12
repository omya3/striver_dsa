#include <vector>
#include <queue>
#include <utility>

using namespace std;

class Solution
{
public:
    // Fixed: Function name kept as 'bfs' to match your declaration
    void bfs(int s_r, int s_c, vector<vector<int>> &grid, vector<vector<int>> &vis)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> del_row = {-1, 0, 1, 0};
        vector<int> del_col = {0, 1, 0, -1};

        queue<pair<int, int>> q;

        vis[s_r][s_c] = 1;
        q.push({s_r, s_c});

        while (!q.empty())
        {
            int node_r = q.front().first;
            int node_c = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++)
            {
                int neigh_r = node_r + del_row[k];
                int neigh_c = node_c + del_col[k];

                if (neigh_r >= 0 && neigh_r < n && neigh_c >= 0 && neigh_c < m)
                {
                    // Fixed: Changed character '1' to integer 1
                    if (!vis[neigh_r][neigh_c] && grid[neigh_r][neigh_c] == 1)
                    {
                        q.push({neigh_r, neigh_c});
                        vis[neigh_r][neigh_c] = 1;
                    }
                }
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));

        // 1. Traverse first and last rows
        for (int j = 0; j < m; j++)
        {
            // Fixed: Call 'bfs' directly and changed '1' to 1
            if (!vis[0][j] && grid[0][j] == 1)
            {
                bfs(0, j, grid, vis);
            }
            if (!vis[n - 1][j] && grid[n - 1][j] == 1)
            {
                bfs(n - 1, j, grid, vis);
            }
        }

        // 2. Traverse first and last columns
        for (int i = 0; i < n; i++)
        {
            // Fixed: Call 'bfs' directly and changed '1' to 1
            if (!vis[i][0] && grid[i][0] == 1)
            {
                bfs(i, 0, grid, vis);
            }
            if (!vis[i][m - 1] && grid[i][m - 1] == 1)
            {
                bfs(i, m - 1, grid, vis);
            }
        }

        // 3. Count unvisited land cells (enclaves)
        int enclave_count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // Fixed: Check for unvisited land and increment a count variable
                if (!vis[i][j] && grid[i][j] == 1)
                {
                    enclave_count++;
                }
            }
        }

        return enclave_count; // Fixed: Added missing return statement
    }
};
