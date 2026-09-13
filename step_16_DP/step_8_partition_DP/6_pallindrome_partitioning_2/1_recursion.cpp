class Solution
{
private:
    int partition(int ind, string &s, vector<int> &dp, vector<vector<bool>> &isPal)
    {
        int n = s.size();
        if (ind == n)
            return 0;

        if (dp[ind] != -1)
            return dp[ind];

        int min_count = INT_MAX;

        for (int i = ind; i < n; i++)
        {
            // Using the precomputed O(1) palindrome check
            if (isPal[ind][i])
            {
                int count = 1 + partition(i + 1, s, dp, isPal);
                min_count = min(count, min_count);
            }
        }
        return dp[ind] = min_count;
    }

public:
    int minCut(string s)
    {
        int n = s.size();
        if (n <= 1)
            return 0;

        // 1. Precompute all palindrome substrings in O(N^2) total time
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++)
        {
            for (int start = 0; start <= n - len; start++)
            {
                int end = start + len - 1;
                if (s[start] == s[end])
                {
                    if (len <= 2 || isPal[start + 1][end - 1])
                    {
                        isPal[start][end] = true;
                    }
                }
            }
        }

        // 2. Run the DP partitioning
        vector<int> dp(n, -1); // Fixed missing semicolon here
        return partition(0, s, dp, isPal) - 1;
    }
};
