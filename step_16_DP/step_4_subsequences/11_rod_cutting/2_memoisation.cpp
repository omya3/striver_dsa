#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    int cutter(int ind, int n, vector<int> &price, vector<vector<int>> &dp)
    {
        if (ind == 0)
        {
            return price[0] * n;
        }

        if (dp[ind][n] != -1)
            return dp[ind][n];

        // FIXED: Passed 'dp' into the recursive call
        int not_take = cutter(ind - 1, n, price, dp);
        int take = INT_MIN;
        int rod_length = ind + 1;

        if (rod_length <= n)
        {
            // FIXED: Passed 'dp' into the recursive call
            take = price[ind] + cutter(ind, n - rod_length, price, dp);
        }

        return dp[ind][n] = max(take, not_take);
    }

public:
    int cutRod(vector<int> &price)
    {
        int p_size = price.size();
        // FIXED: Used 'p_size + 1' instead of undefined 'n + 1'
        vector<vector<int>> dp(p_size, vector<int>(p_size + 1, -1));
        return cutter(p_size - 1, p_size, price, dp);
    }
};
