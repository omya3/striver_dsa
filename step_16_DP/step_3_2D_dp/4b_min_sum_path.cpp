#include <iostream>
using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, -1));

        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == (m - 1) && j == (n - 1))
                    dp[i][j] = grid[i][j];
                else
                {
                    long down = INT_MAX;
                    long right = INT_MAX;
                    if (i + 1 < m)
                        down = grid[i][j] + dp[i + 1][j];
                    if (j + 1 < n)
                        right = grid[i][j] + dp[i][j + 1];
                    dp[i][j] = min(down, right);
                }
            }
        }
        return dp[0][0];
    }
};
