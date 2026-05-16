class Solution
{

private:
    long find_num_combs(int ind, int amount, vector<int> &coins)
    {
        if (ind == 0)
        {
            return (amount % coins[ind] == 0);
        }

        long not_take = find_num_combs(ind - 1, amount, coins);
        long take = 0;
        if (coins[ind] <= amount)
        {
            take = find_num_combs(ind, amount - coins[ind], coins);
        }
        return take + not_take;
    }

public:
    int change(int amount, vector<int> &coins)
    {

        int n = coins.size();
        return find_num_combs(n - 1, amount, coins);
    }
};