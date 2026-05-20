class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        if (n == 0)
            return 0;

        // Represents the data for the 'next day' (ind + 1)
        vector<vector<long>> after(2, vector<long>(3, 0));

        for (int ind = n - 1; ind >= 0; ind--)
        {
            // Represents the data for the 'current day' (ind)
            vector<vector<long>> curr(2, vector<long>(3, 0));

            for (int buy = 0; buy < 2; buy++)
            {
                // FIX 1: Start cap from 1 to safely do cap - 1 without underflow
                for (int cap = 1; cap < 3; cap++)
                {
                    long profit = 0; // Match long data type

                    if (buy)
                    {
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
            // FIX 2: Essential update step to pass today's profits to the next day's evaluation
            after = curr;
        }
        return after[1][2];
    }
};
