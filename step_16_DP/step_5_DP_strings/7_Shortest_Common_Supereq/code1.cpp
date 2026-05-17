#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // Fixed return type from int to string
    string shortestCommonSupersequence(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();

        // Create DP table initialized to 0
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

        // Fill the DP table for LCS length
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++)
            {
                if (s1[i - 1] == s2[j - 1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        string ans = "";
        int i = l1, j = l2;

        // Backtrack to build the supersequence from the end
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans += s1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                ans += s1[i - 1];
                i--;
            }
            else
            {
                ans += s2[j - 1];
                j--;
            }
        }

        // Add remaining characters of s1
        while (i > 0)
        {
            ans += s1[i - 1];
            i--;
        }

        // Add remaining characters of s2
        while (j > 0)
        {
            ans += s2[j - 1];
            j--;
        }

        // Reverse the string since it was built backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};
