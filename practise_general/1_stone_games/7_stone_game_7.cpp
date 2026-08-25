#include <vector>
#include <numeric>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    int recursion(int left, int right, int current_sum, const vector<int> &stones, vector<vector<int>> &dp)
    {
        // Base case: Only one stone left, no points can be scored
        if (left >= right)
            return 0;

        // Return cached result
        if (dp[left][right] != -1)
            return dp[left][right];

        // Option 1: Remove the rightmost stone
        int take_right = (current_sum - stones[right]) - recursion(left, right - 1, current_sum - stones[right], stones, dp);

        // Option 2: Remove the leftmost stone
        int take_left = (current_sum - stones[left]) - recursion(left + 1, right, current_sum - stones[left], stones, dp);

        // Store and return the maximum difference the current player can achieve
        return dp[left][right] = max(take_right, take_left);
    }

public:
    int stoneGameVII(vector<int> &stones)
    {
        int n = stones.size();

        // Initialize DP table with -1
        vector<vector<int>> dp(n, vector<int>(n, -1));

        // Calculate the total sum of all stones initially
        int total_sum = accumulate(stones.begin(), stones.end(), 0);

        return recursion(0, n - 1, total_sum, stones, dp);
    }
};
