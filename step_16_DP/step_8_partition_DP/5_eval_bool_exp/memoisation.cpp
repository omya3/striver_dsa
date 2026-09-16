#include <string>
#include <vector>

using namespace std;

class Solution {
  private:
    // We compute both True and False ways simultaneously to avoid state overlap issues
    pair<int, int> evaluate(int i, int j, string &exp, vector<vector<pair<int, int>>> &dp) {
        // Base case 1: Invalid range
        if (i > j) return {0, 0};

        // Base case 2: Single character (T or F)
        if (i == j) {
            if (exp[i] == 'T') return {1, 0}; // {True ways, False ways}
            else return {0, 1};
        }

        // Return if already computed
        if (dp[i][j].first != -1) return dp[i][j];

        long long totalTrue = 0;
        long long totalFalse = 0;

        // p loops through all operators
        for (int p = i + 1; p <= j - 1; p += 2) {

            pair<int, int> left = evaluate(i, p - 1, exp, dp);
            pair<int, int> right = evaluate(p + 1, j, exp, dp);

            long long lt = left.first;
            long long lf = left.second;
            long long rt = right.first;
            long long rf = right.second;

            if (exp[p] == '&') {
                totalTrue += (lt * rt);
                totalFalse += (lt * rf) + (lf * rt) + (lf * rf);
            }
            else if (exp[p] == '|') {
                totalTrue += (lt * rt) + (lt * rf) + (lf * rt);
                totalFalse += (lf * rf);
            }
            else if (exp[p] == '^') {
                totalTrue += (lt * rf) + (lf * rt);
                totalFalse += (lt * rt) + (lf * rf);
            }
        }

        return dp[i][j] = {totalTrue, totalFalse};
    }

  public:
    int countWays(string &s) {
        int n = s.length();
        // Storing pairs of {True, False} choices to optimize recursion trees
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {-1, -1}));
        return evaluate(0, n - 1, s, dp).first;
    }
};
