#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;

    long long solve(int i, int j, int state, string &s, vector<vector<vector<int>>> &dp)
    {
        // Base Case 1: If pointers cross, no characters are left to pick
        if (i > j)
            return 0;

        // Base Case 2: If we have matched the 4 outer characters (state == 4),
        // ANY individual character left between i and j can be the middle element.
        if (state == 4)
        {
            return (j - i + 1);
        }

        // Return cached result if already computed
        if (dp[i][j][state] != -1)
            return dp[i][j][state];

        long long ans = 0;

        // Choice 1: Skip the left character
        ans = (ans + solve(i + 1, j, state, s, dp)) % MOD;

        // Choice 2: Skip the right character
        ans = (ans + solve(i, j - 1, state, s, dp)) % MOD;

        // Choice 3: Deduct the overlapping subproblem (both skipped) to fix double-counting
        ans = (ans - solve(i + 1, j - 1, state, s, dp) + MOD) % MOD;

        // Choice 4: Try to match structural pairs if characters are equal
        if (s[i] == s[j])
        {
            if (state == 0)
            {
                // Outer pair matches (1st and 5th char) -> move pointers in and go to state 2
                ans = (ans + solve(i + 1, j - 1, 2, s, dp)) % MOD;
            }
            else if (state == 2)
            {
                // Inner pair matches (2nd and 4th char) -> move pointers in and go to state 4
                ans = (ans + solve(i + 1, j - 1, 4, s, dp)) % MOD;
            }
        }

        return dp[i][j][state] = ans;
    }

public:
    int countPalindromes(string s)
    {
        int n = s.length();
        if (n < 5)
            return 0;

        // 3D vector for Memoization: dp[n][n][5]
        // Since state can only be 0, 2, or 4, size 5 is perfect.
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(5, -1)));

        return solve(0, n - 1, 0, s, dp);
    }
};
