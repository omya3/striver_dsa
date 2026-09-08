#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int cutRod(vector<int> &price)
    {
        int p_size = price.size();
        // dp[ind][curr_size] stores max profit using rod pieces from index 0 up to 'ind' for a rod of length 'curr_size'
        vector<vector<int>> dp(p_size, vector<int>(p_size + 1, 0));

        // 1. Base Case Initialization: If we only use pieces of length 1 (ind = 0)
        for (int n = 0; n <= p_size; n++)
        {
            dp[0][n] = price[0] * n;
        }

        // 2. Iterate through all items (rod pieces) and target lengths
        for (int ind = 1; ind < p_size; ind++)
        {
            for (int n = 0; n <= p_size; n++)
            {

                // Option 1: Skip the current piece size
                int not_take = dp[ind - 1][n];

                // Option 2: Cut the current piece size (if it fits)
                int take = INT_MIN;
                int rod_length = ind + 1; // 0-based index maps to (ind + 1) length

                if (rod_length <= n)
                {
                    take = price[ind] + dp[ind][n - rod_length];
                }

                dp[ind][n] = max(take, not_take);
            }
        }

        // The ultimate solution lies at the last index with the maximum rod capacity
        return dp[p_size - 1][p_size];
    }
};
