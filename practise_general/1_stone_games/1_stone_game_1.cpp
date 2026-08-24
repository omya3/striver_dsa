class Solution
{
public:
    bool stoneGame(vector<int> &piles)
    {
        return true;
    }
};

// below os solution 2
class Solution
{

public:
    int recursion(int left, int right, vector<int> &piles, vector<vector<int>> &dp)
    {
        if (left > right)
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        bool even = (((right - left + 1) % 2) == 0) ? true : false;

        int left_val = 0;
        int right_val = 0;

        if (even)
        {
            left_val = piles[left];
            right_val = piles[right];
        }

        return dp[left][right] = max(left_val + recursion(left + 1, right, piles, dp),
                                     right_val + recursion(left, right - 1, piles, dp));
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        int total_sum = 0;

        for (int i = 0; i < n; i++)
        {
            total_sum += piles[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, -1));

        int achievable_sum = recursion(0, n - 1, piles, dp);

        return (achievable_sum > (total_sum / 2));
    }
};