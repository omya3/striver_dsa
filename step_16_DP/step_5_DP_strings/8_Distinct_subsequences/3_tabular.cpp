#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDistinct(string s, string t)
    {
        int m = s.size();
        int n = t.size();

        /*
         * WHY (m + 1) x (n + 1)?
         * dp[i][j] represents: "Subsequences of t's prefix of LENGTH j inside s's prefix of LENGTH i"
         * Lengths range from 0 (empty string "") to m or n. 
         * To fit length 'm' into a 0-indexed vector, the vector must be size 'm + 1'.
         */
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));

        /*
         * BASE CASE (i = 0 to m, j = 0):
         * dp[i][0] = 1 means: If target 't' is an empty string "", there is exactly 
         * 1 way to form it from any prefix of 's' (by deleting all characters of 's').
         * This handles the 'j = 0' column safely without running out of bounds.
         */
        for (int i = 0; i <= m; i++)
        {
            dp[i][0] = 1;
        }

        /*
         * MAIN LOOPS (Start at 1 instead of 0):
         * Since index 0 is reserved for empty strings, our loops process lengths 1 to m/n.
         */
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++) 
            {
                /*
                 * STRING INDEX OFFSET (i - 1 and j - 1):
                 * Loop variables 'i' and 'j' represent STRING LENGTHS.
                 * To check the actual current character in the 0-indexed strings 's' and 't',
                 * we must subtract 1. (e.g., Length 1 means character at index 0).
                 */
                if (s[i - 1] == t[j - 1])
                {
                    /*
                     * NO BOUNDARY CRASH:
                     * Because loops start at 1, the term 'dp[i - 1][j - 1]' will at minimum 
                     * evaluate to 'dp[0][0]', which is a perfectly valid cell in our table!
                     */
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        /*
         * FINAL ANSWER RETRIEVAL:
         * The total number of ways to form the full target string (length n) 
         * from the full source string (length m) sits at the very bottom-right corner: dp[m][n].
         */
        return dp[m][n];
    }
};
