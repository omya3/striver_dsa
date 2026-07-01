#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int longestKSubstr(string &s, int k)
    {
        // Initialize maxlen to -1 to handle the case where no valid substring exists
        int maxlen = -1;
        int l = 0, r = 0;
        int n = s.size();
        unordered_map<char, int> mpp;

        while (r < n)
        {
            // Add current character to map
            mpp[s[r]]++;

            // If unique characters exceed k, shift left pointer once (non-shrinking window)
            if (mpp.size() > k)
            {
                mpp[s[l]]--;
                if (mpp[s[l]] == 0)
                {
                    mpp.erase(s[l]);
                }
                l = l + 1;
            }

            // Track the length only when we have EXACTLY k distinct characters
            if (mpp.size() == k)
            {
                maxlen = max(maxlen, r - l + 1);
            }

            r++;
        }

        return maxlen;
    }
};
