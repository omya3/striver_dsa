#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    // This function returns the MAXIMUM NET SCORE DIFFERENCE (Alice - Bob) from index i to the end
    int recursion(int turn_alice, int i, vector<int> &stoneValue, vector<vector<int>> &dp)
    {
        int n = stoneValue.size();

        // BASE CASE: No more stones left to pick
        if (i >= n)
        {
            return 0;
        }

        // MEMOIZATION: Return cached result if already calculated
        if (dp[turn_alice][i] != -1)
            return dp[turn_alice][i];

        int res;
        if (turn_alice)
        {
            res = INT_MIN; // Alice wants to MAXIMIZE net score (Alice - Bob)
        }
        else
        {
            res = INT_MAX; // Bob wants to MINIMIZE net score (Alice - Bob)
        }

        int total_prefix = 0;

        // Loop through all valid moves: A player can take X stones where X is 1, 2, or 3
        for (int X = 1; X <= 3; X++)
        {
            // If taking X stones goes out of bounds, stop exploring larger X choices
            if ((i + X) > n)
                break;

            // Keep track of the stones picked in the current choice
            total_prefix += stoneValue[i + X - 1];

            if (turn_alice)
            {
                // ALICE'S TURN:
                // She gains positive points. She wants the maximum overall net score.
                res = max(res, total_prefix + recursion(0, i + X, stoneValue, dp));
            }
            else
            {
                // BOB'S TURN:
                // Bob gains points, which hurts Alice's net score (hence the minus sign).
                // Bob wants to minimize this overall net value.
                res = min(res, -total_prefix + recursion(1, i + X, stoneValue, dp));
            }
        }

        // Store the calculated result in our 2D DP table and return it
        return dp[turn_alice][i] = res;
    }

public:
    string stoneGameIII(vector<int> &stoneValue)
    {
        int n = stoneValue.size();

        // 2D DP Table:
        // Dimension 1: turn_alice (size 2 -> 0 or 1)
        // Dimension 2: current index i (size n)
        vector<vector<int>> dp(2, vector<int>(n, -1));

        // Game starts: Alice's turn (1), starting at index 0
        int net_score = recursion(1, 0, stoneValue, dp);

        // Evaluate the relative net score
        if (net_score > 0)
            return "Alice";
        if (net_score < 0)
            return "Bob";
        return "Tie";
    }
};
