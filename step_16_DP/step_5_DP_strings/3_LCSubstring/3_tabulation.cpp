class Solution {
  public:
    int longCommSubstr(string& s1, string& s2) {
        // code here
        int l1 = s1.length();
        int l2 = s2.length();

        // Create DP table initialized to 0
        // Size is (l1 + 1) x (l2 + 1) to handle the base case of empty strings
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        int ans = 0;
        // Fill the DP table
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                // If characters match, add 1 to the previous diagonal state
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans, dp[i][j]);
                }
                // If they don't match, take the maximum of skipping a character from s1 or s2
                else
                {
                    dp[i][j] = 0;
                }
            }
        }

        // The bottom-right cell contains the length of the LCS
        return ans;
    }
};