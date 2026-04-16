#include <iostream>
using namespace std;

long find_min_path(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &mat)
{
    if (i == m && j == n)
        return mat[i][j];

    if (i > m || j > n)
        return INT_MAX;

    if (dp[i][j] != -1)
        return dp[i][j];

    long down = mat[i][j] + find_min_path(i + 1, j, m, n, dp, mat);

    long right = mat[i][j] + find_min_path(i, j + 1, m, n, dp, mat);

    return dp[i][j] = min(down, right);
}

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find_min_path(0, 0, m - 1, n - 1, dp, grid);
    }
};
