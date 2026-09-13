#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{

private:
    int burster(int i, int j, vector<int> &nums, vector<vector<int>> &dp)
    {
        if (i > j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxi = INT_MIN;
        // Fix 3: Changed 'ind < j' to 'ind <= j' to include the boundary
        for (int ind = i; ind <= j; ind++)
        {

            // Fix 2: Changed 'arr' to 'nums'
            int sum = nums[i - 1] * nums[ind] * nums[j + 1] +
                      burster(i, ind - 1, nums, dp) +
                      burster(ind + 1, j, nums, dp);
            maxi = max(maxi, sum);
        }
        return dp[i][j] = maxi;
    }

public:
    int maxCoins(vector<int> &nums)
    {

        // Fix 1: Changed 'numbers' to 'nums'
        nums.insert(nums.begin(), 1);
        nums.push_back(1); // Cleaner approach than nums.insert(nums.end(), 1)

        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return burster(1, nums.size() - 2, nums, dp);
    }
};