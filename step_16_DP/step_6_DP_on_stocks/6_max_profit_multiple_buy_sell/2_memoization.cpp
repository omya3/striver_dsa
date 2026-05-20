class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices, int fee, int n, vector<vector<long>> &dp)
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
            profit = max(-prices[ind] + find_max_profit(ind + 1, 0, prices, fee, n, dp),
                         0 + find_max_profit(ind + 1, 1, prices, fee, n, dp));
        }
        else
        {
            profit = max(prices[ind] - fee + find_max_profit(ind + 1, 1, prices, fee, n, dp),
                         find_max_profit(ind + 1, 0, prices, fee, n, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices, int fee)
    {
        vector<vector<long>> dp(prices.size(), vector<long>(2, -1));
        return find_max_profit(0, 1, prices, fee, prices.size(), dp);
    }
};