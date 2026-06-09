class Solution
{

public:
    int maxProfit(int k, vector<int> &prices)
    {

        // DP Table Dimensions: [n + 1][2][k + 1]
        // Why prices.size() + 1? 
        // 1. Prevents "Out of Bounds" errors when day 'ind' looks ahead to day 'ind + 1'.
        // 2. Index 'n' represents a hypothetical day AFTER trading ends, serving as our base case (0 profit).
        vector<vector<vector<long>>> dp(prices.size()+1,
                                        vector<vector<long>>(2,
                                                             vector<long>(k+1, 0)));
    
        int n = prices.size();

        for (int ind = 0; ind < n; ind++)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                dp[ind][buy][0] = 0;
            }
        }

        for (int buy = 0; buy < 2; buy++)
        {
            for (int cap = 0; cap <= k; cap++)
            {
                dp[n][buy][cap] = 0;
            }
        }

        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy < 2; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    long profit = 0;

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
        return dp[0][1][k];
    }
};