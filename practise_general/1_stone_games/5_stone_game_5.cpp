#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    int recursion(int left, int right, vector<int> &stoneValue, vector<vector<int>> &dp)
    {
        // BASE CASE: Single row/stone left. Cannot be split, so score is 0.
        if (left >= right)
        {
            return 0;
        }

        // MEMOIZATION: Return cached result if already calculated
        if (dp[left][right] != -1)
            return dp[left][right];

        // 1. CRITICAL FIX: Calculate total sum of the CURRENT window [left, right]
        // Doing this inside the loop was rewriting it incorrectly.
        int total_sum = 0;
        for (int i = left; i <= right; i++)
        {
            total_sum += stoneValue[i];
        }

        int prefix_sum = 0;
        int res = INT_MIN;

        // 2. CRITICAL FIX: The split index 'i' must stop at 'right - 1'
        // to ensure we always create two valid, non-empty groups: [left, i] and [i + 1, right].
        for (int i = left; i < right; i++)
        {
            prefix_sum += stoneValue[i];
            int suffix_sum = total_sum - prefix_sum;

            if (prefix_sum < suffix_sum)
            {
                // Left row is strictly smaller: Bob throws away the right row.
                // Alice gets prefix_sum points and continues playing on the left row [left, i].
                res = max(res, prefix_sum + recursion(left, i, stoneValue, dp));
            }
            else if (prefix_sum > suffix_sum)
            {
                // Right row is strictly smaller: Bob throws away the left row.
                // Alice gets suffix_sum points and continues playing on the right row [i + 1, right].
                res = max(res, suffix_sum + recursion(i + 1, right, stoneValue, dp));
            }
            else
            {
                // Tie breaker: Bob lets Alice choose which row to keep.
                // Alice will greedily choose whichever side maximizes her ultimate score.
                int choose_left = prefix_sum + recursion(left, i, stoneValue, dp);
                int choose_right = suffix_sum + recursion(i + 1, right, stoneValue, dp);
                res = max({res, choose_left, choose_right});
            }
        }

        return dp[left][right] = res;
    }

public:
    int stoneGameV(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        // Match the constraints of the problem (N <= 500)
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return recursion(0, n - 1, stoneValue, dp);
    }
};