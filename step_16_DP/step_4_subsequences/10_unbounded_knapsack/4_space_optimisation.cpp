class Solution
{

private:
    int find_profit(int ind, vector<int> &val, vector<int> &wt, int capacity, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (capacity / wt[0]) * val[0];
        }

        if (dp[ind][capacity] != -1)
        {
            return dp[ind][capacity];
        }
        int not_take = find_profit(ind - 1, val, wt, capacity, dp);
        int take = 0;
        if (wt[ind] <= capacity)
        {
            take = val[ind] + find_profit(ind, val, wt, capacity - wt[ind], dp);
        }
        return dp[ind][capacity] = max(not_take, take);
    }

public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = val.size();
        vector<unsigned long long> prev(capacity + 1, 0);

        for (int target = 0; target <= capacity; target++)
        {

            prev[target] = (target / wt[0]) * val[0];
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<unsigned long long> curr(capacity + 1, 0);
            for (int target = 0; target <= capacity; target++)
            {
                unsigned long long not_take = prev[target];
                unsigned long long take = 0;
                if (wt[ind] <= target)
                {
                    take = val[ind] + curr[target - wt[ind]];
                }
                curr[target] = max(take, not_take);
            }
            prev = curr;
        }

        return prev[capacity];
    }
};