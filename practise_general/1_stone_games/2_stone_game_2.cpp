class Solution
{
private:
    // This function ALWAYS returns: "The maximum total stones ALICE can get from index i to the end"
    int recursion(int turn_alice, int i, int M, vector<int> &piles, vector<vector<vector<int>>> &dp)
    {
        int n = piles.size();

        // BASE CASE: No more stones left to pick
        if (i >= n)
        {
            return 0;
        }

        // MEMOIZATION: Return cached result if already calculated
        if (dp[turn_alice][i][M] != -1)
            return dp[turn_alice][i][M];

        int res;
        if (turn_alice)
        {
            res = 0; // Alice wants to MAXIMIZE, so start with a low floor
        }
        else
        {
            res = INT_MAX; // Bob wants to MINIMIZE Alice, so start with a high ceiling
        }

        int total_prefix = 0;

        // Loop through all valid moves: A player can take X piles where 1 <= X <= 2M
        for (int X = 1; X <= 2 * M; X++)
        {

            // If taking X piles goes out of bounds, stop exploring larger X choices
            if ((i + X) > n)
                break;

            // Keep track of the stones picked in the current choice
            total_prefix += piles[i + X - 1];

            if (turn_alice)
            {
                // ALICE'S TURN:
                // 1. She gets the stones picked now (total_prefix).
                // 2. She adds what she will get in the future from the remaining piles.
                // 3. She uses MAX because she wants the highest possible score for herself.
                res = max(res, total_prefix + recursion(0, i + X, max(M, X), piles, dp));
            }
            else
            {
                // BOB'S TURN:
                // 1. Bob takes the stones, so Alice gets 0 stones from this immediate move.
                // 2. We check what Alice gets in the future from the remaining piles.
                // 3. Bob uses MIN because he wants to force Alice into the worst possible future score.
                res = min(res, 0 + recursion(1, i + X, max(M, X), piles, dp));
            }
        }

        // Store the calculated result in our 3D DP table and return it
        return dp[turn_alice][i][M] = res;
    }

public:
    int stoneGameII(vector<int> &piles)
    {
        int n = piles.size();

        // 3D DP Table:
        // Dimension 1: turn_alice (size 2 -> 0 or 1)
        // Dimension 2: current index i (size n)
        // Dimension 3: M value (sized to 2*n + 1 to safely prevent out-of-bounds as M grows)
        vector<vector<vector<int>>> dp(2, vector<vector<int>>(n, vector<int>(2 * n + 1, -1)));

        // Game starts: Alice's turn (1), starting at index 0, with initial M = 1
        return recursion(1, 0, 1, piles, dp);
    }
};
