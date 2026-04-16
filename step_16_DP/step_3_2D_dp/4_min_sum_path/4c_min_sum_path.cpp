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

        vector<int> prev(n, INT_MAX);
        for (int i = m - 1; i >= 0; i--)
        {   
            vector<int> temp(n, INT_MAX);
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == (m - 1) && j == (n - 1))
                    temp[j] = grid[i][j];
                else
                {
                    long down = INT_MAX;
                    long right = INT_MAX;
                    if (i + 1 < m)
                        down = grid[i][j] + prev[j];
                    if (j + 1 < n)
                        right = grid[i][j] + temp[j + 1];
                    temp[j] = min(down, right);
                }
            }
            prev=temp;
        }
        return prev[0];
    }
};
