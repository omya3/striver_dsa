#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int m = s.length();
        int n = t.length();
        if (m < n)
            return "";

        // Frequency tracker for characters in t
        vector<int> hash(128, 0);
        for (char c : t)
        {
            hash[c]++;
        }

        int l = 0, r = 0;
        int min_len = INT_MAX;
        int start_idx = -1;
        int cnt = 0; // Number of characters from t currently matched

        while (r < m)
        {
            // If we find a character that is still actively needed by t
            if (hash[s[r]] > 0)
            {
                cnt++;
            }
            // Decrement its availability (can go negative if we have extra duplicates)
            hash[s[r]]--;

            // When a valid window containing all characters of t is formed
            while (cnt == n)
            {
                // Track the smallest window size
                if (r - l + 1 < min_len)
                {
                    min_len = r - l + 1;
                    start_idx = l;
                }

                // Try to shrink from the left
                hash[s[l]]++;
                // If it becomes positive, an essential character left our window
                if (hash[s[l]] > 0)
                {
                    cnt--;
                }
                l++;
            }
            r++;
        }

        return start_idx == -1 ? "" : s.substr(start_idx, min_len);
    }
};
