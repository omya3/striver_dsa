class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices, int cap, int n)
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

        if (buy)
        {
            profit = max(-prices[ind] + find_max_profit(ind + 1, 0, prices, cap, n),
                         0 + find_max_profit(ind + 1, 1, prices, cap, n));
        }
        else
        {
            profit = max(prices[ind] + find_max_profit(ind + 1, 1, prices, cap - 1, n),
                         find_max_profit(ind + 1, 0, prices, cap, n));
        }
        return profit;
    }

public:
    int maxProfit(int k, vector<int> &prices)
    {
        return find_max_profit(0, 1, prices, k, prices.size());
    }
};