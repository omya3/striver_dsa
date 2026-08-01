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

// one more below solution

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        int left = 0;
        int n = s.size();

        map<char, int> charMap;
        int curr_len = 0;
        int max_len = 0; // fixed: was INT_MIN, now handles empty string correctly

        for (int right = 0; right < n; right++)
        {

            charMap[s[right]] += 1;

            curr_len = right - left + 1;
            if (curr_len != (int)charMap.size())
            {
                if (charMap[s[left]] == 1)
                {
                    charMap[s[left]] -= 1;
                    charMap.erase(s[left]);
                    left++;
                    curr_len = right - left + 1;
                }
                else
                {
                    charMap[s[left]] -= 1;
                    left++;
                    curr_len = right - left + 1;
                }
            }

            if (curr_len == (int)charMap.size())
            {
                max_len = max(max_len, curr_len);
            }
        }

        return max_len;
    }
};