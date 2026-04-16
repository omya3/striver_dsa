#include <iostream>
using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        vector<int> prev(n, 0);
        if (obstacleGrid[0][0] == 1)
        {
            return 0;
        }
        for (int i = m - 1; i >= 0; i--)
        {
            vector<int> temp(n, 0);
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == (m - 1) && j == (n - 1) && obstacleGrid[i][j] != 1)
                    temp[j] = 1;
                else
                {
                    long down = 0;
                    long right = 0;
                    if (i + 1 < m && obstacleGrid[i + 1][j] != 1)
                        down = prev[j];
                    if (j + 1 < n && obstacleGrid[i][j + 1] != 1)
                        right = temp[j + 1];
                    temp[j] = down + right;
                }
            }
            prev = temp;
        }
        return prev[0];
    }
};
