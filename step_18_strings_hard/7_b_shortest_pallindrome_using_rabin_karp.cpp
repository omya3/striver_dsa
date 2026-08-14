#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string shortestPalindrome(string s)
    {

        int n = s.length();
        if (n <= 1)
            return s;

        long long forward_hash = 0;
        long long backward_hash = 0;
        long long power = 1;

        long long d = 29;
        long long q = 1e9 + 7;

        int longest_pal_len = 0;

        for (int i = 0; i < n; i++)
        {

            int char_val = s[i] - 'a' + 1;

            forward_hash = (forward_hash * d + char_val) % q;
            // FIX: Changed backward_has to backward_hash
            backward_hash = (backward_hash + char_val * power) % q;

            power = (power * d) % q;

            if (forward_hash == backward_hash)
            {
                longest_pal_len = i + 1;
            }
        }

        // Extract the remaining non-palindrome suffix
        string suffix_to_add = s.substr(longest_pal_len);

        // Reverse it and glue it to the front
        reverse(suffix_to_add.begin(), suffix_to_add.end());
        return suffix_to_add + s;
    }
};
