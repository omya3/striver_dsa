class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices, int n, vector<vector<long>> &dp)
    {
        if (ind >= n)
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
            profit = max(prices[ind] + find_max_profit(ind + 2, 1, prices, n, dp),
                         find_max_profit(ind + 1, 0, prices, n, dp));
        }
        return dp[ind][buy] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<long>> dp(prices.size(), vector<long>(2, -1));
        return find_max_profit(0, 1, prices, prices.size(), dp);
    }
};