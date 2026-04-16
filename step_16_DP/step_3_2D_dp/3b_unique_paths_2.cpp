#include <iostream>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {   
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<long>> dp(m, vector<long>(n, -1));

        if(obstacleGrid[0][0]==1){
            return 0;
        }

        for (int i = m-1; i >= 0; i--)
        {
            for (int j = n-1; j >= 0; j--)
            {
                if (i == (m-1) && j == (n-1) && obstacleGrid[i][j]!=1)
                    dp[i][j] = 1;
                else
                {
                    long down = 0;
                    long right = 0;
                    if (i+1 <m && obstacleGrid[i+1][j]!=1)
                        down = dp[i + 1][j];
                    if (j+1 <n && obstacleGrid[i][j+1]!=1)
                        right = dp[i][j + 1];
                    dp[i][j] = down + right;
                }
            }
        }
        return dp[0][0];
    }
};
