#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int longestBitonicSequence(int n, vector<int> &arr)
    {
        if (n == 0)
            return 0;

        // dp1[i] stores the length of LIS ending at index i
        vector<int> dp1(n, 1);
        for (int i = 0; i < n; i++)
        {
            for (int prev = 0; prev < i; prev++)
            {
                if (arr[prev] < arr[i] && 1 + dp1[prev] > dp1[i])
                {
                    dp1[i] = 1 + dp1[prev];
                }
            }
        }

        // dp2[i] stores the length of LDS starting at index i
        vector<int> dp2(n, 1);
        for (int i = n - 1; i >= 0; i--)
        { // Fixed loop condition
            for (int ahead = n - 1; ahead > i; ahead--)
            {
                if (arr[ahead] < arr[i] && 1 + dp2[ahead] > dp2[i])
                { // Fixed operator
                    dp2[i] = 1 + dp2[ahead];
                }
            }
        }

        // Find the maximum bitonic sequence length
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            // A valid bitonic sequence requires both an increasing and decreasing part
            // depending on specific platform rules (e.g., GeeksforGeeks vs LeetCode)
            maxi = max(maxi, dp1[i] + dp2[i] - 1); // Fixed formula
        }

        return maxi;
    }
};
