#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // Standard modulo for large combinations
    int MOD = 1e9 + 7; // Note: Usually 1e9 + 7 is used in competitive programming

private:
    // Fixed: Changed dp to pass a 2D vector by reference properly
    long long counter(int i, int j, string &s, vector<vector<long long>> &dp)
    {
        if (i > j)
            return 0;
        if (i == j)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i] == s[j])
        {
            // Fixed: Pass dp into recursive calls
            return dp[i][j] = (1 + counter(i + 1, j, s, dp) + counter(i, j - 1, s, dp)) % MOD;
        }
        else
        {
            // Fixed 1: Changed i-1 to i+1 to properly check the inner overlapping segment
            // Fixed 2: Added + MOD before % MOD to prevent negative results in C++
            return dp[i][j] = (counter(i + 1, j, s, dp) + counter(i, j - 1, s, dp) - counter(i + 1, j - 1, s, dp) + MOD) % MOD;
        }
    }

public:
    int countPalindromes(string s)
    {
        int n = s.length(); // Fixed: Defined n

        // Fixed: Vector type matches the helper function signature
        vector<vector<long long>> dp(n, vector<long long>(n, -1));
        return counter(0, n - 1, s, dp);
    }
};
