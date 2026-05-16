

class Solution
{

private:
    int find_min_coins(int ind, vector<int> &coins, int amount)
    {
        if (ind == 0)
        {
            if ((amount % coins[0]) == 0)
            {
                return (amount / coins[0]);
            }
            return 1e9;
        }

        int not_take = 0 + find_min_coins(ind - 1, coins, amount);
        int take = INT_MAX;
        if (coins[ind] <= amount)
        {
            take = 1 + find_min_coins(ind, coins, amount - coins[ind]);
        }

        return min(take, not_take);
    }

public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int min_coins = find_min_coins(n - 1, coins, amount);
        if (min_coins >= 1e9)
        {
            return -1;
        }
        return min_coins;
    }
};