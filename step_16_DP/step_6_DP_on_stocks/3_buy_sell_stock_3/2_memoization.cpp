class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices, int cap, int n, vector<vector<vector<long>>> &dp)
    {
        if (cap == 0)
        {
            return 0;
        }

        if (ind == n)
        {
            return 0;
        }

        int profit = 0;

        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];

        if (buy)
        {
            profit = max(-prices[ind] + find_max_profit(ind + 1, 0, prices, cap, n, dp),
                         0 + find_max_profit(ind + 1, 1, prices, cap, n, dp));
        }
        else
        {
            profit = max(prices[ind] + find_max_profit(ind + 1, 1, prices, cap - 1, n, dp),
                         find_max_profit(ind + 1, 0, prices, cap, n, dp));
        }
        return dp[ind][buy][cap] = profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        vector<vector<long>> dp(prices.size(),
                                vector<vector<long>>(2,
                                                     vector<long>(3, -1)));

        return find_max_profit(0, 1, prices, 2, prices.size(), dp);
    }
};