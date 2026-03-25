class Solution {
    int climbsteps(int n, vector<int> &dp) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        if (dp[n] != -1) return dp[n];

        return dp[n] = climbsteps(n - 1, dp) + climbsteps(n - 2, dp);
    }

public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        vector<int> dp(n + 1, -1);
        return climbsteps(n, dp);
    }
};