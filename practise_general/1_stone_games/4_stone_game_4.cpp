#include <vector>
using namespace std;

class Solution {
private:
    int recursion(int n, vector<int> &dp) {
        // BASE CASE: If 0 stones are left, the current player loses 
        // because they cannot make a valid move (must take >= 1 stone)
        if (n == 0) return 0;

        if (dp[n] != -1) return dp[n];

        // Loop through all valid non-zero square numbers (1, 4, 9, 16...)
        // Start i at 1 so we never take 0 stones (i*i >= 1)
        for (int i = 1; i * i <= n; i++) {
            
            // If the NEXT player loses from the remaining state (returns 0),
            // then the CURRENT player wins (returns 1) by choosing this move.
            if (recursion(n - i * i, dp) == 0) {
                return dp[n] = 1; 
            }
        }

        // If no move leads to a winning position, the current player loses
        return dp[n] = 0;
    }

public:
    bool winnerSquareGame(int n) {
        // Size should be n + 1 to dynamically match the input size up to 10^5
        vector<int> dp(n + 1, -1);

        return recursion(n, dp) == 1;
    }
};
