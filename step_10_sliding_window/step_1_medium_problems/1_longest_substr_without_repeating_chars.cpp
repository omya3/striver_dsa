#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        // Initialize an array of size 256 with -1 to store the last seen index of characters
        vector<int> mpp(256, -1);

        int n = s.length();
        int l = 0, r = 0;
        int maxLen = 0;

        while (r < n)
        {
            // If the character has been seen before and is inside our current window
            if (mpp[s[r]] != -1)
            {
                l = max(mpp[s[r]] + 1, l);
            }

            // Calculate length of the current valid window and update maxLen
            maxLen = max(maxLen, r - l + 1);

            // Store/update the index of the current character
            mpp[s[r]] = r;

            // Move the right pointer forward
            r++;
        }

        return maxLen;
    }
};
