#include <vector>
#include <set>
#include <utility>

using namespace std;

class Solution
{
private:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<int>> &visited,
             vector<pair<int, int>> &vec, int base_r, int base_c)
    {

        // Record the coordinate structure relative to the starting point of the island
        vec.push_back({i - base_r, j - base_c});

        visited[i][j] = 1;

        // Correctly paired directional arrays for 4-directional moves (Up, Right, Down, Left)
        int delta_row[] = {-1, 0, 1, 0};
        int delta_col[] = {0, 1, 0, -1};

        int n = grid.size();
        int m = grid[0].size();

        // Process the 4 neighbors linearly
        for (int k = 0; k < 4; k++)
        {
            int n_row = i + delta_row[k];
            int n_col = j + delta_col[k];

            // Ensure neighbors are inside valid index boundaries
            if (n_row >= 0 && n_row < n && n_col >= 0 && n_col < m)
            {
                // FIXED: Check for character 'L' instead of '1'
                if (visited[n_row][n_col] != 1 && grid[n_row][n_col] == 'L')
                {
                    dfs(n_row, n_col, grid, visited, vec, base_r, base_c);
                }
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        if (n == 0)
            return 0;
        int m = grid[0].size();

        // Properly initialize the tracking matrix as a 2D layout
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Set naturally filters out duplicate vector shape configurations
        set<vector<pair<int, int>>> st;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // FIXED: Check for character 'L' instead of '1'
                if (visited[i][j] != 1 && grid[i][j] == 'L')
                {
                    vector<pair<int, int>> vec;
                    dfs(i, j, grid, visited, vec, i, j);
                    st.insert(vec);
                }
            }
        }

        // Return the total count of distinct island shapes
        return st.size();
    }
};
