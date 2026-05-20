class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices,, int fee, int n)
    {
        if (ind == n)
        {
            return 0;
        }

        int profit = 0;

        if (buy)
        {
            profit = max(-prices[ind] + find_max_profit(ind + 1, 0, prices, fee, n),
                         0 + find_max_profit(ind + 1, 1, prices, fee, n));
        }
        else
        {
            profit = max(prices[ind] -fee + find_max_profit(ind + 1, 1, prices, fee, n),
                         find_max_profit(ind + 1, 0, prices, fee, n));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices, , int fee)
    {
        return find_max_profit(0, 1, prices, fee, prices.size());
    }
};