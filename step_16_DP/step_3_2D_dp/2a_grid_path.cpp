#include <iostream>
using namespace std;

int find_total_paths(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;

    if (i < 0 || j < 0)
        return 0;

    if (dp[i][j] != -1)
        return dp[i][j];

    int up = find_total_paths(i - 1, j, dp);

    int left = find_total_paths(i, j - 1, dp);

    return dp[i][j] = (up + left);
}

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return find_total_paths(m - 1, n - 1, dp);
    }
};


