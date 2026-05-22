#include <vector>
#include <string>
#include <algorithm>

class Solution
{
private:
    // Checks if s2 can be formed by adding exactly one character to s1
    bool checkPossible(const std::string &s1, const std::string &s2)
    {
        if (s1.size() + 1 != s2.size())
        {
            return false;
        }

        int first = 0;  // pointer for s1
        int second = 0; // pointer for s2

        while (second < s2.size())
        {
            if (first < s1.size() && s1[first] == s2[second])
            {
                first++;
                second++;
            }
            else
            {
                second++; // Skip the extra character in s2
            }
        }
        return first == s1.size();
    }

    // Static comparator to sort strings by length
    static bool comp(const std::string &s1, const std::string &s2)
    {
        return s1.size() < s2.size();
    }

public:
    int longestStrChain(std::vector<std::string> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return 0;

        // Step 1: Sort by length ONLY
        std::sort(arr.begin(), arr.end(), comp);

        std::vector<int> dp(n, 1);
        int maxi = 1;

        // Step 2: Dynamic programming string chaining
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                // Pass shorter string (arr[prev]) first, longer string (arr[i]) second
                if (checkPossible(arr[prev], arr[i]) && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
            }
        }

        return maxi;
    }
};
