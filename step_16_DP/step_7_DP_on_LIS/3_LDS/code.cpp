#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> getLargestDivisibleSubset(std::vector<int> &arr)
    {
        int n = arr.size();
        if (n == 0)
            return {};

        // Sort the array first to naturally handle divisibility order
        std::sort(arr.begin(), arr.end());

        std::vector<int> dp(n, 1);
        std::vector<int> hash(n);
        int maxi = 1;
        int lastIndex = 0;

        for (int i = 0; i < n; i++)
        {
            hash[i] = i; // Initialize parent pointer to itself
            for (int prev = 0; prev < i; prev++)
            {
                // Ensure no division by zero and check divisibility
                if (arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i])
                {
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev; // Track the backtracking path
                }
            }
            if (dp[i] > maxi)
            {
                maxi = dp[i];
                lastIndex = i;
            }
        }

        // Reconstruct the subsequence
        std::vector<int> temp;
        while (hash[lastIndex] != lastIndex)
        {
            temp.push_back(arr[lastIndex]);
            lastIndex = hash[lastIndex];
        }
        temp.push_back(arr[lastIndex]); // Don't forget the last element

        std::reverse(temp.begin(), temp.end());
        return temp;
    }
};
