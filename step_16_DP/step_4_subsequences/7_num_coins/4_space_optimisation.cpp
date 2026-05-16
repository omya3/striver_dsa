

class Solution
{

private:
    int find_min_coins(int ind, vector<int> &coins, int amount, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            if ((amount % coins[0]) == 0)
            {
                return (amount / coins[0]);
            }
            return 1e9;
        }

        if (dp[ind][amount] != -1)
            return dp[ind][amount];

        int not_take = 0 + find_min_coins(ind - 1, coins, amount, dp);
        int take = INT_MAX;
        if (coins[ind] <= amount)
        {
            take = 1 + find_min_coins(ind, coins, amount - coins[ind], dp);
        }

        return dp[ind][amount] = min(take, not_take);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);

        for (int target = 0; target <= amount; target++)
        {
            if ((target % coins[0]) == 0)
            {
                prev[target] = (target / coins[0]);
            }
            else
            {
                prev[target] = 1e9;
            }
        }

        for (int ind = 1; ind < n; ind++)
        {
            vector<int> curr(amount + 1, 0);
            for (int target = 0; target <= amount; target++)
            {

                int not_take = 0 + prev[target];
                int take = INT_MAX;
                if (coins[ind] <= target)
                {
                    take = 1 + curr[target - coins[ind]];
                }

                curr[target] = min(take, not_take);
            }
            prev = curr;
        }

        int min_coins = prev[amount];
        if (min_coins >= 1e9)
        {
            return -1;
        }
        return min_coins;
    }
};