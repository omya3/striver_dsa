class Solution
{

private:
    long find_num_combs(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return (amount % coins[ind] == 0);
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];
        long not_take = find_num_combs(ind - 1, amount, coins, dp);
        long take = 0;
        if (coins[ind] <= amount)
        {
            take = find_num_combs(ind, amount - coins[ind], coins, dp);
        }
        return dp[ind][amount] = take + not_take;
    }

public:
    int change(int amount, vector<int> &coins)
    {
        int n = coins.size();
        vector<unsigned long long> prev(amount + 1, 0);

        for (int target = 0; target <= amount; target++)
        {

            prev[target] = ((target % coins[0]) == 0);
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<unsigned long long> curr(amount + 1, 0);
            for (int target = 0; target <= amount; target++)
            {
                unsigned long long not_take = prev[target];
                unsigned long long take = 0;
                if (coins[ind] <= target)
                {
                    take = curr[target - coins[ind]];
                }
                curr[target] = take + not_take;
            }
            prev = curr;
        }

        return prev[amount];
    }
};