class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        // 'after' stores the results of the next day (ind + 1)
        vector<vector<long>> after(2, vector<long>(3, 0));

        // FIX 1: Run backward from n - 1 down to 0
        for (int ind = n - 1; ind >= 0; ind--)
        {
            // 'curr' stores the results of the current day (ind)
            vector<vector<long>> curr(2, vector<long>(3, 0));

            for (int buy = 0; buy < 2; buy++)
            {
                // FIX 2: Start from cap = 1 to prevent cap - 1 from going below 0
                for (int cap = 1; cap < 3; cap++)
                {
                    long profit = 0;

                    if (buy)
                    {
                        // Cleaned up the hardcoded indexes to use state logic
                        profit = max(-prices[ind] + after[0][cap],
                                     0 + after[1][cap]);
                    }
                    else
                    {
                        profit = max(prices[ind] + after[1][cap - 1],
                                     after[0][cap]);
                    }
                    curr[buy][cap] = profit;
                }
            }
            // FIX 3: Shift current day's calculated data into 'after' for the next day's evaluation
            after = curr;
        }
        return after[1][2];
    }
};
