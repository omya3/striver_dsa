class Solution
{

private:
    int get_lis(int curr_ind, int prev_ind, int n, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (curr_ind == n)
        {
            return 0;
        }

        if (dp[curr_ind][prev_ind + 1] != -1)
            return dp[curr_ind][prev_ind + 1];

        int len = 0 + get_lis(curr_ind + 1, prev_ind, n, arr, dp);

        if (prev_ind == -1 || arr[curr_ind] > arr[prev_ind])
        {
            len = max(len, 1 + get_lis(curr_ind + 1, curr_ind, n, arr, dp));
        }
        return dp[curr_ind][prev_ind + 1] = len;
    }

public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr_ind = n - 1; curr_ind >= 0; curr_ind--)
        {
            for (int prev_ind = curr_ind - 1; prev_ind >= -1; prev_ind--)
            {

                int len = 0 + dp[curr_ind + 1][prev_ind + 1];

                if (prev_ind == -1 || nums[curr_ind] > nums[prev_ind])
                {
                    len = max(len, 1 + dp[curr_ind + 1][curr_ind+1]);
                }
                dp[curr_ind][prev_ind + 1] = len;
            }
        }
        return dp[0][-1 + 1];
    }
};
