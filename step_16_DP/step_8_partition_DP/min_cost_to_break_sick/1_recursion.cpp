#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
private:
    int f(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
    {
        // Base case: no cuts left to make
        if (i > j)
            return 0;

        // Return already computed subproblem
        if (dp[i][j] != -1)
            return dp[i][j];

        int mini = INT_MAX;

        for (int ind = i; ind <= j; ind++)
        {
            // Cost is the length of the current segment plus subproblems
            int cost = (cuts[j + 1] - cuts[i - 1]) + f(i, ind - 1, cuts, dp) + f(ind + 1, j, cuts, dp);

            mini = min(mini, cost);
        }

        return dp[i][j] = mini;
    }

public:
    int minCost(int n, vector<int> &cuts)
    {
        // Add boundary markers to easily calculate stick segment lengths
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        // Initialize DP table with -1
        // Valid cut indices range from 1 to m - 2
        vector<vector<int>> dp(m, vector<int>(m, -1));

        // Correct initial boundary call
        return f(1, m - 2, cuts, dp);
    }
};
