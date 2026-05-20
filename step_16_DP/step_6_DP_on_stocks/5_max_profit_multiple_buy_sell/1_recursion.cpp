class Solution
{

private:
    int find_max_profit(int ind, int buy, vector<int> &prices, int n)
    {
        if (ind >= n)
        {
            return 0;
        }

        int profit = 0;

        if (buy)
        {
            profit = max(-prices[ind] + find_max_profit(ind + 1, 0, prices, n),
                         0 + find_max_profit(ind + 1, 1, prices, n));
        }
        else
        {
            profit = max(prices[ind] + find_max_profit(ind + 2, 1, prices, n),
                         find_max_profit(ind + 1, 0, prices, n));
        }
        return profit;
    }

public:
    int maxProfit(vector<int> &prices)
    {
        return find_max_profit(0, 1, prices, prices.size());
    }
};