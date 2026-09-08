#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int traverse(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
    {
        int m = grid.size();
        int n = grid[0].size();

        // 1. Corrected boundary check: must use 'n' (columns) and strict inequalities
        if (j1 < 0 || j2 < 0 || j1 >= n || j2 >= n)
        {
            return -1e8;
        }

        // Base case: Last row reached
        if (i == m - 1)
        {
            if (j1 == j2)
                return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        // Memoization check
        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];

        // 2. Compute current cell value once before entering direction loops
        int val = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];

        int maxi = -1e8;
        // Explore all 9 transition combinations for both robots
        for (int dir1 = -1; dir1 <= 1; dir1++)
        {
            for (int dir2 = -1; dir2 <= 1; dir2++)
            {
                int next_cherries = traverse(i + 1, j1 + dir1, j2 + dir2, grid, dp);
                maxi = max(maxi, val + next_cherries);
            }
        }

        return dp[i][j1][j2] = maxi;
    }

public:
    int cherryPickup(vector<vector<int>> &grid)
    {
        int m = grid.size();    // Rows
        int n = grid[0].size(); // Columns

        // dp table dimensions: [rows][columns][columns]
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
        return traverse(0, 0, n - 1, grid, dp);
    }
};