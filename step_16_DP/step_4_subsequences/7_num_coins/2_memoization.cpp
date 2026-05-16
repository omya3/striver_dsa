

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
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int min_coins = find_min_coins(n - 1, coins, amount, dp);
        if (min_coins >= 1e9)
        {
            return -1;
        }
        return min_coins;
    }
};