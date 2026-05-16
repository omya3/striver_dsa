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
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return find_num_combs(n - 1, amount, coins, dp);
    }
};