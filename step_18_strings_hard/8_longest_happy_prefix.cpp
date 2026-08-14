#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestPrefix(string s)
    {
        int n = s.size();
        if (n <= 1)
            return ""; // Edge case for single character strings

        vector<int> lps(n, 0);

        int prev_lps = 0;
        int i = 1; // Fix 3: Start checking from index 1 (lps[0] is always 0)

        while (i < n)
        {
            if (s[prev_lps] == s[i])
            { // Fix 1: Fixed the 'pre_lps' typo
                prev_lps += 1;
                lps[i] = prev_lps;
                i += 1;
            }
            else
            {
                if (prev_lps == 0)
                {
                    lps[i] = 0;
                    i += 1;
                }
                else
                {
                    // Fix 2: Update prev_lps to fall back, avoiding the infinite loop
                    prev_lps = lps[prev_lps - 1];
                }
            }
        }

        // Fix 4: The final index lps[n-1] automatically holds the longest happy prefix length
        int happy_pref_len = lps[n - 1];

        // Return the substring of that length from the beginning
        return s.substr(0, happy_pref_len);
    }
};
