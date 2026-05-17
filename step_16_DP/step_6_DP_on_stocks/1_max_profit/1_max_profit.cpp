class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int mini = prices[0];
        int cost = INT_MIN;
        int profit = INT_MIN;
        int n = prices.size();
        for (int i = 0; i < n; i++)
        {
            cost = prices[i] - mini;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};