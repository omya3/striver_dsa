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

        // 1. SPACE OPTIMIZATION:
        // Instead of an (m+1) x (n+1) matrix, we only need two rows of size (n+1).
        // 'prev' represents the calculations from row (i-1)
        // 'curr' represents the calculations for the current row (i)
        vector<unsigned long long> prev(n + 1, 0);
        vector<unsigned long long> curr(n + 1, 0);

        // 2. FIXED BASE CASE:
        // Setting target length 0 (j=0) to 1. An empty target can always be formed 1 way.
        // We initialize both rows so the base case survives the row-swapping steps.
        prev[0] = 1;
        curr[0] = 1;

        // 3. MAIN LOOPS:
        // Outer loop iterates through string 's' lengths, inner loop through target 't' lengths.
        for (int i = 1; i <= m; i++)
        {
            // BUG FIX: Ensure the base case 'j=0 is 1' carries forward into the current row
            curr[0] = 1;

            for (int j = 1; j <= n; j++)
            {
                // Offset by -1 because loop variables represent lengths, but string indexing is 0-based.
                if (s[i - 1] == t[j - 1])
                {
                    // If characters match, add options: use current character (prev[j-1])
                    // or skip current character (prev[j]).
                    curr[j] = prev[j - 1] + prev[j];
                }
                else
                {
                    // If characters mismatch, we can only skip the current character from 's'.
                    curr[j] = prev[j];
                }
            }
            // ROW SWAP: The current row calculations become the history ('prev') for the next character of 's'
            prev = curr;
        }

        // 4. FINAL EXTRACTION:
        // Returns the value at the end of our target array column row space.
        return curr[n];
    }
};
