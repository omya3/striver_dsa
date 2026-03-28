class Solution
{
    int find_macx_sum_adj(vector<int> &nums, vector<int> &dp, int n)
    {
        if (n == 0)
            return nums[0];

        if (n < 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int pick = nums[n] + find_macx_sum_adj(nums, dp, n - 2);
        int not_pick = 0 + find_macx_sum_adj(nums, dp, n - 1);

        return dp[n] = max(pick, not_pick);
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return find_macx_sum_adj(nums, dp, n-1);
    }
};