#include <iostream>
using namespace std;

int find_total_paths(int i, int j, int m, int n, vector<vector<int>> &dp, vector<vector<int>> &mat)
{
    if (i <= m && j <= n && mat[i][j] == 1)
        return 0;

    if (i == m && j == n)
        return 1;

    if (i > m || j > n)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int down = find_total_paths(i + 1, j, m, n, dp, mat);

    int right = find_total_paths(i, j + 1, m, n, dp, mat);

    return dp[i][j] = (down + right);
}

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find_total_paths(0, 0, m - 1, n - 1, dp, obstacleGrid);
    }
};
