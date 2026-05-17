class Solution
{

private:
    int find_lcs_length(int l1, int l2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        if (l1 < 0 || l2 < 0)
            return 0;

        if (dp[l1][l2] != -1)
            return dp[l1][l2];
            
        if (s1[l1] == s2[l2])
        {
            return dp[l1][l2] = (1 + find_lcs_length(l1 - 1, l2 - 1, s1, s2, dp));
        }

        return dp[l1][l2] = (0 + max(find_lcs_length(l1 - 1, l2, s1, s2, dp), find_lcs_length(l1, l2 - 1, s1, s2, dp)));
    }

public:
    int lcs(string &s1, string &s2)
    {
        // code here
        int l1 = s1.length();
        int l2 = s2.length();

        vector<vector<int>> dp(l1, vector<int>(l2, -1));

        return find_lcs_length(l1 - 1, l2 - 1, s1, s2, dp);
    }
};
