#include <iostream>
using namespace std;

class Solution
{
    int frogJump(int ind, vector<int> heights, vector<int> &dp)
    {
        if (ind == 0)
            return 1;

        if (dp[ind] != -1)
            return dp[ind];

        int left = frogJump(ind - 1, heights, dp) + abs(heights[ind] - heights[ind - 1]);
        int right = INT_MAX;

        if (ind > 1)
            right = frogJump(ind - 2, heights, dp) + abs(heights[ind] - heights[ind - 2]);

        return dp[ind] = min(left, right);
    }

public:
    int frogJump(int n)
    {
        if (n == 1)
            return 1;
        vector<int> dp(n + 1, -1);
        return frogJump(n, heights, dp);
    }
};