class Solution
{

public:
    bool isSubsetSum(vector<int> &arr, int sum)
    {
        // code here
        vector<vector<bool>> dp(arr.size(), vector<bool>(sum + 1, 0));
        int n = arr.size();
        for (int i = 0; i < n; i++)
        {
            dp[i][0] = true;
        }

        dp[0][arr[0]] = true;

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 1; target <= sum; target++)
            {
                bool not_take = dp[ind - 1][target];
                bool take = false;
                if (target >= arr[ind])
                {
                    take = dp[ind - 1][target - arr[ind]];
                }
                dp[ind][target] = take | not_take;
            }
        }
        return dp[n-1][sum];
    }
};