#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        // Frequency array for uppercase English letters
        vector<int> hash(26, 0);

        int n = s.size();
        int l = 0, r = 0;
        int maxf = 0;   // Stores the maximum frequency of any single character in the current window
        int maxlen = 0; // Stores the length of the longest valid substring

        while (r < n)
        {
            // Include the current character in the window frequency map
            hash[s[r] - 'A']++;

            // Update the maximum frequency found so far in any window
            maxf = max(maxf, hash[s[r] - 'A']);

            // If the number of characters to replace exceeds k, shift the left pointer by 1
            if ((r - l + 1) - maxf > k)
            {
                hash[s[l] - 'A']--;
                l = l + 1;
            }

            // If the window is valid, track the maximum length
            if ((r - l + 1) - maxf <= k)
            {
                maxlen = max(maxlen, r - l + 1);
            }

            // Move the right pointer forward
            r++;
        }

        return maxlen;
    }
};
