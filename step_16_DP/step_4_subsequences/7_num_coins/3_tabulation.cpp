

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
        vector<vector<int>> dp(n, vector<int>(amount + 1, 0));

        for (int target = 0; target <= amount; target++)
        {
            if ((target % coins[0]) == 0)
            {
                dp[0][target] = (target / coins[0]);
            }
            else
            {
                dp[0][target] = 1e9;
            }
        }

        for (int ind = 1; ind < n; ind++)
        {
            for (int target = 0; target <= amount; target++)
            {

                int not_take = 0 + dp[ind - 1][target];
                int take = INT_MAX;
                if (coins[ind] <= target)
                {
                    take = 1 + dp[ind][target - coins[ind]];
                }

                dp[ind][target] = min(take, not_take);
            }
        }

        int min_coins = dp[n - 1][amount];
        if (min_coins >= 1e9)
        {
            return -1;
        }
        return min_coins;
    }
};