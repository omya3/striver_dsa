#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // 1. Changed return type from int to string
    string shortestCommonSupersequence(string &s1, string &s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();

        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));

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

        // 2. Pre-allocate the exact size of the Shortest Common Supersequence
        int len_lcs = l1 + l2 - dp[l1][l2];
        string ans(len_lcs, '$'); // Faster way to initialize a string of size len_lcs

        int index = len_lcs - 1;
        int i = l1;
        int j = l2;

        // 3. Fixed backtracking paths
        while (i > 0 && j > 0)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                ans[index] = s1[i - 1];
                index--;
                i--;
                j--;
            }
            // Crucial Fix: Changed > to >= to correctly handle tie-breakers in the grid
            else if (dp[i - 1][j] >= dp[i][j - 1])
            {
                ans[index] = s1[i - 1];
                index--;
                i--;
            }
            else
            {
                ans[index] = s2[j - 1];
                index--;
                j--;
            }
        }

        // 4. Clean up any remaining characters
        while (i > 0)
        {
            ans[index] = s1[i - 1];
            index--;
            i--;
        }
        while (j > 0)
        {
            ans[index] = s2[j - 1];
            index--;
            j--;
        }

        return ans;
    }
};
