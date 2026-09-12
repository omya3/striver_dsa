#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();

        // 1. Properly initialize the (m + 1) x (n + 1) table for 1-based indexing lengths.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        // 2. Base Cases: If word2 is empty, it requires 'i' deletions from word1 to match.
        for (int i = 1; i <= m; i++)
        {
            dp[i][0] = i;
        }

        // 3. Base Cases: If word1 is empty, it requires 'j' insertions to construct word2.
        for (int j = 1; j <= n; j++)
        {
            dp[0][j] = j;
        }

        // 4. MAIN TRANSITION LOOPS:
        // FIXED: Loops must start at 1 to fully evaluate all characters.
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                // FIXED: Offset loop lengths by -1 to check the correct 0-indexed string positions.
                if (word1[i - 1] == word2[j - 1])
                {
                    dp[i][j] = 0 + dp[i - 1][j - 1]; // Characters match; no operation needed.
                }
                else
                {
                    dp[i][j] = min({
                        1 + dp[i][j - 1],   // 1. INSERTION OPERATION
                        1 + dp[i - 1][j],   // 2. DELETION OPERATION
                        1 + dp[i - 1][j - 1] // 3. REPLACEMENT OPERATION
                    });
                }
            }
        }
        
        // Return the final cell tracking full lengths
        return dp[m][n];
    }
};
