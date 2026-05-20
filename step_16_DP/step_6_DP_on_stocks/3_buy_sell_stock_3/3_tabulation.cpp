class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        // FIX 1: Change size to n + 1 so index 'n' is valid and safe to access
        vector<vector<vector<long>>> dp(n + 1,
                                        vector<vector<long>>(2,
                                                             vector<long>(3, 0)));

        for (int ind = 0; ind < n; ind++)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }

        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 0; cap < 3; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                // FIX 2: Start from cap = 1 to prevent cap - 1 from becoming -1
                for (int cap = 1; cap < 3; cap++)
                {
                    long profit = 0; // Changed to long to match DP vector type

                    if (buy)
                    {
                        profit = max(-prices[ind] + dp[ind + 1][0][cap],
                                     0 + dp[ind + 1][1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1],
                                     dp[ind + 1][0][cap]);
                    }
                    dp[ind][buy][cap] = profit;
                }
            }
        }
        return dp[0][1][2];
    }
};
