class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices, int n, vector<vector<long>> &dp)
    {
        if (ind == n)
        {
            return 0;
        }

        int profit = 0;

        if (dp[ind][buy] != -1)
            return dp[ind][buy];

        if (buy)
        {
            profit = max(-prices[ind] + find_max_profit(ind + 1, 0, prices, n, dp),
                         0 + find_max_profit(ind + 1, 1, prices, n, dp));
        }
        else
        {
            profit = max(prices[ind] + find_max_profit(ind + 1, 1, prices, n, dp),
                         find_max_profit(ind + 1, 0, prices, n, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        vector<long> prev(2, 0);

        prev[0] = prev[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--)
        {
            vector<long> curr(2, 0);
            for (int buy = 0; buy <= 1; buy++)
            {

                int profit = 0;

                if (buy)
                {
                    profit = max(-prices[ind] + prev[0],
                                 0 + prev[1]);
                }
                else
                {
                    profit = max(prices[ind] + prev[1],
                                 prev[0]);
                }
                curr[buy] = profit;
            }
            prev = curr;
        }

        return prev[1];
    }
};