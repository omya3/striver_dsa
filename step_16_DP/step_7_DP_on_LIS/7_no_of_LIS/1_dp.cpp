class Solution
{
public:
    int findNumberOfLIS(vector<int> &s)
    {
        int n = s.size();

        vector<int> dp(n, 1);
        vector<int> count(n, 1);
        int maxi = INT_MIN;

        for (int curr = 0; curr < n; curr++)
        {
            for (int prev = 0; prev < curr; prev++)
            {
                if (s[curr] > s[prev] and dp[curr] < dp[prev] + 1)
                {
                    dp[curr] = dp[prev] + 1;
                    count[curr] = count[prev];
                }
                else if (s[curr] > s[prev] and dp[curr] == 1 + dp[prev])
                {
                    count[curr] += count[prev];
                }
            }
            maxi = max(maxi, dp[curr]);
        }

        int nos = 0;

        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            {
                nos += count[i];
            }
        }
        return nos;
    }
};